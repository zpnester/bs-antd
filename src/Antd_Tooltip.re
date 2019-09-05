open React;

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

[@react.component] [@bs.module "antd/es/tooltip"]
external make:
  (
    ~arrowPointAtCenter: bool=?,
    ~autoAdjustOverflow: bool=?,
    ~defaultVisible: bool=?,
    ~getPopupContainer: Dom.htmlElement => Dom.htmlElement=?,
    ~getTooltipContainer: Dom.element => Dom.htmlElement=?,
    ~mouseEnterDelay: float=?,
    ~mouseLeaveDelay: float=?,
    ~overlayClassName: string=?,
    ~overlayStyle: ReactDOMRe.Style.t=?,
    ~style: ReactDOMRe.Style.t=?,
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
    ~trigger: [@bs.string] [ | `hover | `focus | `click | `contextMenu]=?,
    ~visible: bool=?,
    ~onVisibleChange: bool => unit=?,
    ~align: Align.t=?,
    ~children: element=?,
    ~title: unit => element=?,
    ~overlay: unit => element=?,
    ~openClassName: string=?,
    ~builtinPlacements: Js.t({..})=?, // TODO
    ~prefixCls: string=?,
    ~className: string=?,
    unit
  ) =>
  element =
  "default";