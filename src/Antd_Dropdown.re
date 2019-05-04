
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



[@react.component] [@bs.module]
external make: (
    ~disabled: bool=?,
    ~getPopupContainer: Dom.element => Dom.htmlElement=?,
    // "You should use Menu as overlay"
    ~overlay: unit => element=?,
    ~overlayClassName: string=?,
    ~overlayStyle: ReactDOMRe.Style.t=?,
    ~placement: [@bs.string] [
        | `topLeft
        | `topCenter
        | `topRight
        | `bottomLeft
        | `bottomCenter
        | `bottomRight
    ]=?,
    ~trigger: [@bs.string] [
        | `click
        | `hover
        | `contextMenu
    ]=?,
    ~visible: bool=?,
    ~onVisibleChange: bool => unit=?,
    // TS only
    // align
    ~prefixCls: string=?,
    ~className: string=?,
    ~transitionName: string=?,
    ~forceRender: bool=?,
    ~mouseEnterDelay: float=?,
    ~mouseLeaveDelay: float=?,
    ~openClassName: string=?,
    unit

) => element = "antd/lib/dropdown";