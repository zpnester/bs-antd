
open React;

module Status = {
    type t = string;
    [@bs.inline] let success  = "success";
    [@bs.inline] let processing   = "processing";
    [@bs.inline] let default    = "default";
    [@bs.inline] let error     = "error";
    [@bs.inline] let warning     = "warning";

};

[@react.component] [@bs.module]
external make: (
    ~color: string=?,
    ~count: element=?,
    ~dot: bool=?,
    ~offset: (float, float)=?,
    ~overflowCount: float=?,
    ~showZero: bool=?,
    ~status: Status.t=?,
    ~text: element=?, // website says string, TS says ReactNode
    ~title: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~className: string=?,
    ~children: element=?,
    unit
) => element = "antd/lib/badge";