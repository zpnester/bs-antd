
open React;


module Shape = {
    type t = string;
    [@bs.inline] let round = "round";
    [@bs.inline] let circle = "circle";
    [@bs.inline] let circleOutline = "circle-outline";
};

module Size = {
    type t = string;
    [@bs.inline] let small = "small";
    [@bs.inline] let default = "default";
    [@bs.inline] let large = "large";
};

module Type = {
    type t = string;
    [@bs.inline] let primary = "primary";
    [@bs.inline] let ghost = "ghost";
    [@bs.inline] let dashed = "dashed";
    [@bs.inline] let danger = "danger";
};

module Loading = {
    type t;
    external bool: bool => t = "%identity";
    external object_: {
        .
        "delay": float
    } => t = "%identity";
}

[@react.component] [@bs.module]
external make: (
    ~disabled: bool=?,
    ~ghost: bool=?,
    ~href: string=?,
    ~htmlType: string=?,
    ~icon: Antd_Icon.Type.t=?,
    ~loading: Loading.t=?, 
    ~shape: Shape.t=?,
    ~size: Size.t=?,
    ~target: string=?,
    ~_type: Type.t=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~block: bool=?,
    ~children: element=?,
    ~className: string=?,
    ~prefixCls: string=?,
    unit
) => element = "antd/lib/button";
