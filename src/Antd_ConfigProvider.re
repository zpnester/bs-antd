open React;

// TODO not tested at all

[@react.component] [@bs.module]
external make:
  (
    ~autoInsertSpaceInButton: bool=?,
    ~csp: {. "nonce": string}=?,
    ~renderEmpty: option(string) => element=?,
    ~getPopupContainer: Dom.htmlElement => Dom.htmlElement=?,
    ~prefixCls: string=?,
    ~children: element=?,
    unit
  ) =>
  element =
  "antd/lib/config-provider";
