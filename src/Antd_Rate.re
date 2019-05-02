
open React;


type t;

[@bs.send] external blur: t => unit = "blur";
[@bs.send] external focus: t => unit = "focus";

[@react.component] [@bs.module]
external make: (
    ~ref: Ref.t(Js.nullable(t))=?,
    ~allowClear: bool=?,
    ~allowHalf: bool=?,
    ~autoFocus: bool=?,
    ~character: element=?,
    ~className: string=?,
    ~count: int=?,
    ~defaultValue: float=?, // TODO float vs int OK?
    ~disabled: bool=?,
    ~style: ReactDOMRe.Style.t=?,
    ~tooltips: array(string)=?,
    ~value: float=?,
    ~onBlur: unit => unit=?, // TODO type?
    ~onChange: float => unit=?, // TODO test
    ~onFocus: unit => unit=?,
    ~onHoverChange: float => unit=?,
    ~onKeyDown: ReactEvent.Keyboard.t => unit=?, // tODO test
    ~prefixCls: string=?,
    unit
) => element = "antd/lib/rate";