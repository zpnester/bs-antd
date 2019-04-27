open React;

// module Container = {
//     type t;
//     external window: Dom.window => t = "%identity";
//     external htmlElement: Dom.htmlElement => t = "%identity";

// };

[@react.component] [@bs.module]
external make:
  (
    ~prefixCls: string=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~children: element=?,
    ~offsetTop: float=?,
    ~bounds: float=?,
    ~affix: bool=?,
    ~showInkInFixed: bool=?,
    ~getContainer: unit => Dom.htmlElement=?,
    ~onClick: (
                ReactEvent.Mouse.t,
                {
                  .
                  "title": element,
                  "href": string,
                }
              ) =>
              unit
                =?,
    unit
  ) =>
  element =
  "antd/lib/anchor";

module Link = {
  [@react.component] [@bs.module "antd/lib/anchor"]
  external make:
    (
      ~prefixCls: string=?,
      ~href: string=?, // TS: not optional
      ~title: element=?, // TS: not optional
      ~children: element=?, // children?: any;
      ~className: string=?
    ) =>
    element =
    "Link";
};
