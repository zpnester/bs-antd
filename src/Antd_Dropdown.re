open React;

// module Placement = {
//     type t = string;
//     [@bs.inline] let topLeft = "topLeft";
//     [@bs.inline] let topCenter = "topCenter";
//     [@bs.inline] let topRight = "topRight";
//     [@bs.inline] let bottomLeft = "bottomLeft";
//     [@bs.inline] let bottomCenter = "bottomCenter";
//     [@bs.inline] let bottomRight = "bottomRight";

// };

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

[@react.component] [@bs.module]
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
  "antd/lib/dropdown";

module Button = {
  [@react.component] [@bs.module]
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
    "antd/lib/dropdown/dropdown-button";
};