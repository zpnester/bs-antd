open Antd;
open React;
open Cascader;
open Expect_;

let expectCascaderOption = (opt: cascaderOption) => {
  expectToEqual(opt->Js.typeof, "object");
  expectToEqual(opt##label->Js.typeof, "string");
  expectElement(opt##label);
  expectToEqual(opt##disabled->Js.typeof, "boolean");
  expectToEqual(opt##children->isArray, true);
};

let expectCascaderOptionArray = (arr: array(cascaderOption)) => {
  expectArray(arr);
  arr->Array.forEach(expectCascaderOption);
};

let expectFilledFieldNames = (x: ShowSearch.filledFieldNames) => {
    expectObject(x);
    expectString(x##value);
    expectString(x##label);
    expectString(x##children);
};


[@react.component]
let make = () => {
  let options = [|
    {
      "value": "zhejiang",
      "label": string("Zhejiang"),
      "disabled": false,
      "children": [|
        {
          "value": "hangzhou",
          "label": string("Hangzhou"),
          "disabled": false,
          "children": [|
            {
              "value": "xihu",
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

      "children": [|
        {
          "value": "nanjing",
          "label": string("Nanjing"),
          "disabled": false,
          "children": [|
            {
              "value": "zhonghuamen",
              "label": string("Zhong Hua Men"),
              "disabled": false,

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
      size=Size.large
      popupPlacement=PopupPlacement.topRight
      expandTrigger=ExpandTrigger.hover
      displayRender={(label, opts) => {
        Js.log3("displayRender", label, opts);
        expectStringArray(label);
        expectCascaderOptionArray(opts);
        string(label |> Js.Array.joinWith("/"));
      }}
      onChange={(value, selectedOpts) => {
        Js.log3("onChange", value, selectedOpts);
        expectStringArray(value);
        expectCascaderOptionArray(selectedOpts);
      }}
      showSearch={ShowSearch.object_(~limit=ShowSearch.Limit.false_, 
        ~filter={(inputValue, path, names) => {
            Js.log4("filter", inputValue, path, names);
            expectString(inputValue);
            expectCascaderOptionArray(path);
            expectFilledFieldNames(names);
            true
        }},
        ~render={(inputValue, path, prefixCls, names) => {
                Js.log("render");
            Js.log4(inputValue, path, prefixCls, names);

            expectString(inputValue);
            expectCascaderOptionArray(path);
            expectFilledFieldNames(names);

            // just a test, it breaks search ui
            path->Array.getExn(0)##label;
        }},
        ~sort={(a, b, inputValue, names) => {
            Js.log("sort");
            Js.log4(a, b, inputValue, names);
            expectCascaderOptionArray(a);
            expectCascaderOptionArray(b);
            expectString(inputValue);
            expectFilledFieldNames(names);
            1.0
        }},
        ~matchInputWidth=false,
      ())

      }
    />
  </>;
};
