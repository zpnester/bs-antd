open React;

module StrokeColor = {
  type t;

  external string: string => t = "%identity";
  // TODO test
  external makeFromTo:
    {
      .
      "direction": string,
      "from": string,
      "to": string,
    } =>
    t =
    "%identity";

  // TODO test
  // ProgressGradient (StringGradients)
  external makeUnsafe: {.. "direction": string} => t = "%identity";
};

[@react.component] [@bs.module]
external make:
  (
    ~_type: [@bs.string] [ | `line | `circle | `dashboard]=?,
    ~format: (~percent: int, ~successPercent: int) => element=?,
    ~percent: int=?,
    ~showInfo: bool=?,
    ~status: [@bs.string] [
               | `normal
               | [@bs.as "exception"] `exception_
               | `active
               | `success
             ]
               =?,
    // TODO test
    ~strokeLinecap: [@bs.string] [ | `round | `square]=?,
    ~strokeColor: StrokeColor.t=?,
    ~successPercent: int=?,
    ~strokeWidth: float=?,
    ~trailColor: string=?,
    ~width: float=?,
    ~style: ReactDOMRe.Style.t=?,
    ~gapDegree: float=?,
    ~gapPosition: [@bs.string] [ | `top | `bottom | `left | `right]=?,
    ~size: [@bs.string] [ | `default | `small]=?,
    ~prefixCls: string=?,
    ~className: string=?,
    unit
  ) =>
  element =
  "antd/lib/progress";