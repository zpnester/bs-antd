

open React;

module Size = {
    type t = string;
    [@bs.inline] let small = "small";
    [@bs.inline] let default = "default";
    [@bs.inline] let large = "large";
};

[@bs.deriving abstract]
type makeProps = {
    [@bs.optional]
    delay: float,
    [@bs.optional]
    indicator: element,
    [@bs.optional]
    size: Size.t,
    [@bs.optional]
    spinning: bool,
    [@bs.optional]
    tip: string,
    [@bs.optional]
    wrapperClassName: string,
    [@bs.optional]
    prefixCls: string,
    [@bs.optional]
    className: string,
    [@bs.optional]
    style: ReactDOMRe.Style.t,
    [@bs.optional]
    children: element
};

[@bs.module]
external make: component(makeProps) = "antd/lib/spin";