open Antd;
open DatePicker;
open React;
open Expect_;
open MomentRe;

let expectPartial = (p: RangePicker.Partial.t) => {
  expectToEqual(
    p == RangePicker.Partial.start || p == RangePicker.Partial.end_,
    true,
  );
};

let expectRangeDisableTimeCurrent = (x: RangePicker.rangeDisableTimeCurrent) => {
  // // Js.log("expect rangeDisableTimeCurrent not implemented");
};

[@react.component]
let make = () => {
  let (date, setDate) = useState(() => (Js.Null.empty, ""));

  <>
    <h1 id="datepicker-example"> {string("DatePicker Example")} </h1>
    {string("date: " ++ snd(date))}
    <button onClick={_ => setDate(_ => (Js.Null.empty, ""))}>
      {string("Reset date")}
    </button>
    <DatePicker
      format=[|"YYYY MMMM DD", "YYYY-MM-DD"|]
      value={fst(date)}
      onChange={(m, s) => {
        // // Js.log3("onChange", m, s);
        expectNullMoment(m);
        expectString(s);
        setDate(_ => (m, s));
      }}
      onOk={m =>
        // // Js.log2("onOk", m);
        expectMoment(m)}
      showTime={ShowTime.bool(true)}
      onPanelChange={(m, mode) => {
        // // Js.log3("onPanelChange", m, mode);
        expectStringAny(mode);
        expectMoment(m);
      }}
      disabledTime={m => {
        // // Js.log2("disabledTime", m);
        expectMomentOption(m);
        {
          "disabledHours": Some(() => [|1|]),
          "disabledMinutes": Some(() => [|2|]),
          "disabledSeconds": Some(() => [|3|]),
        };
      }}
      disabledDate={m => {
        // // Js.log2("disabledDate", m);
        expectMoment(m);
        false;
      }}
      dateRender={(~current, ~today) => {
        // // Js.log3("dateRender", current, today);
        expectMoment(current);
        expectMoment(today);
        string(
          current
          |> MomentRe.Moment.locale("ru")
          |> MomentRe.Moment.format("MMMM DD"),
        );
      }}
      renderExtraFooter={mode => {
        // // Js.log2("renderExtraFooter", mode);
        expectStringAny(mode);
        string("extra footer");
      }}
    />
    <h2> {string("MonthPicker")} </h2>
    <DatePicker.MonthPicker
      allowClear=true
      monthCellContentRender={(m, l) => {
        // // Js.log3("monthCellContentRender", m, l);
        expectMoment(m);
        expectLocale(l);
        string(m |> MomentRe.Moment.format("MMMM"));
      }}
      onChange={(m, s) => {
        // // Js.log3("onChange", m, s);
        expectNullMoment(m);
        expectString(s);
      }}
      onPanelChange={(m, mode) => {
        // // Js.log3("onPanelChange", m, mode);
        expectStringAny(mode);
        expectMoment(m);
        failwith("CANNOT BE REMOVED FROM MONTH");
      }}
      disabledDate={m => {
        // // Js.log2("disabledDate", m);
        expectMoment(m);
        false;
      }}
      dateRender={(~current, ~today) => {
        // // Js.log3("dateRender", current, today);
        failwith("CANNOT BE REMOVED FROM MONTH");
        expectMoment(current);
        expectMoment(today);
        string(current |> MomentRe.Moment.format("MMMM1"));
      }}
      renderExtraFooter={() =>
        // // Js.log("renderExtraFooter");
        string("extra footer")}
    />
    <h2> {string("WeekPicker")} </h2>
    <DatePicker.WeekPicker
      renderExtraFooter={mode => {
        // // Js.log2("renderExtraFooter", mode);
        expectStringAny(mode);
        string("extra footer");
      }}
      onChange={(m, s) => {
        // // Js.log3("onChange", m, s);
        expectNullMoment(m);
        expectString(s);
      }}
      dateRender={current => {
        // // Js.log2("dateRender", current);
        expectMoment(current);
        string(current |> MomentRe.Moment.format("DD"));
      }}
      onPanelChange={(m, mode) => {
        // // Js.log3("onPanelChange", m, mode);
        expectStringAny(mode);
        expectMoment(m);
        failwith("CANNOT BE REMOVED FROM WEEK");
      }}
    />
    <h2> {string("RangePicker")} </h2>
    <DatePicker.RangePicker
      ranges={Js.Dict.fromList([
        (
          "A",
          () => (
            Js.Null.return(
              momentNow() |> Moment.subtract(~duration=duration(5.0, `days)),
            ),
            Js.Null.return(
              momentNow() |> Moment.add(~duration=duration(1.0, `days)),
            ),
          ),
        ),
        (
          "B",
          () => (
            Js.Null.return(
              momentNow() |> Moment.subtract(~duration=duration(5.0, `days)),
            ),
            Js.Null.empty,
          ),
        ),
        ("C", () => (Js.Null.empty, Js.Null.empty)),
      ])}
      disabledTime={(a, p) => {
        // // Js.log3("disabledTime", a, p);
        expectPartial(p);
        expectRangeDisableTimeCurrent(a);
        {
          "disabledHours": Some(() => [|1|]),
          "disabledMinutes": Some(() => [|2|]),
          "disabledSeconds": Some(() => [|3|]),
        };
      }}
      onCalendarChange={m =>
        // // Js.log2("onCalendarChange", m);
        expectNullMomentArray(m)}
      onChange={(m, s) => {
        // // Js.log3("onChange", m, s);
        expectStringTuple2(s);
        expectNullMomentArray(m);
      }}
      onOk={m =>
        // // Js.log2("onOk", m);
        expectNullMomentArray(m)}
      showTime={ShowTime.bool(true)}
    />
  </>;
};