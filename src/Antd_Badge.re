open React;

[@react.component] [@bs.module]
external make:
  (
    ~color: string=?,
    ~count: element=?,
    ~dot: bool=?,
    ~offset: (float, float)=?,
    ~overflowCount: float=?,
    ~showZero: bool=?,
    ~status: [@bs.string] [
               | `success
               | `processing
               | `default
               | `error
               | `warning
             ]
               =?,
    ~text: element=?, // website says string, TS says ReactNode
    ~title: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~className: string=?,
    ~children: element=?,
    unit
  ) =>
  element =
  "antd/lib/badge";