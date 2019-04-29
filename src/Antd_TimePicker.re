open React;
open MomentRe;


// bsc -bs-re-out ./lib/bs/src/TimePicker.cmi


type t;

[@bs.send] external blur: t => unit = "blur";
[@bs.send] external focus: t => unit = "focus";

type addon;



type props = {
  .
  "ref": option(Ref.t(Js.nullable(t))),
  "_open": option(bool),
  "addon": option(addon),
  "allowClear": option(bool),
  "autoFocus": option(bool),
  "className": option(string),
  "clearIcon": option(React.element),
  "clearText": option(string),
  "defaultOpenValue": option(MomentRe.Moment.t),
  "defaultValue": option(MomentRe.Moment.t),
  "disabled": option(bool),
  "disabledHours": option(unit => array(int)),
  "disabledMinutes": option(int => array(int)),
  "disabledSeconds":
    option((~selectedHour: int, ~selectedMinute: int) => array(int)),
  "format": option(string),
  "getPopupContainer": option(Dom.element => Dom.htmlElement),
  "hideDisabledOptions": option(bool),
  "hourStep": option(int),
  "inputReadOnly": option(bool),
  "minuteStep": option(int),
  "onChange": option((MomentRe.Moment.t, string) => unit),
  "onOpenChange": option(bool => unit),
  "placeholder": option(string),
  "popupClassName": option(string),
  "popupStyle": option(ReactDOMRe.Style.t),
  "secondStep": option(int),
  "style": option(ReactDOMRe.Style.t),
  "suffixIcon": option(React.element),
  "use12Hours": option(bool),
  "value": option(MomentRe.Moment.t),
};

[@bs.obj]
external makeProps:
  (
    ~ref: Ref.t(Js.nullable(t))=?,
    ~className: string=?,
    ~addon: addon=?,
    ~allowClear: bool=?,
    ~autoFocus: bool=?,
    ~clearText: string=?,
    ~defaultOpenValue: Js.null(MomentRe.Moment.t)=?, // TODO test
    ~defaultValue: Js.null(MomentRe.Moment.t)=?, // TODO test
    ~disabled: bool=?,
    ~disabledHours: unit => array(int)=?,
    ~disabledMinutes: Js.null(int) => array(int)=?,
    ~disabledSeconds: (~selectedHour: Js.null(int), ~selectedMinute: Js.null(int)) => array(int)
                        =?,
    ~style: ReactDOMRe.Style.t=?,
    ~format: string=?,
    ~getPopupContainer: Dom.element => Dom.htmlElement=?,
    ~hideDisabledOptions: bool=?,
    ~hourStep: int=?,
    ~inputReadOnly: bool=?,
    ~minuteStep: int=?,
    ~_open: bool=?,
    ~placeholder: string=?,
    ~popupClassName: string=?,
    ~popupStyle: ReactDOMRe.Style.t=?,
    ~secondStep: int=?,
    ~suffixIcon: React.element=?,
    ~clearIcon: React.element=?,
    ~use12Hours: bool=?,
    ~value: MomentRe.Moment.t=?,
    ~onChange: (Js.null(MomentRe.Moment.t), string) => unit=?,
    ~onOpenChange: bool => unit=?,
    ~key: string=?,
    unit
  ) =>
  props =
  "";
  
// TODO using default is fragile, antd change exports sometimes
[@bs.module  "antd/lib/time-picker"]
external make: component(props) = "default";

// [@bs.module]
// external make: component(props) = "antd/lib/time-picker";



// [@react.component] [@bs.module]
// external make:
//   (
//     ~className: string=?,
//     ~addon: addon=?, // TODO
//     ~allowClear: bool=?,
//     ~autoFocus: bool=?,
//     ~clearText: string=?,
//     ~defaultOpenValue: Moment.t=?,
//     ~defaultValue: Moment.t=?, // TODO why array variant in TS, not in website
//     ~disabled: bool=?,
//     ~disabledHours: unit => array(int)=?,
//     ~disabledMinutes: int => array(int)=?,
//     ~disabledSeconds: (~selectedHour: int, ~selectedMinute: int) => array(int)
//                         =?,
//     ~style: ReactDOMRe.Style.t=?,
//     ~format: string=?,
//     ~getPopupContainer: Dom.element => Dom.htmlElement=?,
//     ~hideDisabledOptions: bool=?,
//     ~hourStep: int=?, // TODO int OK?
//     ~inputReadOnly: bool=?,
//     ~minuteStep: int=?, // TODO int OK
//     ~_open: bool=?,
//     ~placeholder: string=?,
//     ~popupClassName: string=?,
//     ~popupStyle: ReactDOMRe.Style.t=?,
//     ~secondStep: int=?, // TODO int OK?
//     ~suffixIcon: element=?,
//     ~clearIcon: element=?,
//     ~use12Hours: bool=?,
//     ~value: Moment.t=?, // TODO confirm null/option not required
//     ~onChange: (Moment.t, string) => unit=?,
//     ~onOpenChange: bool => unit=?,
//     unit
//   ) =>
//   element =
//   "antd/lib/time-picker";
