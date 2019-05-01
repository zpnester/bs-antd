
open React;

[@react.component] [@bs.module]
external make: (
    ~className: string=?,
    ~hasSider: bool=?,
    ~prefixCls: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~children: element=?,
    // TODO html div
    ~id: string=?,
    ~tabIndex: int=?,
    ~title: string=?,
    unit
) => element = "antd/lib/layout";

module Content = {
    [@react.component] [@bs.module "antd/lib/layout"]
external make: (
    ~className: string=?,
    ~prefixCls: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~children: element=?,
    // TODO html div
    ~id: string=?,
    ~tabIndex: int=?,
    ~title: string=?,
    unit
) => element = "Content";
};


module Header = {
    [@react.component] [@bs.module "antd/lib/layout"]
external make: (
    ~className: string=?,
    ~prefixCls: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~children: element=?,
    // TODO html div
    ~id: string=?,
    ~tabIndex: int=?,
    ~title: string=?,
    unit
) => element = "Header";
};


module Footer = {
    [@react.component] [@bs.module "antd/lib/layout"]
external make: (
    ~className: string=?,
    ~prefixCls: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~children: element=?,
    // TODO html div
    ~id: string=?,
    ~tabIndex: int=?,
    ~title: string=?,
    unit
) => element = "Footer";
};


module Sider = {

    module Collapse = {
        type t = string;
        [@bs.inline] let clickTrigger = "clickTrigger";
        [@bs.inline] let responsive = "responsive";
    };


    [@react.component] [@bs.module "antd/lib/layout"]
    external make: (
        ~className: string=?,
        ~prefixCls: string=?,
        ~style: ReactDOMRe.Style.t=?,
        ~children: element=?,
        ~breakpoint: [@bs.string] [
            | `xs
            | `sm
            | `md
            | `lg
            | `xl
            | `xxl
        ]=?,
        ~collapsed: bool=?,
        ~collapsedWidth: float=?, // string skipped
        ~_collapsedWidth: string=?, 
        ~collapsible: bool=?,
        ~defaultCollapsed: bool=?,
        ~reverseArrow: bool=?,
        ~theme: [@bs.string] [
            | `light
            | `dark
        ]=?,
        ~trigger: Js.null(element)=?,
        ~width: float=?, // TODO
        ~onCollapse: (bool, Collapse.t) => unit=?,
        ~onBreakpoint: bool => unit=?,
        // TODO html div
        ~id: string=?,
        ~tabIndex: int=?,
        ~title: string=?,
        unit
    ) => element = "Sider";
}; 