open React;
open Antd;
open Expect_;
open Belt;
open Helpers;

module WithHooks = {
  [@react.component]
  let make = () => {
    let (c, setC) = useState(() => 0);

    <button onClick={_ => setC(c => c + 1)}>
      {string(c->string_of_int)}
    </button>;
  };
};

[@bs.val] [@bs.return nullable]
external window: option(Dom.window) = "window";

external asHtmlElementUnsafe: Dom.element => Dom.htmlElement = "%identity";



[@react.component]
let make = () => {
 
  <>
    <h1 id="affix-example"> {string("Affix Example")} </h1>
    <Affix
      offsetTop=150.0
      // offsetBottom=50.0
      className="myaffixclassname"
      target={getDocumentBody}
      onChange={a => {
        // Js.log2("affix changed", a);
        expectToEqual(a->Js.typeof, "boolean");
      }}>
      <WithHooks />
    </Affix>
  </>
  
};
