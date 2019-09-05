open React;

type route('r) =
  {
    ..
    "path": string,
    "breadcrumbName": string,
  } as 'r;

module Item = {
  [@react.component] [@bs.module "antd/es/breadcrumb"] [@bs.scope "default"]
  external make:
    (
      ~prefixCls: string=?,
      ~separator: element=?,
      ~href: string=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~children: element=?,
      ~key: string=?,
      unit
    ) =>
    element =
    "Item";
};

[@react.component] [@bs.module "antd/es/breadcrumb"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~className: string=?,
    ~separator: element=?,
    ~children: element=?,
    ~key: string=?,
    ~prefixCls: string=?,
    unit
  ) =>
  element =
  "default";

type params('a) = Js.t({..}) as 'a;

module Routes = {
  [@react.component] [@bs.module "antd/es/breadcrumb"]
  external make:
    (
      ~routes: array(route('r)),
      ~itemRender: (
                     route('r),
                     params('params),
                     array(route('r)),
                     array(string)
                   ) =>
                   element,
      ~style: ReactDOMRe.Style.t=?,
      ~className: string=?,
      ~params: params('params),
      ~separator: element=?,
      ~key: string=?,
      ~prefixCls: string=?,
      // no children
      unit
    ) =>
    element =
    "default";
};