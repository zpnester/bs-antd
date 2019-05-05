

open React;

module Copyable = {
    type t;

    external bool: bool => t = "%identity";

    [@bs.obj] external make: (
        ~text: string=?,
        ~onCopy: unit => unit,
        unit
    ) => t = "";
};

module Editable = {
    type t;

    external bool: bool => t = "%identity";

    [@bs.obj] external make: (
        ~editing: bool=?,
        ~onStart: unit => unit=?,
        ~onChange: string => unit=?,
        unit
    ) => t = "";
};

module Ellipsis = {
    type t;

    external bool: bool => t = "%identity";

    [@bs.obj] external make: (
        ~rows: int=?,
        ~expandable: bool=?,
        ~onExpand: unit => unit=?,
        unit
    ) => t = "";
};


module Text = {

[@react.component] [@bs.module]
external make: (
    ~code: bool=?,
    ~copyable: Copyable.t=?,
    ~delete: bool=?,
    ~disabled: bool=?,
    ~editable: Editable.t=?,
    ~ellipsis: Ellipsis.t=?,
    ~mark: bool=?,
    ~underline: bool=?,
    ~onChange: string => unit=?, // not in TS
    ~strong: bool=?,
    ~_type: [@bs.string] [
        | `secondary
        | `danger
        | `warning
    ]=?,
    // typography
    ~id: string=?,
    ~prefixCls: string=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~children: element=?,
    unit
) => element = "antd/lib/typography/Text";

}

module Title = {
    [@react.component] [@bs.module]
    external make: (
     ~onChange: string => unit=?, // not in TS
        // block
        ~editable: Editable.t=?,
    ~copyable: Copyable.t=?,
    ~_type: [@bs.string] [
        | `secondary
        | `danger
        | `warning
    ]=?,
    ~disabled: bool=?,
    ~ellipsis: Ellipsis.t=?,
    ~code: bool=?,
    ~mark: bool=?,
    ~underline: bool=?,
    ~delete: bool=?,
    // omit strong
    ~level: [@bs.int] [
        | [@bs.as 1] `h1
        | [@bs.as 2 ] `h2
        | [@bs.as 3] `h3
        | [@bs.as 4] `h4
    ]=?,
    // typography

        ~id: string=?,
    ~prefixCls: string=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~children: element=?,
        unit
    ) => element = "antd/lib/typography/Title";
};


module Paragraph = {
     [@react.component] [@bs.module]
    external make: (
     ~onChange: string => unit=?, // not in TS
        // block
    ~editable: Editable.t=?,
    ~copyable: Copyable.t=?,
    ~_type: [@bs.string] [
        | `secondary
        | `danger
        | `warning
    ]=?,
    ~disabled: bool=?,
    ~ellipsis: Ellipsis.t=?,
    ~code: bool=?,
    ~mark: bool=?,
    ~underline: bool=?,
    ~delete: bool=?,
    ~strong: bool=?,
    // omit strong
    // typography
     ~id: string=?,
    ~prefixCls: string=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~children: element=?,
    unit
    ) => element = "antd/lib/typography/Paragraph";
};