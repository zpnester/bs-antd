open React;

[@react.component] [@bs.module "antd/es/badge"]
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
    ~text: element=?,
    ~title: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~className: string=?,
    ~children: element=?,
    unit
  ) =>
  element =
  "default";