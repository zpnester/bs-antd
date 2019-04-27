

open React;

[@react.component] [@bs.module]
external make: (
    ~target: unit => Dom.htmlElement=?,
    ~visibilityHeight: float=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~style: ReactDOMRe.Style.t=?,
    ~className: string=?,
    ~visible: bool=?,
    ~children: element=?,
    unit
) => element = "antd/lib/back-top";