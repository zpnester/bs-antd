open React;

type clickParam = {
  .
  "key": string,
  "keyPath": array(string),
  "item": Js.Json.t, // TODO
  "domEvent": Dom.event // TODO dom or react
};

type selectParam = {
  .
  "key": string,
  "keyPath": array(string),
  "item": Js.Json.t, // TODO
  "domEvent": Dom.event, // TODO dom or react
  "selectedKeys": array(string),
};

[@react.component] [@bs.module "antd/lib/menu"]
external make:
  (
    ~defaultOpenKeys: array(string)=?,
    ~defaultSelectedKeys: array(string)=?,
    ~forceSubMenuRender: bool=?,
    ~inlineCollapsed: bool=?,
    ~inlineIndent: float=?,
    ~mode: [@bs.string] [
             | `vertical
             | [@bs.as "vertical-left"] `verticalLeft
             | [@bs.as "vertical-right"] `verticalRight
             | `horizontal
             | `inline
           ]
             =?,
    ~multiple: bool=?,
    ~openKeys: array(string)=?,
    ~selectable: bool=?,
    ~selectedKeys: array(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    ~subMenuCloseDelay: float=?,
    ~subMenuOpenDelay: float=?,
    ~theme: [@bs.string] [ | `light | `dark]=?,
    ~onClick: clickParam => unit=?,
    ~onDeselect: selectParam => unit=?,
    ~onOpenChange: array(string) => unit=?,
    ~onSelect: selectParam => unit=?,
    ~overflowedIndicator: element=?,
    ~children: element=?,
    ~focusable: bool=?,
    ~getPopupContainer: Dom.htmlElement => Dom.htmlElement=?,
    ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
    ~prefixCls: string=?,
    ~className: string=?,
    ~openTransitionName: 'openTransitionName=?, // TODO
    ~openAnimation: 'openAnimation=?, // TODO
    ~id: string=?,
    unit
  ) =>
  element =
  "default";

module Item = {
  [@react.component] [@bs.module]
  external make:
    (
      ~disabled: bool=?,
      ~key: string=?,
      ~title: string=?,
      ~rootPrefixCls: string=?,
      ~level: float=?,
      ~children: element=?,
      ~className: string=?,
      ~style: ReactDOMRe.Style.t=?,
      ~onClick: clickParam => unit=?,
      ~onMouseEnter: {
                       .
                       "key": string,
                       "domEvent": Dom.mouseEvent,
                     } =>
                     unit
                       =?,
      ~onMouseLeave: {
                       .
                       "key": string,
                       "domEvent": Dom.mouseEvent,
                     } =>
                     unit
                       =?,
      unit
    ) =>
    element =
    "antd/lib/menu/MenuItem";
};

module SubMenu = {
  [@react.component] [@bs.module]
  external make:
    (
      ~children: element=?,
      ~disabled: bool=?,
      ~key: string=?,
      ~title: element=?,
      ~onTitleClick: {
                       .
                       "key": string,
                       "domEvent": Dom.event,
                     } =>
                     unit
                       =?,
      ~onTitleMouseEnter: {
                            .
                            "key": string,
                            "domEvent": Dom.event,
                          } =>
                          unit
                            =?,
      ~onTitleMouseLeave: {
                            .
                            "key": string,
                            "domEvent": Dom.event,
                          } =>
                          unit
                            =?,
      ~style: ReactDOMRe.Style.t=?,
      ~className: string=?,
      ~rootPrefixCls: string=?,
      unit
    ) =>
    element =
    "antd/lib/menu/SubMenu";
};

module ItemGroup = {
  // default: potential problem
  [@react.component] [@bs.module "antd/lib/menu"] [@bs.scope "default"]
  external make:
    (
      ~children: element=?,
      ~title: element=?,
      // TODO nothing in TS and website?
      unit
    ) =>
    element =
    "ItemGroup";
};