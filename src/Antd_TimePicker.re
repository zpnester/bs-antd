open React;
open MomentRe;

type t;

[@bs.send] external blur: t => unit = "blur";
[@bs.send] external focus: t => unit = "focus";

type addon;

module Size = {
  type t = string;
  [@bs.inline]
  let large = "large";
  [@bs.inline]
  let default = "default";
  [@bs.inline]
  let small = "small";
};

module AmPm = {
  type t = string;
  [@bs.inline]
  let am = "AM";
  [@bs.inline]
  let pm = "PM";
};

// null is required for value/defaultValue, option/nullable won't work

[@bs.deriving abstract]
type makeProps = {
  // ***** BEGIN TIME PICKER *****
  [@bs.optional]
  className: string,
  [@bs.optional]
  size: Size.t,
  [@bs.optional]
  value: Js.null(MomentRe.Moment.t),
  [@bs.optional]
  defaultValue: Js.null(MomentRe.Moment.t),
  [@bs.optional] [@bs.as "open"]
  open_: bool,
  [@bs.optional]
  format: string,
  [@bs.optional]
  onChange: (Js.null(MomentRe.Moment.t), string) => unit,
  [@bs.optional]
  onOpenChange: bool => unit,
  [@bs.optional]
  onAmPmChange: AmPm.t => unit,
  [@bs.optional]
  disabled: bool,
  [@bs.optional]
  placeholder: string,
  [@bs.optional]
  prefixCls: string,
  [@bs.optional]
  hideDisabledOptions: bool,
  [@bs.optional]
  disabledHours: unit => array(int),
  [@bs.optional]
  disabledMinutes: Js.null(int) => array(int),
  [@bs.optional]
  disabledSeconds:
    (~selectedHour: Js.null(int), ~selectedMinute: Js.null(int)) =>
    array(int),
  [@bs.optional]
  style: ReactDOMRe.Style.t,
  [@bs.optional]
  getPopupContainer: Dom.element => Dom.htmlElement,
  [@bs.optional]
  addon,
  [@bs.optional]
  use12Hours: bool,
  [@bs.optional]
  focusOnOpen: bool,
  [@bs.optional]
  hourStep: int,
  [@bs.optional]
  minuteStep: int,
  [@bs.optional]
  secondStep: int,
  [@bs.optional]
  allowEmpty: bool,
  [@bs.optional]
  allowClear: bool,
  [@bs.optional]
  inputReadOnly: bool,
  [@bs.optional]
  clearText: string,
  [@bs.optional]
  defaultOpenValue: Js.null(MomentRe.Moment.t),
  [@bs.optional]
  popupClassName: string,
  [@bs.optional]
  popupStyle: ReactDOMRe.Style.t,
  [@bs.optional]
  suffixIcon: React.element,
  [@bs.optional]
  clearIcon: React.element,
  [@bs.optional]
  locale: {. "placeholder": string},
  // ***** END TIME PICKER *****
  // ***** BEGIN TIME PICKER FROM WEBSITE *****
  [@bs.optional]
  autoFocus: bool,
  // ***** END TIME PICKER FROM WEBSITE *****
  [@bs.optional]
  key: string,
};

[@bs.module "antd/es/time-picker"]
external make: component(makeProps) = "default";