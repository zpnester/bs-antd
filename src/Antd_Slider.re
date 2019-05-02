
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

[@react.component] [@bs.module]
external make: (
    // not optional to ensure type safety
    ~range: Range.t('value),
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
    ~tipFormatter: Js.null(float => element)=?, // tODO remove null if possible
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
) => element = "antd/lib/slider";


// module Uncontrolled = {
//     [@react.component] [@bs.module]
//     external make: (
//         ~ref: Ref.t(Js.nullable(t))=?,
//         ~autoFocus: bool=?,


//     ) => element = "antd/lib/slider";
// };