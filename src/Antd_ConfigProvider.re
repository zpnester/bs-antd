open React;

// TODO not tested at all

[@react.component] [@bs.module "antd/lib/config-provider"]
external make:
  (
    ~autoInsertSpaceInButton: bool=?,
    ~csp: {. "nonce": string}=?,
    ~renderEmpty: option(string) => element=?,
    ~getPopupContainer: Dom.htmlElement => Dom.htmlElement=?,
    ~locale: Antd_Locale.t=?,
    ~prefixCls: string=?,
    ~children: element=?,
    unit
  ) =>
  element =
  "default";