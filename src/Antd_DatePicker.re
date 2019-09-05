open React;
open MomentRe;

type t;

[@bs.send] external blur: t => unit = "blur";
[@bs.send] external focus: t => unit = "focus";

module Mode = {
  type t = string;
  [@bs.inline]
  let time = "time";
  [@bs.inline]
  let date = "date";
  [@bs.inline]
  let month = "month";
  [@bs.inline]
  let year = "year";
};

module ShowTime = {
  type t;
  external bool: bool => t = "%identity";
  external timePickerProps: Antd_TimePicker.makeProps => t = "%identity";
};

module Locale = {
  type t('a) = Js.t({..}) as 'a; // TODO
};

// using Js.null is important here, option/nullable won't work

// used null even if TS says undefined, undefined is a lie

[@react.component] [@bs.module "antd/lib/date-picker"]
// ***** BEGIN PICKER *****
external make:
  (
    ~id: string=?,
    ~prefixCls: string=?,
    ~inputPrefixCls: string=?,
    ~format: array(string)=?, // non-array variant skipped
    ~disabled: bool=?,
    ~allowClear: bool=?,
    ~className: string=?,
    ~suffixIcon: element=?,
    ~style: ReactDOMRe.Style.t=?,
    ~popupStyle: ReactDOMRe.Style.t=?,
    ~dropdownClassName: string=?,
    ~locale: Js.t({..})=?,
    ~size: [@bs.string] [ | `large | `default | `small]=?,
    ~getCalendarContainer: Dom.element => Dom.htmlElement=?,
    ~_open: bool=?,
    ~onOpenChange: bool => unit=?,
    ~disabledDate: Moment.t => bool=?, // not null
    ~renderExtraFooter: Mode.t => element=?,
    ~dateRender: (~current: Moment.t, ~today: Moment.t) => element=?, // not null
    // ***** END PICKER *****
    // ***** BEGIN SINGLE PICKER *****
    ~value: Js.null(Moment.t)=?,
    ~defaultValue: Js.null(Moment.t)=?,
    ~defaultPickerValue: Js.null(Moment.t)=?,
    ~onChange: (Js.null(Moment.t), string) => unit=?,
    // ***** END SINGLE PICKER *****
    // ***** BEGIN DATE PICKER *****
    // className
    ~showTime: ShowTime.t=?,
    ~showToday: bool=?,
    // open
    ~disabledTime: Js.null(Moment.t) =>
                   {
                     .
                     "disabledHours": option(unit => array(int)),
                     "disabledMinutes": option(unit => array(int)),
                     "disabledSeconds": option(unit => array(int)),
                   }
                     =?,
    // onOpenChange
    ~onPanelChange: (Js.null(Moment.t), Js.null(Mode.t)) => unit=?,
    ~onOk: Moment.t => unit=?, // not null
    ~placeholder: string=?,
    ~mode: Mode.t=?,
    // ***** END DATE PICKER *****
    ~ref: Ref.t(Js.nullable(t))=?,
    unit
  ) =>
  element =
  "default";

module MonthPicker = {
  type t;

  [@bs.send] external blur: t => unit = "blur";
  [@bs.send] external focus: t => unit = "focus";

  [@react.component] [@bs.module "antd/lib/date-picker"] [@bs.scope "default"]
  // ***** BEGIN PICKER *****
  external make:
    (
      ~id: string=?,
      ~prefixCls: string=?,
      ~inputPrefixCls: string=?,
      ~format: array(string)=?, // non-array variant skipped
      ~disabled: bool=?,
      ~allowClear: bool=?,
      ~className: string=?,
      ~suffixIcon: element=?,
      ~style: ReactDOMRe.Style.t=?,
      ~popupStyle: ReactDOMRe.Style.t=?,
      ~dropdownClassName: string=?,
      ~locale: Js.t({..})=?,
      ~size: [@bs.string] [ | `large | `default | `small]=?,
      ~getCalendarContainer: Dom.element => Dom.htmlElement=?,
      ~_open: bool=?,
      ~onOpenChange: bool => unit=?,
      ~disabledDate: Moment.t => bool=?, // not null
      ~renderExtraFooter: unit => element=?, // ***** OVERRIDEN *****
      // ~dateRender: (~current: Moment.t, ~today: Moment.t) => element=?, // ***** OVERRIDEN REMOVED ****
      // ***** END PICKER *****
      // ***** BEGIN SINGLE PICKER *****
      ~value: Js.null(Moment.t)=?,
      ~defaultValue: Js.null(Moment.t)=?,
      ~defaultPickerValue: Js.null(Moment.t)=?,
      ~onChange: (Js.null(Moment.t), string) => unit=?,
      // ***** END SINGLE PICKER *****
      // ***** BEGIN MONTH PICKER *****
      ~placeholder: string=?,
      // ***** END MONTH PICKER *****
      // ***** BEGIN MONTH PICKER FROM WEBSITE *****
      ~autoFocus: bool=?,
      ~monthCellContentRender: (Moment.t, Locale.t('todo)) => element=?,
      // ***** END MONTH PICKER FROM WEBSITE *****
      ~ref: Ref.t(Js.nullable(t))=?,
      unit
    ) =>
    element =
    "MonthPicker";
};

module WeekPicker = {
  type t;

  [@bs.send] external blur: t => unit = "blur";
  [@bs.send] external focus: t => unit = "focus";

  [@react.component] [@bs.module "antd/lib/date-picker"] [@bs.scope "default"]
  // begin common
  // ***** BEGIN PICKER *****
  external make:
    (
      ~id: string=?,
      ~prefixCls: string=?,
      ~inputPrefixCls: string=?,
      ~format: array(string)=?, // non-array variant skipped
      ~disabled: bool=?,
      ~allowClear: bool=?,
      ~className: string=?,
      ~suffixIcon: element=?,
      ~style: ReactDOMRe.Style.t=?,
      ~popupStyle: ReactDOMRe.Style.t=?,
      ~dropdownClassName: string=?,
      ~locale: Js.t({..})=?, // TODO lowest priority
      ~size: [@bs.string] [ | `large | `default | `small]=?,
      ~getCalendarContainer: Dom.element => Dom.htmlElement=?,
      ~_open: bool=?,
      ~onOpenChange: bool => unit=?,
      ~disabledDate: Moment.t => bool=?, // not null
      ~renderExtraFooter: Mode.t => element=?,
      ~dateRender: Moment.t => element=?, // ***** OVERRIDEN
      // ***** END PICKER *****
      // ***** BEGIN SINGLE PICKER *****
      ~value: Js.null(Moment.t)=?,
      ~defaultValue: Js.null(Moment.t)=?,
      ~defaultPickerValue: Js.null(Moment.t)=?,
      ~onChange: (Js.null(Moment.t), string) => unit=?,
      // ***** END SINGLE PICKER *****
      // ***** BEGIN WEEK FROM WEBSITE *****
      ~placeholder: string=?,
      // ***** END WEEK FROM WEBSITE *****
      ~ref: Ref.t(Js.nullable(t))=?,
      unit
    ) =>
    element =
    "WeekPicker";
};

module RangePicker = {
  module Partial = {
    type t = string;
    [@bs.inline]
    let start = "start";
    [@bs.inline]
    let end_ = "end";
  };

  module Mode = {
    type t = string;
    [@bs.inline]
    let date = "date";
    [@bs.inline]
    let month = "month";
    [@bs.inline]
    let year = "year";
    [@bs.inline]
    let decade = "decade";
  };

  // can be undef, m, [m, m]...
  type rangeDisableTimeCurrent;

  [@react.component] [@bs.module "antd/lib/date-picker"] [@bs.scope "default"]
  // ***** BEGIN PICKER *****
  external make:
    (
      ~id: string=?,
      ~prefixCls: string=?,
      ~inputPrefixCls: string=?,
      ~format: array(string)=?, // non-array variant skipped
      ~disabled: bool=?,
      ~allowClear: bool=?,
      ~className: string=?,
      ~suffixIcon: element=?,
      ~style: ReactDOMRe.Style.t=?,
      ~popupStyle: ReactDOMRe.Style.t=?,
      ~dropdownClassName: string=?,
      ~locale: Js.t({..})=?, // TODO lowest priority
      ~size: [@bs.string] [ | `large | `default | `small]=?,
      ~getCalendarContainer: Dom.element => Dom.htmlElement=?,
      ~_open: bool=?,
      ~onOpenChange: bool => unit=?,
      ~disabledDate: Moment.t => bool=?, // not null
      ~renderExtraFooter: unit => element=?, // ***** OVERRIDEN *****
      ~dateRender: (~current: Moment.t, ~today: Moment.t) => element=?, // not null
      // ***** END PICKER *****
      // ***** BEGIN RANGE ****
      // ~className: string=?,
      ~value: (Js.null(Moment.t), Js.null(Moment.t))=?,
      ~defaultValue: (Js.null(Moment.t), Js.null(Moment.t))=?,
      ~defaultPickerValue: (Js.null(Moment.t), Js.null(Moment.t))=?,
      ~onChange: (array(Js.null(Moment.t)), (string, string)) => unit=?, // arr of nulls
      ~onCalendarChange: array(Moment.t) => unit=?, // arr of not nulls
      ~onOk: array(Js.null(Moment.t)) => unit=?,
      ~showTime: ShowTime.t=?,
      ~ranges: Js.Dict.t(unit => (Js.null(Moment.t), Js.null(Moment.t)))=?,
      ~placeholder: (string, string)=?,
      ~mode: (Mode.t, Mode.t)=?,
      ~separator: element=?,
      ~onPanelChange: (array(Js.null(Moment.t)), array(Js.null(Mode.t))) =>
                      unit
                        =?,
      // ***** END RANGE *****
      // ***** BEGIN RANGE FROM WEBSITE *****
      ~disabledTime: (rangeDisableTimeCurrent, Partial.t) =>
                     {
                       .
                       "disabledHours": option(unit => array(int)),
                       "disabledMinutes": option(unit => array(int)),
                       "disabledSeconds": option(unit => array(int)),
                     }
                       =?,
      // ***** END RANGE FROM WEBSITE *****
      ~ref: Ref.t(Js.nullable(t))=?,
      ~autoFocus: bool=?,
      unit
    ) =>
    element =
    "RangePicker";
};