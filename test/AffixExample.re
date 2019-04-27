open React;
open Antd;
open Expect_;
open Belt;

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

let getDocumentBody: unit => Dom.htmlElement = [%raw
  {|
function(unit) {
  return document.body
}
|}
];

[@react.component]
let make = () => {
  // let affixRef = useRef(Js.Nullable.undefined);

  // let style = ReactDOMRe.Style.make(~height="300px", ~overflow="scroll", ());

  let content = [||];
  for (i in 0 to 50) {
    content
    |> Js.Array.push(
         <span key={"t" ++ i->string_of_int}>
           {string("text #" ++ i->string_of_int)}
         </span>,
       )
    |> ignore;
    content |> Js.Array.push(<br key={"b" ++ i->string_of_int} />) |> ignore;
  };

  <div >
    <h1 id="affix-example">{string("Affix Example")}</h1>
    // ref=affixRef
    <Affix
      offsetTop=150.0
      offsetBottom=50.0
      className="myaffixclassname"
      // target={getDocumentBody}
      onChange={a => {
        Js.log2("affix changed", a);
        expectToEqual(a->Js.typeof, "boolean");
      }}>
       <WithHooks /> </Affix>
      // <button
      //   onClick={_ => {
      //     // Js.log(affixRef->Ref.current);
      //     // expectToEqual(
      //     //   affixRef->Ref.current->Js.Nullable.toOption->Option.getExn##props
      //     //   ->Js.typeof,
      //     //   "object",
      //     // );
      //   }}>
      //   {string("affix")}
      // </button>
    // {array(content)}
  </div>;
};
