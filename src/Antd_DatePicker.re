open React;
open MomentRe;

type t;

[@bs.send] external blur: t => unit = "blur";
[@bs.send] external focus: t => unit = "focus";

module Mode = {
  type t;
  let time: t = [%raw {| ("time") |}];
  let date: t = [%raw {| ("date") |}];
  let month: t = [%raw {| ("month") |}];
  let year: t = [%raw {| ("year") |}];
};



module ShowTime = {
  type t;
  external bool: bool => t = "%identity";
  external timePickerProps: Antd_TimePicker.makeProps => t = "%identity";

};

// using Js.null is important here, option/nullable won't work

[@react.component] [@bs.module]
// begin common
external make:
  (
    ~ref: Ref.t(Js.nullable(t))=?,
    ~allowClear: bool=?,
    ~autoFocus: bool=?,
    ~className: string=?,
    ~dateRender: (~current: Moment.t, ~today: Moment.t) => element=?, // not null
    ~disabled: bool=?,
    ~disabledDate: Moment.t => bool=?, // not null
    ~dropdownClassName: string=?,
    ~getCalendarContainer: Dom.element => Dom.htmlElement=?,
    ~locale: Antd_LocaleProvider.locale=?,
    ~mode: Mode.t=?,
    ~_open: bool=?,
    // TODO placeholder
    ~popupStyle: ReactDOMRe.Style.t=?,
    ~size: [@bs.string] [ | `large | `default | `small]=?,
    ~suffixIcon: element=?,
    ~style: ReactDOMRe.Style.t=?,
    ~onOpenChange: bool => unit=?,
    ~onPanelChange: (Moment.t, Mode.t) => unit=?, // not null looks OK
    // end common
    ~defaultValue: Js.null(Moment.t)=?,
    ~defaultPickerValue: Js.null(Moment.t)=?,
    ~disabledTime: option(Moment.t) => // option, not null
                   {
                     .
                     "disabledHours": option(unit => array(int)),
                     "disabledMinutes": option(unit => array(int)),
                     "disabledSeconds": option(unit => array(int)),
                   }
                     =?,
    ~format: array(string)=?, // non-array variant skipped
    ~renderExtraFooter: unit => element=?, // TODO recheck type, website differs from TS
    ~showTime: ShowTime.t=?,
    ~showToday: bool=?,
    ~value: Js.null(Moment.t)=?,
    ~onChange: (Js.null(Moment.t), string) => unit=?,
    ~onOk: Moment.t => unit=?, // not null
    unit
  ) =>
  element =
  "antd/lib/date-picker";

module MonthPicker = {
  type t;
  // same methods, duplicate just in case

  [@bs.send] external blur: t => unit = "blur";
  [@bs.send] external focus: t => unit = "focus";

  [@react.component] [@bs.module "antd/lib/date-picker"]
  // begin common
  external make:
    (
      ~ref: Ref.t(Js.nullable(t))=?,
      ~allowClear: bool=?,
      ~autoFocus: bool=?,
      ~className: string=?,
      ~dateRender: (~current: Moment.t, ~today: Moment.t) => element=?, // can be removed from month?
      ~disabled: bool=?,
      ~disabledDate: Moment.t => bool=?,
      ~dropdownClassName: string=?,
      ~getCalendarContainer: Dom.element => Dom.htmlElement=?,
      ~locale: Antd_LocaleProvider.locale=?,
      ~mode: Mode.t=?, // polyvar not used intentionally
      ~_open: bool=?,
      ~popupStyle: ReactDOMRe.Style.t=?,
      ~size: [@bs.string] [ | `large | `default | `small]=?,
      ~suffixIcon: element=?,
      ~style: ReactDOMRe.Style.t=?,
      ~onOpenChange: bool => unit=?,
      ~onPanelChange: (Moment.t, Mode.t) => unit=?, // can be removed from month?
      // end common
      ~placeholder: string=?,
      ~defaultValue: Js.null(Moment.t)=?,
      ~defaultPickerValue: Js.null(Moment.t)=?,
      ~format: string=?,
      ~monthCellContentRender: (Moment.t, Antd_LocaleProvider.locale) => element=?, // not null // todo check locale not null
      ~renderExtraFooter: unit => element=?,
      ~value: Js.null(Moment.t)=?,
      ~onChange: (Js.null(Moment.t), string) => unit=?,
      unit
    ) =>
    element =
    "MonthPicker";
};

module WeekPicker = {
  type t;
  // same methods, duplicate just in case

  [@bs.send] external blur: t => unit = "blur";
  [@bs.send] external focus: t => unit = "focus";

  [@react.component] [@bs.module "antd/lib/date-picker"]
  // begin common
  external make:
    (
      ~ref: Ref.t(Js.nullable(t))=?,
      ~allowClear: bool=?,
      ~autoFocus: bool=?,
      ~className: string=?,
      ~dateRender: Moment.t => element=?, // no today in week
      ~disabled: bool=?,
      ~disabledDate: Moment.t => bool=?, // not null
      ~dropdownClassName: string=?,
      ~getCalendarContainer: Dom.element => Dom.htmlElement=?,
      ~locale: Antd_LocaleProvider.locale=?,
      ~mode: Mode.t=?,
      ~_open: bool=?,
      ~popupStyle: ReactDOMRe.Style.t=?,
      ~size: [@bs.string] [ | `large | `default | `small]=?,
      ~suffixIcon: element=?,
      ~style: ReactDOMRe.Style.t=?,
      ~onOpenChange: bool => unit=?,
      ~onPanelChange: (Moment.t, Mode.t) => unit=?, // can be removed from week?
      // end common
      ~defaultValue: Js.null(Moment.t)=?,
      ~defaultPickerValue: Js.null(Moment.t)=?,
      ~format: string=?,
      ~value: Js.null(Moment.t)=?,
      ~onChange: (Js.null(Moment.t), string) => unit=?,
      ~renderExtraFooter: Mode.t => element=?,
      unit
    ) =>
    element =
    "WeekPicker";
};



module RangePicker = {


  module Partial = {
    type t = string;
    [@bs.inline] let start = "start";
    [@bs.inline] let end_ = "end";

  };

  // docs are lying, made it abstract (can be undef, m, [m, m]...)
  type rangeDisableTimeCurrent;

  [@react.component] [@bs.module "antd/lib/date-picker"]
  external make:
    // begin common
    (
      ~ref: Ref.t(Js.nullable(t))=?,
      ~allowClear: bool=?,
      ~autoFocus: bool=?,
      ~className: string=?,
      ~dateRender: (~current: Moment.t, ~today: Moment.t) => element=?, // not null
      ~disabled: bool=?,
      ~disabledDate: Moment.t => bool=?, // not null
      ~dropdownClassName: string=?,
      ~getCalendarContainer: Dom.element => Dom.htmlElement=?,
      ~locale: Antd_LocaleProvider.locale=?,
      ~mode: Mode.t=?,
      ~_open: bool=?,
      // TODO placeholder
      ~popupStyle: ReactDOMRe.Style.t=?,
      ~size: [@bs.string] [ | `large | `default | `small]=?,
      ~suffixIcon: element=?,
      ~style: ReactDOMRe.Style.t=?,
      ~onOpenChange: bool => unit=?,
      ~onPanelChange: (Moment.t, Mode.t) => unit=?, // not null looks OK
      // end common
      ~defaultValue: (Js.null(Moment.t), Js.null(Moment.t))=?,
      ~defaultPickerValue: (Js.null(Moment.t), Js.null(Moment.t))=?,
      ~disabledTime: (rangeDisableTimeCurrent, Partial.t) => // option, not null; not tuple/array
                   {
                     .
                     "disabledHours": option(unit => array(int)),
                     "disabledMinutes": option(unit => array(int)),
                     "disabledSeconds": option(unit => array(int)),
                   }=?,
      ~format: array(string)=?,
      ~ranges: Js.Dict.t(unit => (Js.null(Moment.t), Js.null(Moment.t)))=?,
      ~renderExtraFooter: unit => element=?,
      ~separator: element=?,
      ~showTime: ShowTime.t=?, // TODO test
      ~value: (Js.null(Moment.t), Js.null(Moment.t))=?,
      // removed second param
      ~onCalendarChange: (array(Js.null(Moment.t))) => unit=?,
      ~onChange: (array(Js.null(Moment.t)), (string, string)) => unit=?,
      ~onOk: array(Js.null(Moment.t)) => unit=?,
      unit
    ) =>
    element =
    "RangePicker";
};
