open React;

[@react.component] [@bs.module "antd/es/back-top"]
external make:
  (
    ~target: unit => Dom.htmlElement=?,
    ~visibilityHeight: float=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~style: ReactDOMRe.Style.t=?,
    ~className: string=?,
    ~visible: bool=?,
    ~children: element=?,
    unit
  ) =>
  element =
  "default";