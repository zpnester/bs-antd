
open React;
open Antd;
open Popover;

[@react.component]
let make = () => {

    <>
        <h1 id="popover-example">{string("Popover Example")}</h1>

        <Popover content={string("Popover content")} title={string("Title")}>
            <Button _type=`primary>{string("Hover me")}</Button>
        </Popover>
    </>
};