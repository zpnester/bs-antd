open React;

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
    ~getContainer: unit => Dom.htmlElement=?, // window skipped, window is default
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
      ~href: string=?,
      ~title: element=?,
      ~children: element=?,
      ~className: string=?
    ) =>
    element =
    "Link";
};
