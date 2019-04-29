
open React;

module Placement = {
    type t = string;
    [@bs.inline] let top = "top";
    [@bs.inline] let right = "right";
    [@bs.inline] let bottom = "bottom";
    [@bs.inline] let left = "left";
};

[@react.component] [@bs.module]
external make: (
    ~closable: bool=?,
    ~destroyOnClose: bool=?,
    ~getContainer: unit => Dom.htmlElement=?,
    ~mask: bool=?,
    ~maskClosable: bool=?,
    ~maskStyle: ReactDOMRe.Style.t=?,
    ~style: ReactDOMRe.Style.t=?,
    ~bodyStyle: ReactDOMRe.Style.t=?,
    ~title: element=?,
    ~visible: bool=?,
    ~width: string=?, // number skipped
    ~height: string=?, // number skipped
    ~className: string=?,
    ~zIndex: int=?,
    ~placement: Placement.t=?,
    ~onClose: ReactEvent.Mouse.t => unit=?,
    // TS only
    ~wrapClassName: string=?,
    ~prefixCls: string=?,
    ~push: bool=?,
    ~handler: element=?, 
    ~children: element=?,
    unit
) => element = "antd/lib/drawer";