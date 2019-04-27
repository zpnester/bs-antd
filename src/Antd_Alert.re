open React;
open Belt;

type props;

module Type = {
  type t = string;

  [@bs.inline]
  let success = "success";
  [@bs.inline]
  let info = "info";
  [@bs.inline]
  let warning = "warning";
  [@bs.inline]
  let error = "error";
};

[@react.component] [@bs.module]
external make:
  // ~children: element=?, // no need for children
  // ~ref: Ref.t(Js.Nullable.t(Js.t({..})))=?,
  (
    ~_type: Type.t=?,
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
    unit
  ) =>
  element =
  "antd/lib/alert";
