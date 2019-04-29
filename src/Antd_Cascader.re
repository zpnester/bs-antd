open React;

type t;

[@bs.send] external blur: t => unit = "blur";
[@bs.send] external focus: t => unit = "focus";

// TODO .. if possible
type cascaderOption = {
  .
  "value": string,
  "label": element,
  "disabled": bool,
  "children": array(cascaderOption),
};

module ExpandTrigger = {
  type t = string;
  [@bs.inline]
  let click = "click";
  [@bs.inline]
  let hover = "hover";
};

module PopupPlacement = {
  type t = string;
  [@bs.inline]
  let bottomLeft = "bottomLeft";
  [@bs.inline]
  let bottomRight = "bottomRight";
  [@bs.inline]
  let topLeft = "topLeft";
  [@bs.inline]
  let topRight = "topRight";
};

module ShowSearch = {
  type t;
  external bool: bool => t = "%identity";

  module Limit = {
    type t;
    external number: int => t = "%identity";
    // TODO inline when possible
    let false_: t = [%raw {| (false) |}];
  };

  type filledFieldNames = {
    .
    "value": string,
    "label": string,
    "children": string,
  };

  [@bs.obj]
  external object_:
    (
      ~limit: Limit.t=?,
      ~filter: (string, array(cascaderOption), filledFieldNames) => bool=?,
      ~render: (string, array(cascaderOption), option(string), filledFieldNames) =>
               element
                 =?,
      ~sort: (array(cascaderOption), array(cascaderOption), string, filledFieldNames) => float=?,
      ~matchInputWidth: bool=?,
      unit
    ) =>
    t =
    "";
};

module Size = {
  type t = string;
  [@bs.inline]
  let large = "large";
  [@bs.inline]
  let default = "default";
  [@bs.inline]
  let small = "small";
};

[@react.component] [@bs.module]
external make:
  (
    ~ref: Ref.t(Js.Nullable.t(t))=?,
    ~allowClear: bool=?,
    ~autoFocus: bool=?,
    ~changeOnSelect: bool=?,
    ~className: string=?,
    ~defaultValue: array(string)=?,
    ~disabled: bool=?,
    ~displayRender: (array(string), array(cascaderOption)) => element=?,
    ~expandTrigger: ExpandTrigger.t=?,
    ~fieldNames: {
                   .
                   "value": string,
                   "label": string,
                   "children": string,
                 }
                   =?,
    ~getPopupContainer: Dom.htmlElement => Dom.htmlElement=?,
    ~loadData: array(cascaderOption) => unit=?,
    ~notFoundContent: element=?,
    ~options: array(cascaderOption)=?,
    ~placeholder: string=?,
    ~popupClassName: string=?,
    ~popupPlacement: PopupPlacement.t=?,
    ~popupVisible: bool=?,
    ~showSearch: ShowSearch.t=?,
    ~size: Size.t=?,
    ~style: ReactDOMRe.Style.t=?,
    ~suffixIcon: element=?,
    ~value: array(string)=?,
    ~onChange: (array(string), array(cascaderOption)) => unit=?,
    ~onPopupVisibleChange: bool => unit=?,
    unit
  ) =>
  element =
  "antd/lib/cascader";
