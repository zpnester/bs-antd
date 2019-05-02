open React;
open Antd;
open Tooltip;
open Expect_;


[@react.component]
let make = () => {

    <>
        <h1 id="tooltip-example">{string("Tooltip Example")}</h1>
        
        <Tooltip title={() => string("prompt text")}>
            <span>{string("Tooltip will show on mouse enter.")}</span>
        </Tooltip>
    </>
}; 