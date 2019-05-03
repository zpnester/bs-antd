

open React;

module Width = {
    type t;
    external string: string => t = "%identity";
    external number: float => t = "%identity";
};


[@react.component] [@bs.module]
external make: (
    ~afterClose: unit => unit=?,
    ~bodyStyle: ReactDOMRe.Style.t=?,
    ~cancelText: element=?,
    ~centered: bool=?,
    ~closable: bool=?,
    ~confirmLoading: bool=?,
    ~destroyOnClose: bool=?,
    ~footer: element=?,
    ~forceRender: bool=?,
    ~getContainer: Js.Json.t => Dom.htmlElement=?, // TODO
    ~mask: bool=?,
    ~maskClosable: bool=?,
    ~maskStyle: ReactDOMRe.Style.t=?,
    ~okText: element=?,
    ~okType: [@bs.string] [
        | `default
        | `dashed
        | `primary
        | `ghost
        | `danger
    ]=?,
    ~okButtonProps: Antd_Button.NativeProps.t=?,
    ~cancelButtonProps:  Antd_Button.NativeProps.t=?,
    ~style: ReactDOMRe.Style.t=?,
    ~title: element=?,
    ~visible: bool=?,
    ~width: Width.t=?,
    ~wrapClassName: string=?,
    ~zIndex: int=?,
    ~onCancel: ReactEvent.Mouse.t => Js.Promise.t(unit)=?, // TODO TS says ...any[],
    ~onOk: ReactEvent.Mouse.t => Js.Promise.t(unit)=?, // TODO TS says ...any[],
    ~children: element=?,
    unit
) => element = "antd/lib/modal";

module AutoFocusButton = {
    type t = Js.null(string);

    let null = Js.Null.empty;
    let ok = Js.Null.return("ok");
    let cancel = Js.Null.return("cancel");
};




module Config = {
    type t;

    [@bs.obj] external make: (
        ~autoFocusButton: AutoFocusButton.t=?,
        ~cancelText: element=?,
        ~centered: bool=?,
        ~className: string=?,
        ~content: element=?,
        ~icon: element=?,
        // iconType deprecated
        ~keyboard: bool=?,
        ~mask: bool=?,
        ~maskClosable: bool=?,
        ~okText: element=?,
        ~okType: [@bs.string] [
            | `default
            | `dashed
            | `primary
            | `ghost
            | `danger
        ]=?,
        ~okButtonProps: Antd_Button.NativeProps.t=?,
        ~cancelButtonProps:  Antd_Button.NativeProps.t=?,
        ~title: element=?,
        ~width: Width.t=?,
        ~zIndex: int=?,
        ~onCancel: ReactEvent.Mouse.t => Js.Promise.t(unit)=?, // TODO TS says ...any[],
        ~onOk: ReactEvent.Mouse.t => Js.Promise.t(unit)=?, // TODO TS says ...any[],
        ~okCancel: bool=?,
        ~_type: string=?, // TODO test
        ~style: ReactDOMRe.Style.t=?,
        ~iconClassName: string=?,
        ~maskStyle: ReactDOMRe.Style.t=?,
        ~width: string=?,
        unit
    ) => t = ""
};

module Dialog = {
    type t;

    [@bs.send] external update: (t, Config.t) => unit = "update";
    [@bs.send] external destroy: t => unit = "destroy";

};

[@bs.module "antd/lib/modal"] external info: Config.t => Dialog.t = "info";   
[@bs.module "antd/lib/modal"] external success: Config.t => Dialog.t = "success";   
[@bs.module "antd/lib/modal"] external error: Config.t => Dialog.t = "error";   
[@bs.module "antd/lib/modal"] external warning: Config.t => Dialog.t = "warning";   
[@bs.module "antd/lib/modal"] external confirm: Config.t => Dialog.t = "confirm"; 

[@bs.module "antd/lib/modal"] external destroyAll: unit => unit = "destroyAll";   