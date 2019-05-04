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

  module Limit = {
    type t;
    external number: int => t = "%identity";
    
    // TODO inline when possible
    let false_: t = [%raw {| (false) |}];
  };

module ShowSearch = {
  type t;
  external bool: bool => t = "%identity";



  type filledFieldNames = {
    .
    "value": string,
    "label": string,
    "children": string,
  };

  [@bs.obj]
  external make:
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
    ~expandTrigger: [@bs.string] [
      | `click
      | `hover
    ]=?,
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
    ~popupPlacement: [@bs.string] [
      | `bottomLeft
      | `bottomRight
      | `topLeft
      | `topRight
    ]=?,
    ~popupVisible: bool=?,
    ~showSearch: ShowSearch.t=?,
    ~size: [@bs.string] [
      | `large
      | `default
      | `small
    ]=?,
    ~style: ReactDOMRe.Style.t=?,
    ~suffixIcon: element=?,
    ~value: array(string)=?,
    ~onChange: (array(string), array(cascaderOption)) => unit=?,
    ~onPopupVisibleChange: bool => unit=?,
    unit
  ) =>
  element =
  "antd/lib/cascader";
