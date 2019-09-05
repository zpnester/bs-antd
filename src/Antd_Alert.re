open React;
open Belt;

[@react.component] [@bs.module "antd/lib/alert"]
external make:
  (
    ~_type: [@bs.string] [ | `success | `info | `warning | `error]=?,
    ~closable: bool=?,
    ~closeText: element=?,
    ~message: element=?,
    ~description: element=?,
    ~onClose: ReactEvent.Mouse.t => unit=?,
    ~afterClose: unit => unit=?,
    ~showIcon: bool=?,
//    ~iconType: Antd_IconType.t=?, iconType is deprecated
    ~style: ReactDOMRe.Style.t=?,
    ~prefixCls: string=?,
    ~className: string=?,
    ~banner: bool=?,
    ~icon: element=?,
    ~children: element=?, // TODO no need for children?
    unit
  ) =>
  element =
  "default";