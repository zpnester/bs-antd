open React;
open Antd;
open AutoComplete;
open Expect_;

// let expectOptionElement = (o: optionElement('a)) => {
//   expectObject(o);
//   expectMaybeString(o##value)
//   expectMaybeString(o##key)
// };

let expectValue =
    (
      value: {
        .
        "key": string,
        "label": element,
      },
    ) => {
  expectToEqual(value->Js.typeof, "object");
  expectToEqual(value##key->Js.typeof, "string");
  expectElement(value##label);
};

let expectMaybeValue =
    (
      value:
        option({
          .
          "key": string,
          "label": element,
        }),
    ) => {
  switch (value) {
  | None => () // ok
  | Some(value) => expectValue(value)
  };
};

[@react.component]
let make = () => {
  let acRef = useRef(Js.Nullable.undefined);
  let value = {"key": "one", "label": string("Value One!")};

  let dataSource = [|
    string("red"),
    string("darkred"),
    string("blue"),
    string("darkblue"),
    string("lightblue"),
    string("green"),
    <Option key="lg"> {string("lightgreen")} </Option>,
    <OptGroup key="g1" label={string("a group")}>
      <Option key="a"> {string("A")} </Option>
      <Option key="b"> {string("B")} </Option>
    </OptGroup>,
  |];

  let filterOption = (s, opt) => {
    let key = opt##props->Option.keyGet->Belt.Option.getWithDefault("");

    // Js.log3("filterOption", value, opt);
    expectString(s);
    expectReactElement(opt);

    key |> Js.String.indexOf(value##key) >= 0;
  };

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
      labelInValue=LabelInValue.true_
      allowClear=true
      ref=acRef
      backfill=true
      dataSource
      defaultValue=value
      defaultActiveFirstOption=false
      placeholder={<h3> {string("...")} </h3>}
      onChange={v =>
        // Js.log2("onChange", v);
        expectMaybeValue(v)}
      onBlur={v =>
        // Js.log2("onBlur", v);
        expectMaybeValue(v)}
      onSearch={s =>
        // Js.log2("onSearch", s);
        expectString(s)}
      onSelect={(v, e) => {
        // Js.log3("onSelect", v, e);
        expectValue(v);
        expectReactElement(e);
      }}
    />
    <br />
    <AutoComplete
      allowClear=true
      labelInValue=LabelInValue.true_
      ref=acRef
      backfill=true
      dataSource
      filterOption
      defaultValue=value
      defaultActiveFirstOption=false
      onChange={v =>
        // Js.log2("onChange", v);
        expectMaybeValue(v)}
      onBlur={v =>
        // Js.log2("onBlur", v);
        expectMaybeValue(v)}
      onSearch={s =>
        // Js.log2("onSearch", s);
        expectString(s)}
      onSelect={(s, e) => {
        // Js.log3("onSelect", s, e);
        expectValue(s);
        expectReactElement(e);
      }}>
      <Input.TextArea
        placeholder="input here"
        className="custom"
        style={ReactDOMRe.Style.make(~height="50", ())}
        onKeyPress={e => Js.log2("onKeyPress", e)}
        onPressEnter={e => Js.log2("onPressEnter", e)}
      />
    </AutoComplete>
  </>;
};