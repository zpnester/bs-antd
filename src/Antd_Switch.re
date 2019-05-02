open React;

type t;

[@bs.send] external blur: t => unit = "blur";
[@bs.send] external focus: t => unit = "focus";

[@react.component] [@bs.module]
external make:
  (
    ~ref: Ref.t(Js.nullable(t))=?,
    ~autoFocus: bool=?,
    ~checked: bool=?,
    ~checkedChildren: element=?,
    ~defaultChecked: bool=?,
    ~disabled: bool=?,
    ~loading: bool=?,
    ~size: [@bs.string] [ | `small | `default]=?,
    ~unCheckedChildren: element=?,
    ~onChange: (bool, ReactEvent.Mouse.t) => unit=?, // react event, not dom
    ~onClick: (bool, ReactEvent.Mouse.t) => unit=?, // react event, not dom
    ~className: string=?,
    ~prefixCls: string=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  element =
  "antd/lib/switch";
