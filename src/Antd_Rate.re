open React;

type t;

[@bs.send] external blur: t => unit = "blur";
[@bs.send] external focus: t => unit = "focus";

[@react.component] [@bs.module "antd/lib/rate"]
external make:
  (
    ~ref: Ref.t(Js.nullable(t))=?,
    ~allowClear: bool=?,
    ~allowHalf: bool=?,
    ~autoFocus: bool=?,
    ~character: element=?,
    ~className: string=?,
    ~count: int=?,
    ~defaultValue: float=?,
    ~disabled: bool=?,
    ~style: ReactDOMRe.Style.t=?,
    ~tooltips: array(string)=?,
    ~value: float=?,
    ~onBlur: unit => unit=?,
    ~onChange: float => unit=?,
    ~onFocus: unit => unit=?,
    ~onHoverChange: float => unit=?,
    ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~prefixCls: string=?,
    unit
  ) =>
  element =
  "default";