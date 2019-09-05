open React;
open Antd__;

type clickParam('a) =
  {
    .
    "key": string, // no need to require key in Item
    "keyPath": array(string),
    "item": Js.t({..}),
    "domEvent": ReactEvent.Synthetic.t,
  } as 'a;

type selectParam('a) =
  {
    .
    "key": string,
    "keyPath": array(string),
    "item": Js.t({..}),
    "domEvent": ReactEvent.Synthetic.t,
    "selectedKeys": array(string),
  } as 'a;

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
    ~onClick: clickParam('clickParam) => unit=?,
    ~onDeselect: selectParam('selectParam) => unit=?,
    ~onOpenChange: array(string) => unit=?,
    ~onSelect: selectParam('selectParam) => unit=?,
    ~overflowedIndicator: element=?,
    ~children: element=?,
    ~focusable: bool=?,
    ~getPopupContainer: Dom.htmlElement => Dom.htmlElement=?,
    ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
    ~prefixCls: string=?,
    ~className: string=?,
    ~openTransitionName: 'todoOpenTransitionName=?,
    ~openAnimation: 'todoOpenAnimation=?,
    ~id: string=?,
    unit
  ) =>
  element =
  "default";

type mouseEvent = {
  .
  "key": string,
  "domEvent": ReactEvent.Mouse.t,
};

module Item = {
  [@react.component] [@bs.module "antd/lib/menu/MenuItem"]
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
      ~onClick: clickParam('clickParam) => unit=?,
      ~onMouseEnter: mouseEvent => unit=?,
      ~onMouseLeave: mouseEvent => unit=?,
      unit
    ) =>
    element =
    "default";
};

type titleEvent = {
  .
  "key": string,
  "domEvent": ReactEvent.Synthetic.t,
};

module SubMenu = {
  [@react.component] [@bs.module "antd/lib/menu/SubMenu"]
  external make:
    (
      ~children: element=?,
      ~disabled: bool=?,
      ~key: string=?,
      ~title: element=?,
      ~onTitleClick: titleEvent => unit=?,
      ~onTitleMouseEnter: titleEvent => unit=?,
      ~onTitleMouseLeave: titleEvent => unit=?,
      ~style: ReactDOMRe.Style.t=?,
      ~className: string=?,
      ~rootPrefixCls: string=?,
      unit
    ) =>
    element =
    "default";
};

module ItemGroup = {
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