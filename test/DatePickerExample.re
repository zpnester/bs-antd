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

let expectMode = expectEnum([|Mode.time, Mode.date, Mode.month, Mode.year|]);

let expectNullMode = expectNullOf(expectMode);

let expectModeArray = expectArrayOf(expectMode);

let expectNullModeArray = expectArrayOf(expectNullMode);



let expectRangeMode = expectEnum([|
  RangePicker.Mode.decade,
  RangePicker.Mode.month,
  RangePicker.Mode.year,
  RangePicker.Mode.date,
|]);

let expectNullRangeMode = expectNullOf(expectRangeMode);
let expectNullRangeModeArray = expectArrayOf(expectNullRangeMode);

[@react.component]
let make = () => {
  let (date, setDate) = useState(() => (Js.Null.empty, ""));


  //// RANGE
  let (mode, setMode) = useState(() => RangePicker.Mode.month);
  let range = 
  <>
  <button onClick={_ => {
    setMode(_ => RangePicker.Mode.year);
  }}>{string("year")}</button>
  <button onClick={_ => {
    setMode(_ => RangePicker.Mode.decade);
  }}>{string("decade")}</button>
  <button onClick={_ => {
    setMode(_ => RangePicker.Mode.date);
  }}>{string("date")}</button>
    <DatePicker.RangePicker
    // mode=(mode, "year")
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
      onPanelChange={(m, mode) => {
        expectNullMomentArray(m);
        expectNullRangeModeArray(mode);
      }}
      renderExtraFooter={x => {
        string("EXTRA FOOTER"); 
      }}
      disabledTime={(a, p) => {
        expectPartial(p);
        {
          "disabledHours": Some(() => [|1|]),
          "disabledMinutes": Some(() => [|2|]),
          "disabledSeconds": Some(() => [|3|]),
        };
      }}
      onCalendarChange={m => {
        expectMomentArray(m)
      }}
      onChange={(m, s) => {
        expectStringTuple2(s);
        expectNullMomentArray(m);
      }}
      onOk={m => {
        expectNullMomentArray(m)
      }}
      placeholder=("SELECT LEFT" , "SELECT RIGHT")

      // showTime={ShowTime.bool(true)}
      showTime={ShowTime.timePickerProps(TimePicker.makeProps(
        ~size=TimePicker.Size.small,
        // ~use12Hours=true,
        ()
      ))}
      // dateRender={(~current, ~today) => {
      //   expectMoment(current);
      //   expectMoment(today);
      //   string(
      //     current
      //     |> MomentRe.Moment.locale("ru")
      //     |> MomentRe.Moment.format("MMMM DD"),
      //   );
      // }}
    />
  </>;

  <>
    <h1 id="datepicker-example"> {string("DatePicker Example")} </h1>
    {string("date: " ++ snd(date))}
    <button onClick={_ => setDate(_ => (Js.Null.empty, ""))}>
      {string("Reset date")}
    </button>
    <DatePicker
      renderExtraFooter={mode => {
        expectMode(mode);
        string("EXTRA FOOTER"); 
      }}
      format=[|"YYYY MMMM DD", "YYYY-MM-DD"|]
      value={fst(date)}
      onChange={(m, s) => {
        expectNullMoment(m);
        expectString(s);
        setDate(_ => (m, s));
      }}
      onOk={m => {
        expectMoment(m)
      }}
      // showTime={ShowTime.bool(true)}
      showTime={ShowTime.timePickerProps(TimePicker.makeProps(
        ~size=TimePicker.Size.small,
        ~use12Hours=true,
        ()
      ))}
      onPanelChange={(m, mode) => {
        expectNullMode(mode);
        expectNullMoment(m);
      }}
      // mode="year"
      disabledTime={m => {
        expectNullMoment(m);
        {
          "disabledHours": Some(() => [|1|]),
          "disabledMinutes": Some(() => [|2|]),
          "disabledSeconds": Some(() => [|3|]),
        };
      }}
      disabledDate={m => {
        expectMoment(m);
        false;
      }}

      // dateRender={(~current, ~today) => {
      //   expectMoment(current);
      //   expectMoment(today);
      //   string(
      //     current
      //     |> MomentRe.Moment.locale("ru")
      //     |> MomentRe.Moment.format("MMMM DD"),
      //   );
      // }}
    />
    <h2> {string("MonthPicker")} </h2>
    <DatePicker.MonthPicker
      renderExtraFooter={() => {
        string("EXTRA FOOTER"); 
      }}
      autoFocus=true
      allowClear=true
      placeholder="*SELECT MONTH*"
      monthCellContentRender={(m, l) => {
        expectMoment(m);
        string(m |> MomentRe.Moment.format("MMMM"));
      }}
      onChange={(m, s) => {
        expectNullMoment(m);
        expectString(s);
      }}
      disabledDate={m => {
        expectMoment(m);
        false;
      }}
    />

    <h2> {string("WeekPicker")} </h2>
    <DatePicker.WeekPicker
      renderExtraFooter={mode => {
        expectMode(mode);
        string("EXTRA FOOTER"); 
      }}
      onChange={(m, s) => {
        expectNullMoment(m);
        expectString(s);
      }}
      dateRender={current => {
        expectMoment(current);
        string(current |> MomentRe.Moment.format("DD"));
      }}
    />
    <h2> {string("RangePicker")} </h2>
    range
  </>;
};