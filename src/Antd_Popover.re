open React;

module AdjustOverflow = {
  type t;

  external bool: bool => t = "%identity";
  // TODO test
  [@bs.obj] external make: (~adjustX: int=?, ~adjustY: int=?, unit) => t = "";
};

module Offset = {
  type t;

  // TODO test
  external numbers: ((float, float)) => t = "%identity";
  external strings: ((string, string)) => t = "%identity";
};

module Align = {
  type t;

  [@bs.obj]
  external make:
    (
      ~points: (string, string)=?,
      ~offset: Offset.t=?,
      ~targetOffset: Offset.t=?,
      ~overflow: {
                   .
                   "adjustX": bool,
                   "adjustY": bool,
                 }
                   =?,
      ~useCssRight: bool=?,
      ~useCssBottom: bool=?,
      ~useCssTransform: bool=?,
      unit
    ) =>
    t =
    "";
};

[@react.component] [@bs.module "antd/es/popover"]
external make:
  (
    ~content: element=?,
    ~title: element=?,
    ~prefixCls: string=?,
    ~overlayClassName: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~className: string=?,
    ~overlayStyle: ReactDOMRe.Style.t=?,
    ~placement: [@bs.string] [
                  | `top
                  | `left
                  | `right
                  | `bottom
                  | `topLeft
                  | `topRight
                  | `bottomLeft
                  | `bottomRight
                  | `leftTop
                  | `leftBottom
                  | `rightTop
                  | `rightBottom
                ]
                  =?,
    ~builtinPlacements: Js.t({..})=?, // TODO
    ~defaultVisible: bool=?,
    ~visible: bool=?,
    ~onVisibleChange: bool => unit=?,
    ~mouseEnterDelay: float=?,
    ~mouseLeaveDelay: float=?,
    ~transitionName: string=?,
    ~trigger: [@bs.string] [ | `hover | `focus | `click | `contextMenu]=?,
    ~openClassName: string=?,
    ~arrowPointAtCenter: bool=?,
    ~autoAdjustOverflow: AdjustOverflow.t=?,
    ~getTooltipContainer: Dom.element => Dom.htmlElement=?,
    ~getPopupContainer: Dom.htmlElement => Dom.htmlElement=?,
    ~children: element=?,
    ~align: Align.t=?,
    unit
  ) =>
  element =
  "default";