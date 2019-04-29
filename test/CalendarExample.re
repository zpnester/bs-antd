
open React;
open Antd;
open Calendar;
open MomentRe;

[@react.component]
let make = () => {

    <>
        <h1 id="calendar-example">{string("Calendar Example")}</h1>

        <Calendar 
        onChange={m => {
            Js.log2("onChange", m);
        }}
        onPanelChange={(m, mode) => {
            Js.log3("onPanelChange", m, mode);
        }}
        // dateFullCellRender={m => {
        //     string(m |> Moment.format("(MMM Do YY)"))
        // }}
        // dateCellRender={m => {
        //     string(m |> Moment.format("MMM Do YY"))  
        // }}
        // value=Js.Null.empty
        validRange=(momentNow(), momentNow() |> Moment.add(~duration=duration(5.0, `days)))
        disabledDate={m => {
            m |> Moment.date == 5
        }}
        />
    </>
};

