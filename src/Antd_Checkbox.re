open React;

type t;

[@bs.send] external blur: t => unit = "blur";
[@bs.send] external focus: t => unit = "focus";


type changeEvent = {
    .
    "target": {
        .
        "checked": bool
    },
    [@bs.meth] "stopPropagation": unit => unit,
    [@bs.meth] "preventDefault": unit => unit,
    [@bs.meth] "nativeEvent": Dom.mouseEvent => unit,

};

[@react.component] [@bs.module]
external make: (
    ~ref: Ref.t(Js.nullable(t))=?,
    ~autoFocus: bool=?,
    ~checked: bool=?,
    ~defaultChecked: bool=?,
    ~disabled: bool=?,
    ~indeterminate: bool=?,
    ~onChange: changeEvent => unit=?,
    ~children: element=?,
    unit
) => element = "antd/lib/checkbox";

module Group = {


    type checkboxOption = {
        .
        "label": element,
        "value": string,
        "disabled": bool,
        "onChange": option(changeEvent => unit)
    };

    [@react.component] [@bs.module]
external make: (
    ~defaultValue: array(string)=?,
    ~disabled: bool=?,
    ~name: string=?,
    ~options: array(checkboxOption)=?,
    ~value: array(string)=?,
    // actually array of ```string | number | boolean``` but should be safe
    ~onChange: array(string) => unit=?,
    ~children: element=?,
    unit
) => element = "antd/lib/checkbox/Group";
};