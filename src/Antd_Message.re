open React;

// promise field is not documented on website but keep it anyway
type message = {. "promise": Js.Promise.t(unit)};

// duration and onClose skipped, use open_ for those
// returned promise should cover onClose use cases

[@bs.module "antd/lib/message"]
external success: element => message = "success";
[@bs.module "antd/lib/message"] external error: element => message = "error";
[@bs.module "antd/lib/message"] external info: element => message = "info";
[@bs.module "antd/lib/message"]
external warning: element => message = "warning";
[@bs.module "antd/lib/message"] external warn: element => message = "warn";
[@bs.module "antd/lib/message"]
external loading: element => message = "loading";

module GlobalConfig = {
  type t;

  [@bs.obj]
  external make:
    (
      ~top: float=?,
      ~duration: float=?,
      ~maxCount: int=?,
      ~getContainer: unit => Dom.htmlElement=?,
      ~transitionName: string=?,
      ~prefixCls: string=?,
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
      ~content: element,
      ~duration: Js.null(float)=?,
      ~onClose: unit => unit=?,
      ~icon: element=?,
      ~_type: [@bs.string] [ | `info | `success | `error | `warning | `loading]
                =?,
      unit
    ) =>
    t =
    "";
};

[@bs.module "antd/lib/message"] external open_: Config.t => message = "open";

[@bs.module "antd/lib/message"]
external config: GlobalConfig.t => unit = "config";

[@bs.module "antd/lib/message"] external destroy: unit => unit = "destroy";