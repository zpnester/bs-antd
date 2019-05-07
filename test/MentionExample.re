open React;
open Antd;
open Mention;
open Expect_;



let expectNullContentState: Js.null(ContentState.t) => unit = [%raw {|
function(x) {
  if (typeof(x) != "object" || (x && typeof(x.blockMap) != "object")) {
    throw "not content state";
  }
}
|}];

let expectContentState: ContentState.t => unit = [%raw {|
function(x) {
  if (x == null || typeof(x) != "object" || (x && typeof(x.blockMap) != "object")) {
    throw "not content state";
  }
}
|}];

type window;
let window: option(window) = [%external window];

type data = {
  a: string,
  b: int
};

let expectData = d => {
  expectString(d.a);
  expectInt(d.b);
};

module Mention2 = Mention.Make({
  type nonrec data = data;
});

[@react.component]
let make = () => {
  
  let defaultSuggestions = [|
    "afc163",
    "benjycui",
    "yiminghe",
    "RaoHai",
    {js|中文|js}, 
    {js|にほんご|js},
  |];

  let defaultSuggestions = defaultSuggestions->Array.map(s => Suggestion.make(
    ~value=s,
    ~children=<h1>{string(s)}</h1> 
  ));

  let (value, setValue) = useState(() => ContentState.fromString("hello"));
  
  let m = switch (window) {
      | None => null
      | Some(_) =>
        <>
        <Mention
          prefix=[|"@", "$"|]
          style={ReactDOMRe.Style.make(~width="100%", ())}
          // value
          onChange={value => {
            expectContentState(value);
            setValue(_ => value)
          }}
          defaultValue={value}
          suggestions=defaultSuggestions
          // defaultSuggestions
          // loading=true
          // multiLines=true
          key="a"
          onSearchChange={(~value, ~trigger) => {
            expectString(value);
            expectString(trigger);
          }}
          notFoundContent={<h1>{string("NOT FOUND")}</h1>}
          onSelect={(suggestion) => {
            expectString(suggestion)
          }}
        />

        <Mention2
            notFoundContent={<h1>{string("not found")}</h1>}
            onSelect={(s, data) => {
              [%debugger]
              expectString(s);
              expectData(data);
            }}
            defaultSuggestions=[|
              Mention2.Suggestion.make(~value="inserted value", ~children=string("Some value"), ~data={
                a: "a", b: 1
              })
            |]
            >
        </Mention2>

        </>
    };


  <>
    <h1 id="mention-example"> {string("Mention Example")} </h1>
    <h1> {string("SSR does not work")} </h1>
    <h1> {string("controlled (setting value) does not work")} </h1>
    <button onClick={_ => {
      let ms = value->ContentState.getMentions;
      let str = ms |> Js.Array.joinWith(", ");
      
      Message.info(string(str)) |> ignore;
    }}>
      {string("get mentions")}
    </button>

    m
    
  </>;
};