open React;

type t;

[@bs.send] external blur: t => unit = "blur";
[@bs.send] external focus: t => unit = "focus";

module Range = {
  type t('value);

  let true_: t((float, float)) = [%raw {| (true) |}];
  let false_: t(float) = [%raw {| (false) |}];
};

module Marks = {
  type t;

  external makeUnsafe: Js.t({..}) => t = "%identity";
};

[@react.component] [@bs.module "antd/es/slider"]
external make:
  (
    ~range: Range.t('value), // required
    ~ref: Ref.t(Js.nullable(t))=?,
    ~autoFocus: bool=?,
    ~defaultValue: 'value=?,
    ~disabled: bool=?,
    ~dots: bool=?,
    ~included: bool=?,
    ~marks: Marks.t=?,
    ~max: float=?,
    ~min: float=?,
    ~step: Js.null(float)=?, // null requried
    ~tipFormatter: Js.null(float => element)=?, // TODO remove null if possible
    ~value: 'value=?,
    ~vertical: bool=?,
    ~onAfterChange: 'value => unit=?,
    ~onChange: 'value => unit=?,
    ~tooltipVisible: bool=?,
    ~id: string=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~prefixCls: string=?,
    ~tooltipPrefixCls: string=?,
    unit
  ) =>
  element =
  "default";