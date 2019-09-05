open React;

[@react.component] [@bs.module "antd/es/tag"]
external make:
  (
    ~afterClose: unit => unit=?,
    ~closable: bool=?,
    ~color: string=?,
    ~onClose: ReactEvent.Mouse.t => unit=?, // TODO change if not always mouse
    ~visible: bool=?,
    ~style: ReactDOMRe.Style.t=?,
    ~className: string=?,
    ~prefixCls: string=?,
    ~children: element=?,
    unit
  ) =>
  element =
  "default";

module CheckableTag = {
  [@react.component] [@bs.module "antd/es/tag/CheckableTag"]
  external make:
    (
      ~checked: bool=?,
      ~onChange: bool => unit=?,
      ~style: ReactDOMRe.Style.t=?,
      ~className: string=?,
      ~prefixCls: string=?,
      ~children: element=?,
      unit
    ) =>
    element =
    "default";
};