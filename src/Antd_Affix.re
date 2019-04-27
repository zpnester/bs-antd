open React;

// TODO target

// module Target = {
//   type t;

//   external window: Dom.window => t = "%identity";
//   external htmlElement: Dom.htmlElement => t = "%identity";
//   let null: t = [%bs.raw {|(null)|}];
// }

[@react.component] [@bs.module]
external make:
  (
    ~children: element=?,
    ~ref: Ref.t(Js.Nullable.t(Js.t({..})))=?,
    ~offsetTop: float=?,
    ~offsetBottom: float=?,
    // ~offset: float=?, // not on website, only in TS
    ~style: ReactDOMRe.Style.t=?,
    ~onChange: bool => unit=?, // TS says optional boolean
    ~target: unit => Dom.htmlElement=?,
    ~prefixCls: string=?,
    ~className: string=?,
    unit
  ) =>
  React.element =
  "antd/lib/affix";
