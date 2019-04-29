open React;

module Size = {
    type t = string;
    [@bs.inline] let default = "default";
    [@bs.inline] let small = "small";
};

[@react.component] [@bs.module]
external make: 
(
    ~prefixCls: string=?,
    ~title: element=?,
    ~extra: element=?,
    ~bordered: bool=?,
    ~headStyle: ReactDOMRe.Style.t=?,
    ~bodyStyle: ReactDOMRe.Style.t=?,
    ~style: ReactDOMRe.Style.t=?,
    ~loading: bool=?,
    ~noHovering: bool=?,
    ~hoverable: bool=?,
    ~children: element=?,
    ~id: string=?,
    ~className: string=?,
    ~size: Size.t=?,
    // ~_type
    ~cover: element=?,
    ~actions: array(element)=?,
    ~tabList: array({
        .
        key: string,
        tab: element,
        disabled: bool
    })=?,
    ~onTabChange: string => unit=?,
    ~activeTabKey: string=?,
    ~defaultActiveTabKey: string=?,
    unit
) => element = "antd/lib/card"; 