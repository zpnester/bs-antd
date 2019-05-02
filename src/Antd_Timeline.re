

open React;

[@react.component] [@bs.module]
external make: (
    ~pending: element=?,
    ~pendingDot: element=?,
    ~reverse: bool=?,
    ~mode: [@bs.string] [
        | `left
        | `alternate
        | `right
    ]=?,
    ~style: ReactDOMRe.Style.t=?,
    ~className: string=?,
    ~prefixCls: string=?,
    ~children: element=?,
    unit
) => element = "antd/lib/timeline";

module Item = {
    
[@react.component] [@bs.module]
external make: (
    ~color: string=?,
    ~dot: element=?,
    ~pending: bool=?,
    ~style: ReactDOMRe.Style.t=?,
    ~className: string=?,
    ~prefixCls: string=?,
    ~children: element=?,
    unit
) => element = "antd/lib/timeline/TimelineItem"
};