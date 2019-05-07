open React;
open Antd;
open TimePicker;
open Expect_;
open MomentRe;

let expectAmPm = expectEnum([|AmPm.am, AmPm.pm |]);

[@react.component]
let make = () => {
  <>
    <h1 id="timepicker-example"> {string("TimePicker Example")} </h1>

    <TimePicker defaultValue=Js.Null.empty />
    <TimePicker defaultValue=Js.Null.return(momentNow())
    onChange={(m, s) => {
        expectNullMoment(m);
        expectString(s);
      }}
     />
    <TimePicker
      key="tp1"
      clearText="Clear"
      disabledHours={() => [|2, 3|]}
      disabledMinutes={h => {
        expectNullInt(h);
        [|4, 5|];
      }}
      // _open=true
      disabledSeconds={(~selectedHour, ~selectedMinute) => {
        expectNullInt(selectedHour);
        expectNullInt(selectedMinute);
        [|6, 7|];
      }}
      format="HH_mm_ss"
      onAmPmChange={ap => {
        expectAmPm(ap);
      }}
      use12Hours=true
      onChange={(m, s) => {
        expectNullMoment(m);
        expectString(s);
      }}
    />
  </>;
};