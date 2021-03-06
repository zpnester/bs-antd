open React;

module Align = {
  [@bs.deriving abstract]
  type make = {
    [@bs.optional]
    points: (string, string),
    [@bs.optional]
    offset: (float, float),
    [@bs.optional]
    targetOffset: (float, float),
    [@bs.optional]
    overflow: {
      .
      "adjustX": option(bool),
      "adjustY": option(bool),
    },
    [@bs.optional]
    useCssRight: bool,
    [@bs.optional]
    useCssBottom: bool,
    [@bs.optional]
    useCssTransform: bool,
  };
};

[@react.component] [@bs.module "antd/es/dropdown"]
// ***** BEGIN DROPDOWN *****
external make:
  (
    ~trigger: [@bs.string] [ | `click | `hover | `contextMenu]=?,
    ~overlay: unit => element=?, // "You should use Menu as overlay"
    ~onVisibleChange: bool => unit=?,
    ~visible: bool=?,
    ~align: Align.make=?,
    ~disabled: bool=?,
    ~getPopupContainer: Dom.element => Dom.htmlElement=?,
    ~prefixCls: string=?,
    ~className: string=?,
    ~transitionName: string=?,
    ~placement: [@bs.string] [
                  | `topLeft
                  | `topCenter
                  | `topRight
                  | `bottomLeft
                  | `bottomCenter
                  | `bottomRight
                ]
                  =?,
    ~overlayClassName: string=?,
    ~overlayStyle: ReactDOMRe.Style.t=?,
    ~forceRender: bool=?,
    ~mouseEnterDelay: float=?,
    ~mouseLeaveDelay: float=?,
    ~openClassName: string=?,
    // ***** END DROPDOWN *****
    ~children: element=?,
    unit
  ) =>
  element =
  "default";

module Button = {
  [@react.component] [@bs.module "antd/es/dropdown/dropdown-button"]
  // ***** BEGIN DROPDOWN BUTTON *****
  external make:
    (
      ~_type: [@bs.string] [ | `primary | `ghost | `dashed]=?,
      ~htmlType: [@bs.string] [ | `submit | `button | `reset]=?,
      // ~disabled: bool=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~href: string=?,
      ~children: element=?,
      // ***** END DROPDOWN BUTTON *****
      // ***** BEGIN BUTTON GROUP *****
      ~size: [@bs.string] [ | `large | `default | `small]=?,
      ~style: ReactDOMRe.Style.t=?,
      // ~className: string=?,
      // ~prefixCls: string=?,
      // ***** END BUTTON GROUP *****
      // ***** BEGIN DROPDOWN *****
      ~trigger: [@bs.string] [ | `click | `hover | `contextMenu]=?,
      ~overlay: unit => element=?, // "You should use Menu as overlay"
      ~onVisibleChange: bool => unit=?,
      ~visible: bool=?,
      ~align: Align.make=?,
      ~disabled: bool=?,
      ~getPopupContainer: Dom.element => Dom.htmlElement=?,
      ~prefixCls: string=?,
      ~className: string=?,
      ~transitionName: string=?,
      ~placement: [@bs.string] [
                    | `topLeft
                    | `topCenter
                    | `topRight
                    | `bottomLeft
                    | `bottomCenter
                    | `bottomRight
                  ]
                    =?,
      ~overlayClassName: string=?,
      ~overlayStyle: ReactDOMRe.Style.t=?,
      ~forceRender: bool=?,
      ~mouseEnterDelay: float=?,
      ~mouseLeaveDelay: float=?,
      ~openClassName: string=?,
      // ***** END DROPDOWN *****
      unit
    ) =>
    element =
    "default";
};