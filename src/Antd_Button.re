open React;

module Loading = {
  type t;
  external bool: bool => t = "%identity";
  
  [@bs.obj] external make: (
    ~delay: float
  ) => t = "";
};

module NativeProps = {
  type t;

  [@bs.obj]
  external make:
    (
      ~htmlType: [@bs.string] [ | `submit | `button | `reset]=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~icon: string=?,
      ~shape: [@bs.string] [
                | `circle
                | [@bs.as "circle-outline"] `circleOutline
                | `round
              ]
                =?,
      ~size: [@bs.string] [ | `large | `default | `small]=?,
      ~loading: Loading.t=?,
      ~prefixCls: string=?,
      ~className: string=?,
      ~ghost: bool=?,
      ~block: bool=?,
      ~children: element=?,
      unit
    ) =>
    t =
    "";
};

// module Shape = {
//     type t = string;
//     [@bs.inline] let round = "round";
//     [@bs.inline] let circle = "circle";
//     [@bs.inline] let circleOutline = "circle-outline";
// };

// module Size = {
//     type t = string;
//     [@bs.inline] let small = "small";
//     [@bs.inline] let default = "default";
//     [@bs.inline] let large = "large";
// };

// module Type = {
//     type t = string;
//     [@bs.inline] let primary = "primary";
//     [@bs.inline] let ghost = "ghost";
//     [@bs.inline] let dashed = "dashed";
//     [@bs.inline] let danger = "danger";
// };

[@react.component] [@bs.module]
external make:
  (
    ~disabled: bool=?,
    ~ghost: bool=?,
    ~href: string=?,
    ~htmlType: string=?,
    ~icon: Antd_Icon.Type.t=?,
    ~loading: Loading.t=?,
    ~shape: [@bs.string] [
              | `circle
              | [@bs.as "circle-outline"] `circleOutline
              | `round
            ]
              =?,
    ~size: [@bs.string] [ | `large | `default | `small]=?,
    ~target: string=?,
    ~_type: [@bs.string] [ | `primary | `ghost | `dashed | `danger]=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~block: bool=?,
    ~children: element=?,
    ~className: string=?,
    ~prefixCls: string=?,
    unit
  ) =>
  element =
  "antd/lib/button";
