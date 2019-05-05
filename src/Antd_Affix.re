open React;

[@react.component] [@bs.module]
external make:
  (
    ~offsetTop: float=?,
    ~offsetBottom: float=?,
    ~offset: float=?,
    ~style: ReactDOMRe.Style.t=?,
    ~onChange: bool => unit=?,
    ~target: unit => Dom.htmlElement=?, // null and window skipped, window is default
    ~prefixCls: string=?,
    ~className: string=?,
    ~children: element=?,
    unit
  ) =>
  React.element =
  "antd/lib/affix";
