open React;
open Antd;
open AutoComplete;
open Expect_;

[@react.component]
let make = () => {
  let acRef = useRef(Js.Nullable.undefined);
  let value = "one";

  let dataSource = [|
    string("red"),
    string("darkred"),
    string("blue"),
    string("darkblue"),
    string("lightblue"),
    string("green"),
    <Option key="lg"> {string("lightgreen")} </Option>,
    <OptGroup key="g1" label=string("a group")>   
        <Option key="a"> {string("A")} </Option>
        <Option key="b"> {string("B")} </Option>

    </OptGroup>
  |];

  let filterOption = (value, opt) => {
    Js.log3("filterOption", value, opt);
    expectString(value);
    expectElement(opt);
    true;
  };

  <>
    <h1> {string("AutoComplete Example")} </h1>
    <button
      onClick={_ =>
        switch (acRef->React.Ref.current->Js.Nullable.toOption) {
        | None => ()
        | Some(ac) => ac->focus
        }
      }>
      {string("focus")}
    </button>
    <AutoComplete
    allowClear=true
      ref=acRef
      backfill=true
      dataSource
      filterOption
      defaultValue=value
      defaultActiveFirstOption=false
      placeholder={<h3>{string("...")}</h3>}
      onChange={v => {
          Js.log2("onChange", v);
          expectMaybeString(v);
      }}    
      onBlur={v => {
          Js.log2("onBlur", v);
          expectMaybeString(v);
      
      }}
      onSearch={s => {
          Js.log2("onSearch", s);
          expectString(s);
      }}
      onSelect={(s, e) => {
          Js.log3("onSelect", s, e);
          expectString(s);
          expectElement(e);
      }}
    />
  </>;
};
