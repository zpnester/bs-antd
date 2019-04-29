

open Antd;
open Collapse;
open React;
open Expect_;

[@react.component]
let make = () => {

    let (keys, setKeys) = useState(() => [|"0"|]);
    let (key, setKey) = useState(() => Some("1"));
    <>
        <h1 id="collapse-example">{string("Collapse Example")}</h1>

        <Collapse 
        activeKey=keys  
        // defaultActiveKey=[|"1"|]
        onChange={value => {
            Js.log2("onChange", value);
            expectStringArray(value);
            setKeys(_ => value);
        }}>
            <Collapse.Panel header=string("First")>
                {string("Panel 1")}
            </Collapse.Panel>

            <Collapse.Panel header=string("Second")>
                {string("Panel 2")}
            </Collapse.Panel>

        </Collapse>

        <h2>{string("Accordion")}</h2>
        <Collapse.Accordion
        activeKey=key
        // defaultActiveKey=[|"1"|]
        onChange={value => {
            Js.log2("onChange", value);
            expectMaybeString(value);
            setKey(_ => value);
        }}>
            <Collapse.Panel header=string("First")>
                {string("Panel 1")}
            </Collapse.Panel>

            <Collapse.Panel header=string("Second")>
                {string("Panel 2")}
            </Collapse.Panel>

        </Collapse.Accordion>
    </>
};