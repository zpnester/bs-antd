
open React;


[@react.component] [@bs.module]
external make: (
    ~closable: bool=?,
    ~destroyOnClose: bool=?,
    ~getContainer: unit => Dom.htmlElement=?,
    ~mask: bool=?,
    ~maskClosable: bool=?,
    ~maskStyle: ReactDOMRe.Style.t=?,
    ~style: ReactDOMRe.Style.t=?,
    ~bodyStyle: ReactDOMRe.Style.t=?,
    ~title: element=?,
    ~visible: bool=?,
    ~width: string=?, // number skipped
    ~height: string=?, // number skipped
    ~className: string=?,
    ~zIndex: int=?,
    ~placement: [@bs.string] [
        | `top
        | `right
        | `bottom
        | `left
    ]=?,
    ~onClose: ReactEvent.Mouse.t => unit=?,
    // TS only
    ~wrapClassName: string=?,
    ~prefixCls: string=?,
    ~push: bool=?,
    ~handler: element=?, 
    ~children: element=?,
    unit
) => element = "antd/lib/drawer";