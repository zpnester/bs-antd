open React;
open Antd;
open Expect_;


// let expectOption = (op: element) => {
//   expectToEqual(op->Js.typeof, "object");
//   expectToEqual(op##props##value->Js.typeof, "string");
// };

// let expectMaybeOption = (op: option(Select.Option.element)) => {
//     switch (op) {
//   | None => () // ok
//   | Some(op) => expectOption(op);
//   };
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

let expectValueArray =
    (
      arr:
        array({
          .
          "key": string,
          "label": element,
        }),
    ) => {
  expectToEqual(arr->isArray, true);
  arr->Array.forEach(v => expectValue(v));
};

let expectElementArray = (els: array(element)) => {
  expectToEqual(els->isArray, true);
  els->Array.forEach(e => expectElement(e));
};

[@react.component]
let make = () => {
  let style = ReactDOMRe.Style.make(~width="50%", ());
  let ref1 = useRef(Js.Nullable.undefined);

  let (value1, setValue1) = useState(() => None);
  let value1Str =
    value1->Option.map(x => x##label)->Option.getWithDefault(null);

  <div>
    value1Str
    <br />
    <Select.Default style 
    showSearch=false
    value=value1 onChange={(v, _) => setValue1(_ => v)}>
      <Select.Option value="f"> {string("first")} </Select.Option>
      <Select.Option value="s"> {string("second")} </Select.Option>
    </Select.Default>
    <button
      onClick={_ =>
        switch (ref1->React.Ref.current->Js.Nullable.toOption) {
        | None => ()
        | Some(r) => r->Select.focus
        }
      }>
      {string("focus")}
    </button>
    <button
      onClick={_ =>
        switch (ref1->React.Ref.current->Js.Nullable.toOption) {
        | None => ()
        | Some(r) => r->Select.blur
        }
      }>
      {string("blur")}
    </button>
    <Select.Default
    // disabled=true
      ref=ref1
      style
      placeholder={string("Please select")}
      defaultValue={"key": "2", "label": null}
      onDropdownVisibleChange={v => {
          Js.log2("onDropdownVisibleChange", v);
          expectToEqual(v->Js.typeof, "boolean");
      }}
      
      allowClear=true
      filterOption={(s, opt) => {
          Js.log3("filterOption", s, opt);
          expectElement(opt);
          expectString(s);
          true;
      }}
      dropdownRender={(menu,props) => {
          expectElement(menu);
          // Js.log3("dropdownRender", menu, props);
          menu
      }}
      onChange={(value, option) => {
        Js.log3("on change", value, option);
        expectMaybeValue(value);
        expectMaybeElement(option);
      }}
      onSelect={(value, option) => {
        Js.log3("on select", value, option);
        expectValue(value);
        expectElement(option);
      }}
      onBlur={value => {
        Js.log2("on blur", value);

        expectMaybeValue(value);
      }}
      onFocus={() => Js.log("on focus")}>
      <Select.Option value="1"> {string("Option 1")} </Select.Option>
      <Select.Option value="2" title="Title 2">
        <h2> {string("Option 2")} </h2>
      </Select.Option>
      <Select.Option value="3" disabled=true>
        {string("Option 3")}
      </Select.Option>
    </Select.Default>
    <Select.Multiple
    onSearch={str => {
        Js.log2("onSearch", str);
        expectString(str);

    }}
      autoFocus=true
      style
      placeholder={string("Please select")}
      defaultValue=[|{"key": "2", "label": null}|]
      notFoundContent={Js.Null.return(string("Not found"))}
    //   notFoundContent={Js.Null.empty}
      allowClear=true
       loading=true
      maxTagCount=1
      clearIcon={string("XxX")}
       filterOption={(s, opt) => {
          Js.log3("filterOption", s, opt);
          expectElement(opt);
          expectString(s);
          false;
      }}
      maxTagPlaceholder={omitted => {
        Js.log2("omitted", omitted);
        expectValueArray(omitted);
        string("+" ++ omitted->Js.Array.length->string_of_int);
      }}
      onChange={(value, option) => {
        Js.log3("on change", value, option);
        expectValueArray(value);
        expectElementArray(option);
      }}
      onBlur={value => {
        Js.log2("on blur", value);
        expectValueArray(value);
      }}
      onSelect={(value, option) => {
        Js.log3("on select", value, option);
        expectValue(value);
        expectElement(option);
      }}
      onDeselect={value => {
        Js.log2("on deselect", value);
        expectValue(value);
      }}
      tokenSeparators=[|","|]>
      <Select.Option value="1" title="Title 1">
        {string("Option 1")}
      </Select.Option>
      <Select.Option value="2" title="Title 2">
        {string("Option 2")}
      </Select.Option>
    </Select.Multiple>
    <Select.Tags
      style
      placeholder={string("Please select")}
      defaultValue=[|
        {"key": "3", "label": string("?")},
        {"key": "asd", "label": string("?")},
      |]
      firstActiveValue="2"
      allowClear=true
      maxTagCount=2
      autoClearSearchValue=false
      maxTagPlaceholder={omitted => {
        Js.log2("omitted", omitted);
        expectValueArray(omitted);

        string("+" ++ omitted->Js.Array.length->string_of_int);
      }}
      onPopupScroll={e => Js.log2("onPopupScroll", e)}
      onInputKeyDown={e => Js.log2("onInputKeyDown", e)}
      onMouseEnter={e => Js.log2("onMouseEnter", e)}
      onMouseLeave={e => Js.log2("onMouseLeave", e)}
      onChange={(values, options) => {
        expectValueArray(values);
        expectElementArray(options);

        Js.log3("on change", values, options);
      }}
      onBlur={value => {
        Js.log2("on blur", value);
        expectValueArray(value);
      }}
      onSelect={(value, option) => {
        Js.log3("on select", value, option);
        expectValue(value);
        expectElement(option);
      }}
      onDeselect={value => {
        Js.log2("on deselect", value);
        expectValue(value);
      }}>
      <Select.Option value="1" title="Title 1">
        {string("Option 1")}
      </Select.Option>
      <Select.Option value="2" title="Title 2">
        {string("Option 2")}
      </Select.Option>
      <Select.Option value="3" title="Title 3">
        {string("Option 3")}
      </Select.Option>
      <Select.Option value="4" title="Title 4">
        {string("Option 4")}
      </Select.Option>
      <Select.Option value="5"> {string("Option 6")} </Select.Option>
    </Select.Tags>
  </div>;
};
