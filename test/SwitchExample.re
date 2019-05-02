
open React;
open Antd;
open Switch;
open Expect_;


[@react.component]
let make = () => {

    <>
        <h1 id="switch-example">{string("Switch Example")}</h1>
        
         <Switch checkedChildren=string("1") unCheckedChildren=string("0") 
         onChange={(v, e) => {
             Js.log3("onChange", v, e);
             expectBool(v);
         }}
         />
    </>
};


