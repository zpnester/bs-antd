
open React;
open Antd;
open Input;
open Expect_;

[@react.component]
let make = () => {
   
   <>
    <h1 id="input-example">{string("Input Example")}</h1>
    <Input addonBefore={string("http://")} addonAfter={string(".com")} defaultValue="mysite" />
    
    <Input.Search enterButton={Search.EnterButton.element(string("Do Search"))} 
    onSearch={(s, e) => {
        expectString(s);
        Js.log("on search " ++ s);  
    }}/>
    <Input.Password />
    </>
};