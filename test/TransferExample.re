open React;
open Antd;
open Transfer;
open Expect_;


[@react.component]
let make = () => {

    let dataSource = [|
        {
            "key": "a",
            "title": "Item 1",
            "description": Some("This is item 1"),
            "disabled": false,
            "customField": "hello"
        }
    |];

    <>
        <h1 id="transfer-example">{string("Transfer Example")}</h1>
        

        <Transfer dataSource 
        render={item => string(item##customField)}
        />
    </>
};