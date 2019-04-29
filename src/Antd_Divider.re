

open React;


module Orientation = {
    type t = string;
    [@bs.inline] let left = "left";
    [@bs.inline] let right = "right";
};

module Type = {
    type t = string;
    [@bs.inline] let horizontal = "horizontal";
    [@bs.inline] let vertical = "vertical";

};

[@react.component] [@bs.module]
external make: (
    ~className: string=?,
    ~dashed: bool=?,
    ~orientation: Orientation.t=?,
    ~style: ReactDOMRe.Style.t=?,
    ~_type: Type.t=?,
    ~prefixCls: string=?,
    ~children: element=?,
    unit 
) => element = "antd/lib/divider"