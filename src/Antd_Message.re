
open React;

// [@bs.module "antd/lib/message"] external
// success: (element, ~duration: float=?, ~onClose: unit => unit, unit) => unit = "success";



// onClose skipped, returned promise should cover onClose use cases


// promise field is not documented on website but keep it anyway
type message = { 
    . 
    "promise": Js.Promise.t(unit)
};

[@bs.module "antd/lib/message"] external success: (element, ~duration: option(float)) => message = "success";
[@bs.module "antd/lib/message"] external error: (element, ~duration: option(float)) => message = "error";
[@bs.module "antd/lib/message"] external info: (element, ~duration: option(float)) => message = "info";
[@bs.module "antd/lib/message"] external warning: (element, ~duration: option(float)) => message = "warning";
[@bs.module "antd/lib/message"] external warn: (element, ~duration: option(float)) => message = "warn";
[@bs.module "antd/lib/message"] external loading: (element, ~duration: option(float)) => message = "loading";

// TODO
module GlobalConfig = {
    type t;

    [@bs.obj] external make: (
        ~top: float=?,
        ~duration: float=?,
        ~maxCount: float=?,
        ~getContainer: unit => Dom.htmlElement=?,
        ~transitionName: string=?,
        ~prefixCls: string=?,
        unit
    ) => t = "";

}

module Config = {
    type t;

    [@bs.obj] external make: (
        ~content: element,
    ~duration: Js.null(float)=?,
    ~onClose: unit => unit=?,
    ~icon: element=?,
    ~_type: [@bs.string] [
        | `info
        | `success
        | `error
        | `warning
        | `loading
    ]=?,
    unit
    ) => t = "";
};

[@bs.module "antd/lib/message"] external
open_: (Config.t) => message = "open"; 


[@bs.module "antd/lib/message"] external
config: (GlobalConfig.t) => unit = "config"; 

[@bs.module "antd/lib/message"] external
destroy: unit => unit = "destroy"; 
