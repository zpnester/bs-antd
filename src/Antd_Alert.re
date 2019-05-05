open React;
open Belt;

[@react.component] [@bs.module]
external make:
  (
    ~_type: [@bs.string] [ | `success | `info | `warning | `error]=?,
    ~closable: bool=?,
    ~closeText: element=?,
    ~message: element=?,
    ~description: element=?,
    // React.MouseEventHandler<HTMLAnchorElement>
    ~onClose: ReactEvent.Mouse.t => unit=?,
    ~afterClose: unit => unit=?,
    ~showIcon: bool=?,
    ~iconType: Antd_IconType.t=?,
    ~style: ReactDOMRe.Style.t=?,
    ~prefixCls: string=?,
    ~className: string=?,
    ~banner: bool=?,
    ~icon: element=?,
    ~children: element=?, // TODO no need for children?
    unit
  ) =>
  element =
  "antd/lib/alert";
