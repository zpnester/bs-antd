open React;

module GlobalConfig = {
  type t;

  [@bs.obj]
  external make:
    (
      ~placement: [@bs.string] [
                    | `topLeft
                    | `topRight
                    | `bottomLeft
                    | `bottomRight
                  ]
                    =?,
      ~bottom: float=?,
      ~top: float=?,
      ~duration: float=?,
      ~getContainer: unit => Dom.htmlElement=?,
      unit
    ) =>
    t =
    "";
};

module Config = {
  type t;

  [@bs.obj]
  external make:
    (
      ~btn: element=?,
      ~className: string=?,
      ~description: element=?,
      ~duration: Js.null(float)=?,
      ~icon: element=?,
      ~key: string=?,
      ~message: element=?,
      ~placement: [@bs.string] [
                    | `topLeft
                    | `topRight
                    | `bottomLeft
                    | `bottomRight
                  ]
                    =?,
      ~style: ReactDOMRe.Style.t=?,
      ~onClose: unit => unit=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~prefixCls: string=?,
      ~_type: [@bs.string] [ | `info | `success | `error | `warning]=?,
      unit
    ) =>
    t =
    "";
};

[@bs.module "antd/es/notification"] [@bs.scope "default"]
external success: Config.t => unit = "success";
[@bs.module "antd/es/notification"] [@bs.scope "default"]
external error: Config.t => unit = "error";
[@bs.module "antd/es/notification"] [@bs.scope "default"] external info: Config.t => unit = "info";
[@bs.module "antd/es/notification"] [@bs.scope "default"]
external warning: Config.t => unit = "warning";
[@bs.module "antd/es/notification"] [@bs.scope "default"] external warn: Config.t => unit = "warn";
[@bs.module "antd/es/notification"] [@bs.scope "default"] external open_: Config.t => unit = "open";

[@bs.module "antd/es/notification"] [@bs.scope "default"] external close: string => unit = "close";
[@bs.module "antd/es/notification"] [@bs.scope "default"]
external destroy: unit => unit = "destroy";

[@bs.module "antd/es/notification"] [@bs.scope "default"]
external config: GlobalConfig.t => unit = "config";