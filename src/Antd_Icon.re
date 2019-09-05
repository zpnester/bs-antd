open React;

module Type = Antd_IconType;

[@react.component] [@bs.module "antd/lib/icon"]
// ~children: element=?, // no need for children
// ~ref // no ref, functional
external make:
  (
    ~tabIndex: int=?,
    ~_type: string=?,
    ~className: string=?,
    ~theme: [@bs.string] [ | `filled | `outlined | `twoTone]=?,
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
  ) =>
  element =
  "default";