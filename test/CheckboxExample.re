open Antd;
open Checkbox;
open React;

open Expect_;

[@react.component]
let make = () => {

    let (c, setC) = useState(() => false);
    let (g, setG) = useState(() => [|"2"|]);

    let options = [|
            {
                "label": string("Option 1"),
                "value": "1",
                "disabled": false,
                "onChange": Some(e => {
                    Js.log2("option 1 change", e);
                })
            },
            {
                "label": string("Option 2"),
                "value": "2",
                "disabled": false,
                "onChange": None
            }
        |];

    <>
        <h1 id="checkbox-example">{string("Checkbox Example")}</h1>

        <Checkbox checked=c onChange={e => {
            // Js.log2("onChange", e);
            setC(_ => e##target##checked)  
        }}/>
        <br />

        {string("group: " ++ (g|>Js.Array.joinWith(",")))}
        <br />
        <Checkbox.Group options  onChange={os => {
            // Js.log2("group change", os);  
            expectStringArray(os);
            setG(_ => os);
        }}/>
    </>
};