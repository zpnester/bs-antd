open Antd;
open React;
open Cascader;
open Expect_;

type customOption = {
  .
  "value": string,
  "label": element,
  "disabled": bool,
  "children": array(customOption),
  "custom": int
};

let expectCascaderOption = (opt: customOption) => {
  expectToEqual(opt->Js.typeof, "object");
  expectToEqual(opt##label->Js.typeof, "string");
  expectElement(opt##label);
  expectToEqual(opt##disabled->Js.typeof, "boolean");
  expectToEqual(opt##children->isArray, true);
  expectInt(opt##custom);
};

let expectCascaderOptionArray = expectArrayOf(expectCascaderOption);

let expectFieledFieldNames = (x: ShowSearch.filledFieldNames) => {
  expectObject(x);
  expectString(x##value);
  expectString(x##label);
  expectString(x##children);
};

[@react.component]
let make = () => {
  let options: array(customOption) = [|
    {
      "value": "zhejiang",
      "label": string("Zhejiang"),
      "disabled": false,
      "custom": 1,
      "children": [|
        {
          "value": "hangzhou",
          "label": string("Hangzhou"),
          "disabled": false,
          "custom": 1,
          "children": [|
            {
              "value": "xihu",
              "custom": 1,
              "label": string("West Lake"),
              "disabled": false,
              "children": [||],
            },
          |],
        },
      |],
    },
    {
      "value": "jiangsu",
      "label": string("Jiangsu"),
      "disabled": false,
      "custom": 1,
      "children": [|
        {
          "value": "nanjing",
          "label": string("Nanjing"),
          "disabled": false,
          "custom": 1,
          "children": [|
            {
              "value": "zhonghuamen",
              "label": string("Zhong Hua Men"),
              "disabled": false,
              "custom": 1,
              "children": [||],
            },
          |],
        },
      |],
    },
  |];

  <>
    <h1 id="cascader-example"> {string("Cascader Example")} </h1>
    <Cascader
      options
      size=`large
      popupPlacement=`topRight
      expandTrigger=`hover
      displayRender={(label, opts) => {
        expectStringArray(label);
        expectCascaderOptionArray(opts);
        string(label |> Js.Array.joinWith("/"));
      }}
      onChange={(value, selectedOpts) => {
        expectStringArray(value);
        expectCascaderOptionArray(selectedOpts);
      }}
      showSearch={ShowSearch.make(
        ~limit=Limit.false_,
        ~filter=
          (inputValue, path, names) => {
            expectString(inputValue);
            expectCascaderOptionArray(path);
            expectFieledFieldNames(names);
            true;
          },
        ~render=
          (inputValue, path, prefixCls, names) => {
            expectString(inputValue);
            expectCascaderOptionArray(path);
            expectFieledFieldNames(names);

            // just a test, it breaks search ui
            path->Array.getExn(0)##label;
          },
        ~sort=
          (a, b, inputValue, names) => {
            expectCascaderOptionArray(a);
            expectCascaderOptionArray(b);
            expectString(inputValue);
            expectFieledFieldNames(names);
            1.0;
          },
        ~matchInputWidth=false,
        (),
      )}
    />
  </>;
};