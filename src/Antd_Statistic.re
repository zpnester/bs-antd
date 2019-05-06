open React;
open MomentRe;

type formatConfig = {
  .
  // "formatter" // no need to include "self"?
  "decimalSeparator": option(string),
  "groupSeparator": option(string),
  "precision": option(float),
  "prefixCls": option(string),
};

module Value = {
  type t;
  external string: string => t = "%identity";
  external number: float => t = "%identity";
};

module Formatter = {
  type t;

  let false_: t = [%raw {| (false) |}];
  let number: t = [%raw {| ("number") |}];
  let countdown: t = [%raw {| ("countdown") |}];
  // TODo rework, input value not OK
  // TODO test
  external make: ((Value.t, formatConfig) => element) => t = "%identity";
};

[@react.component] [@bs.module]
external make:
  (
    ~decimalSeparator: string=?,
    ~formatter: Formatter.t=?,
    ~groupSeparator: string=?,
    ~precision: int=?,
    ~prefix: element=?,
    ~suffix: element=?,
    ~title: element=?,
    ~value: Value.t=?, // TODO
    ~valueStyle: ReactDOMRe.Style.t=?,
    ~style: ReactDOMRe.Style.t=?,
    ~prefixCls: string=?,
    ~className: string=?,
    unit
  ) =>
  element =
  "antd/lib/statistic";

module Countdown = {
  module Value = {
    type t;
    external string: string => t = "%identity";
    external moment: Moment.t => t = "%identity";
  };

  [@react.component] [@bs.module]
  // copy paste (except value)
  external make:
    (
      ~decimalSeparator: string=?,
      ~formatter: Formatter.t=?,
      ~groupSeparator: string=?,
      ~precision: int=?, // TODO ensure OK
      ~prefix: element=?,
      ~suffix: element=?,
      ~title: element=?,
      ~valueStyle: ReactDOMRe.Style.t=?,
      ~style: ReactDOMRe.Style.t=?,
      ~prefixCls: string=?,
      ~className: string=?,
      // end of copy paste
      ~format: string=?,
      ~onFinish: unit => unit=?,
      ~value: Value.t=?, // TODO
      unit
    ) =>
    element =
    "antd/lib/statistic/Countdown";
};