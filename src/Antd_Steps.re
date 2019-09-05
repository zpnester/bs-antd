open React;

module ProgressDot = {
  type t;

  external bool: bool => t = "%identity";

  external make:
    (
      (
        element,
        {
          .
          "index": int,
          "status": string, // enum ignored
          "title": option(string),
          "description": option(string),
        }
      ) =>
      element
    ) =>
    t =
    "%identity";
};

[@react.component] [@bs.module "antd/es/steps"]
external make:
  (
    ~className: string=?,
    ~current: int=?,
    ~direction: [@bs.string] [ | `horizontal | `vertical]=?,
    ~labelPlacement: [@bs.string] [ | `horizontal | `vertical]=?,
    ~progressDot: ProgressDot.t=?,
    ~size: [@bs.string] [ | `default | `small]=?,
    ~status: [@bs.string] [ | `wait | `process | `finish | `error]=?,
    ~initial: int=?,
    ~style: ReactDOMRe.Style.t=?,
    ~iconPrefix: string=?, // not element // TODO check
    ~children: element=?,
    unit
  ) =>
  element =
  "default";

module Step = {
  [@react.component] [@bs.module "antd/es/steps"] [@bs.scope "default"]
  external make:
    (
      ~description: element=?,
      ~icon: element=?,
      ~status: [@bs.string] [ | `wait | `process | `finish | `error]=?,
      ~title: element=?,
      ~className: string=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~style: ReactDOMRe.Style.t=?,
      // ~children: element=?, // not needed
      unit
    ) =>
    element =
    "Step";
};