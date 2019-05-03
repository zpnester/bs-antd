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
    let  key = opt##key->Belt.Option.getWithDefault("");

    Js.log3("filterOption", value, opt);
    expectString(value);
    expectElementAny(opt);
    
    key |> Js.String.indexOf(value) >= 0
  };

  let a = ReactDOMRe.props(~ariaLabel="322", ());
  let x = a->ReactDOMRe.ariaRoledescription;
  Js.log2("___________________________", x);

  <> 
    <h1 id="autocomplete-example"> {string("AutoComplete Example")} </h1>
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
  

  <br />
  {string("------------")}
  <AutoComplete
      allowClear=true
      ref=acRef
      backfill=true
      dataSource
      filterOption
      defaultValue=value
      defaultActiveFirstOption=false
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
    >
     <Input.TextArea
          placeholder="input here"
          className="custom"
          style=ReactDOMRe.Style.make(~height="50", ())
          onKeyPress={e => {
            Js.log2("onKeyPress", e);
          }}
          onPressEnter={e => {
            Js.log2("onPressEnter", e);
          }}
        />
    </AutoComplete>


  </>;
};
