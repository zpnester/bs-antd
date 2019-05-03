open React;

[@react.component] [@bs.module]
external make:
  (
    ~children: element=?,
    ~ref: Ref.t(Js.Nullable.t(Js.t({..})))=?,
    ~offsetTop: float=?,
    ~offsetBottom: float=?,
    ~offset: float=?,
    ~style: ReactDOMRe.Style.t=?,
    ~onChange: bool => unit=?,
    ~target: unit => Dom.htmlElement=?, // null and window skipped, window is default
    ~prefixCls: string=?,
    ~className: string=?,
    unit
  ) =>
  React.element =
  "antd/lib/affix";
