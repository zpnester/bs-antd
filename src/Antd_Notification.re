
open React;

module GlobalConfig = {
    type t;

    [@bs.obj] external make: (
        ~placement: [@bs.string] [
            | `topLeft
            | `topRight
            | `bottomLeft
            | `bottomRight
        ]=?,
        ~bottom: float=?,
        ~top: float=?,
        ~duration: float=?,
        ~getContainer: unit => Dom.htmlElement=?,
        unit
    ) => t = "";
};

module Config = {
    type t;

    [@bs.obj] external make: (
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
        ]=?,
        ~style: ReactDOMRe.Style.t=?,
        ~onClose: unit => unit=?,
        ~onClick: unit => unit=?,
        ~prefixCls: string=?,
        ~_type: [@bs.string] [ | `info | `success | `error | `warning ]
                =?,
        unit
    ) => t = "";
};

[@bs.module "antd/lib/notification"] external success: Config.t => unit = "success";
[@bs.module "antd/lib/notification"] external error: Config.t => unit = "error";
[@bs.module "antd/lib/notification"] external info: Config.t => unit = "info";
[@bs.module "antd/lib/notification"] external warning: Config.t => unit = "warning";
[@bs.module "antd/lib/notification"] external warn: Config.t => unit = "warn";
[@bs.module "antd/lib/notification"] external open_: Config.t => unit = "open";

[@bs.module "antd/lib/notification"] external close: string => unit = "close";
[@bs.module "antd/lib/notification"] external destroy: unit => unit = "destroy";

[@bs.module "antd/lib/notification"] external config: GlobalConfig.t => unit = "config";
