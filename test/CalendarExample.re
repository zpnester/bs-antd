 open React;
open Antd;
open Calendar;
open MomentRe;
open Expect_;

let expectMode = expectEnum([|Mode.month, Mode.year|]);

[@react.component]
let make = () => {

  let (value, setValue) = useState(() => momentNow());

  <>
    <h1 id="calendar-example"> {string("Calendar Example")} </h1>
    <p>
    {string(value |> Moment.defaultFormat)}
    </p>
    <button onClick={_ => {
      setValue(_ => momentNow() |> Moment.setYear(1995));
    }}>{string("Change")}</button>
    <Calendar
      onChange={m => {
        expectMoment(m);
        setValue(_ => m);
        }}
      onPanelChange={(m, mode) =>{
        expectMode(mode);
        expectMoment(m);
        }}

        disabledDate={m => {
          expectMoment(m);
          m |> Moment.get(`day) == 5
        }}
        // monthCellRender={m => {
        //   expectMoment(m);
        //   string("m")
        // }}
      // dateFullCellRender={m => {

      //   expectMoment(m);
      //     string(m |> Moment.format("(MMM Do YY)"))
      // }}
      // dateCellRender={m => {
      //     expectMoment(m);
      //     string(m |> Moment.format("MMM Do YY"))
      // }}
      value
      // validRange=(
      //   momentNow(),
      //   momentNow() |> Moment.add(~duration=duration(5.0, `days)),
      // )
    />
  </>;
};