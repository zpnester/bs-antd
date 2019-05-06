open React;

[@react.component] [@bs.module]
external make:
  (
    ~title: element=?,
    ~subTitle: element=?,
    ~backIcon: element=?,
    ~tags: array(element)=?,
    ~extra: element=?,
    ~breadcrumb: Js.t({..})=?, // TODO ref breadcrumb, lowest priority
    ~footer: element=?,
    ~onBack: ReactEvent.Mouse.t => unit=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  element =
  "antd/lib/page-header";