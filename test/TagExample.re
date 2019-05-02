open React;
open Antd;
open Tag;
open Expect_;


[@react.component]
let make = () => {

    <>
        <h1 id="tag-example">{string("Tag Example")}</h1>
        
       <Tag>{string("Tag 1")}</Tag>
        <Tag><a href="https://github.com/ant-design/ant-design/issues/1862">{string("Link")}</a></Tag>
        <Tag closable=true onClose={_ => {
            Js.log("onClose");
        }}>{string("Tag 2")}</Tag>
        <Tag closable=true onClose={e => {
            Js.log2("onClose prevent", e)
            e->ReactEvent.Mouse.preventDefault;
        }}>{string("Prevent Default")}</Tag>
    </>
};