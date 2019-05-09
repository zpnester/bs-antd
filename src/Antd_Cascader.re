open React;

type t;

[@bs.send] external blur: t => unit = "blur";
[@bs.send] external focus: t => unit = "focus";

type cascaderOption('a) =
  {
    ..
    "value": string,
    "label": element,
    "disabled": bool,
    "children": array(cascaderOption('a)),
  } as 'a;

module Limit = {
  type t;
  external number: int => t = "%identity";

  // TODO inline when possible
  let false_: t = [%raw {| false |}];
};

module ShowSearch = {
  type t('option);
  external bool: bool => t('option) = "%identity";

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
      ~filter: (string, array(cascaderOption('option)), filledFieldNames) =>
               bool
                 =?,
      ~render: (
                 string,
                 array(cascaderOption('option)),
                 option(string),
                 filledFieldNames
               ) =>
               element
                 =?,
      ~sort: (
               array(cascaderOption('option)),
               array(cascaderOption('option)),
               string,
               filledFieldNames
             ) =>
             float
               =?,
      ~matchInputWidth: bool=?,
      unit
    ) =>
    t('option) =
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
    ~displayRender: (array(string), array(cascaderOption('option))) =>
                    element
                      =?,
    ~expandTrigger: [@bs.string] [ | `click | `hover]=?,
    ~fieldNames: {
                   .
                   "value": string,
                   "label": string,
                   "children": string,
                 }
                   =?,
    ~getPopupContainer: Dom.htmlElement => Dom.htmlElement=?,
    ~loadData: array(cascaderOption('option)) => unit=?,
    ~notFoundContent: element=?,
    ~options: array(cascaderOption('option)),
    ~placeholder: string=?,
    ~popupClassName: string=?,
    ~popupPlacement: [@bs.string] [
                       | `bottomLeft
                       | `bottomRight
                       | `topLeft
                       | `topRight
                     ]
                       =?,
    ~popupVisible: bool=?,
    ~showSearch: ShowSearch.t('option)=?,
    ~size: [@bs.string] [ | `large | `default | `small]=?,
    ~style: ReactDOMRe.Style.t=?,
    ~suffixIcon: element=?,
    ~value: array(string)=?,
    ~onChange: (array(string), array(cascaderOption('option))) => unit=?,
    ~onPopupVisibleChange: bool => unit=?,
    unit
  ) =>
  element =
  "antd/lib/cascader";