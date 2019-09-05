open React;
open MomentRe;

module Formatter = {
  type t;

  let false_: t = [%raw {| (false) |}];
  let number: t = [%raw {| ("number") |}];
  let countdown: t = [%raw {| ("countdown") |}];

  // FormatConfig skipped
  // value number variant skipped
  external make: (string => element) => t = "%identity";
};

[@react.component] [@bs.module "antd/lib/statistic"]
// ***** BEGIN FORMAT *****
external make:
  (
    ~formatter: Formatter.t=?,
    ~decimalSeparator: string=?,
    ~groupSeparator: string=?,
    ~precision: int=?,
    ~prefixCls: string=?,
    // ***** END FORMAT *****
    // ***** BEGIN STATISTIC *****
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~value: string=?,
    ~valueStyle: ReactDOMRe.Style.t=?,
    ~valueRender: element => element=?,
    ~title: element=?,
    ~prefix: element=?,
    ~suffix: element=?,
    // ***** END STATISTIC *****
    unit
  ) =>
  element =
  "default";

module Countdown = {
  [@react.component] [@bs.module "antd/lib/statistic/Countdown"]
  // ***** BEGIN FORMAT *****
  external make:
    (
      ~formatter: Formatter.t=?,
      ~decimalSeparator: string=?,
      ~groupSeparator: string=?,
      ~precision: int=?,
      ~prefixCls: string=?,
      // ***** END FORMAT *****
      // ***** BEGIN STATISTIC *****
      ~className: string=?,
      ~style: ReactDOMRe.Style.t=?,
      // ~value: string=?,
      ~valueStyle: ReactDOMRe.Style.t=?,
      ~valueRender: element => element=?,
      ~title: element=?,
      ~prefix: element=?,
      ~suffix: element=?,
      // ***** END STATISTIC *****
      // ***** BEGIN COUNTDOWN *****
      ~value: Moment.t=?,
      ~format: string=?,
      ~onFinish: unit => unit=?,
      // ***** END COUNTDOWN *****
      unit
    ) =>
    element =
    "default";
};