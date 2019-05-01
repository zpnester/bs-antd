
open React;

[@react.component] [@bs.module]
external make: (
    ~title: element=?,
    ~subTitle: element=?,
    ~backIcon: element=?,
    ~tags: array(string)=?, // TODO test
    ~extra: element=?,
    ~breadcrumb: Js.t({..})=?, // TODO improve breadcrumb
    ~footer: element=?,
    ~onBack: ReactEvent.Mouse.t => unit=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
) => element = "antd/lib/page-header";