
open React;

type route = {
        .
        "path": string,
        "breadcrumbName": string
    };

module Item = {
    [@react.component] [@bs.module "antd/lib/breadcrumb"]
    external make: (
        ~separator: element=?,
        ~href: string=?,
        ~onClick: ReactEvent.Mouse.t => unit=?,
        ~prefixCls: string=?,
        ~children: element=?,
        ~key: string=?,
        unit
    ) => element = "Item"
};

[@react.component] [@bs.module]
external make: (
    ~style: ReactDOMRe.Style.t=?,
    ~className: string=?,
    ~separator: element=?,
     ~children: element=?,
    ~key: string=?,
    ~prefixCls: string=?,
    unit
) => element = "antd/lib/breadcrumb";

module Routes = {
    [@react.component] [@bs.module]
external make: (
    ~routes: array(route)=?,
    ~itemRender: (route, Js.t({..}), array(route), array(string)) => element=?, // TODO test
    ~style: ReactDOMRe.Style.t=?,
    ~className: string=?,
    ~params: Js.t({..})=?,
    ~separator: element=?,
    ~key: string=?,
     ~prefixCls: string=?,
    unit
) => element = "antd/lib/breadcrumb";
}