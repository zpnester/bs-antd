

open React;


module Theme = {
    type t = string;
    [@bs.inline] let filled = "filled";
    [@bs.inline] let outlined = "outlined";
    [@bs.inline] let twoTone = "twoTone";
};

module Type = Antd_IconType;


[@react.component] [@bs.module]
external make:
(
    // ~children: element=?, // no need for children
    // ~ref: Ref.t(Js.Nullable.t(Js.t({..})))=?, // no ref, functional
    ~tabIndex: int=?,
    ~_type: string=?,
    ~className: string=?,
    ~theme: Theme.t=?,
    ~title: string=?,
    ~onKeyUp: ReactEvent.Keyboard.t => unit=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~component: component('customIconProps)=?,
    ~twoToneColor: string=?,
    ~viewBox: string=?,
    ~spin: bool=?,
    ~rotate: float=?,
    ~style: ReactDOMRe.Style.t=?,
    ~prefixCls: string=?,
    ~role: string=?,
    unit
) => element = "antd/lib/icon";