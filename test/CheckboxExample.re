open Antd;
open Checkbox;
open React;

open Expect_;

let expectCheckboxChangeEvent = e => {
  expectBool(e##target##checked);
  expectDomMouseEvent(e##nativeEvent);
  expectString(e##target##value);
  expectMaybeString(e##target##name);
};

[@react.component]
let make = () => {
  let (c, setC) = useState(() => false);
  let (g, setG) = useState(() => [|"2"|]);

  let options = [|
    {
      "label": string("Option 1"),
      "value": "1",
      "disabled": false,
      "onChange": Some(e => Js.log2("option 1 change", e)),
    },
    {
      "label": string("Option 2"),
      "value": "2",
      "disabled": false,
      "onChange": None,
    },
  |];

  <>
    <h1 id="checkbox-example"> {string("Checkbox Example")} </h1>
    <Checkbox
      value="c1"
      checked=c
      indeterminate=false
      autoFocus=true
      onClick={e => {
        expectReactMouseEvent(e);
      }}
      onChange={e => {
        expectCheckboxChangeEvent(e);
        setC(_ => e##target##checked)
      }}
    />
    <h2>{string("Group")}</h2>
    <Checkbox.Group onChange={ss => {
      expectStringArray(ss);
    }}
    
    >
      <Checkbox value="a"
      onChange={e => {
        expectCheckboxChangeEvent(e);
      }}
      />
      <Checkbox value="b" 
      onChange={e => {
        expectCheckboxChangeEvent(e);
      }}/>
    </Checkbox.Group>
    
    <br />

    <h2>{string("Group with options")}</h2>
    {string("group: " ++ (g |> Js.Array.joinWith(",")))}
    <br />

    <Checkbox.Group
      options
      onChange={os => {
        expectStringArray(os);
        setG(_ => os);
      }}
    />

    <h2>{string("Group with default value")}</h2>

    <Checkbox.Group options defaultValue=[|"2"|] />
  </>;
};