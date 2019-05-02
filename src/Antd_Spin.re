

open React;

[@react.component] [@bs.module]
external make: (
    ~delay: float=?,
    ~indicator: element=?,
    ~size: [@bs.string] [
        | `small
        | `default
        | `large
    ]=?,
    ~spinning: bool=?,
    ~tip: string=?,
    ~wrapperClassName: string=?,
    ~prefixCls: string=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~children: element=?,
    unit
) => element = "antd/lib/spin"