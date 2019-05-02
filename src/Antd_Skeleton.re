
open React;

module Avatar = {
    type t;

    external bool: bool => t = "%identity";
    [@bs.obj] external make: (
        ~prefixCls: string=?,
        ~className: string=?,
        ~style: ReactDOMRe.Style.t=?,
        ~size: [@bs.string] [
            | `large
            | `small
            | `default
        ]=?,
        ~shape: [@bs.string] [
            | `circle
            | `square
        ]=?,
        unit
    ) => t = "";
};

module Width = {
    type t;
    external string: string => t = "%identity";
    external number: float => t = "%identity";
};

module Paragraph = {
    type t;

    external bool: bool => t = "%identity";

    [@bs.obj] external make: (
        ~prefixCls: string=?,
        ~className: string=?,
        ~style: ReactDOMRe.Style.t=?,
        ~width: Width.t=?,
        ~rows: int=?, // TODO ensure ok
        unit
    ) => t = "";
};

module Title = {
    type t;

    external bool: bool => t = "%identity";

    [@bs.obj] external make: (
        ~prefixCls: string=?,
        ~className: string=?,
        ~style: ReactDOMRe.Style.t=?,
        ~width: Width.t=?,
        unit
    ) => t = "";
};

[@react.component] [@bs.module]
external make: (
    ~active: bool=?,
    ~avatar: Avatar.t=?,
    ~loading: bool=?,
    ~paragraph: Paragraph.t=?,
    ~title: Title.t=?,
    ~prefixCls: string=?,
    ~className: string=?,
    ~children: element=?,
    unit
) => element = "antd/lib/skeleton";