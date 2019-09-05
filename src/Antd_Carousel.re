open React;

type t;

[@bs.send] external goTo: (t, int, bool) => unit = "goTo";
[@bs.send] external next: t => unit = "next";
[@bs.send] external prev: t => unit = "prev";


[@react.component] [@bs.module "antd/es/carousel"]
external make:
  (
    ~ref: Ref.t(Js.Nullable.t(t))=?,
    ~afterChange: int => unit=?,
    ~autoplay: bool=?,
    ~beforeChange: (int, int) => unit=?,
    ~dots: bool=?,
    ~easing: string=?,
    ~effect: [@bs.string] [ | `scrollx | `fade]=?,
    ~vertical: bool=?,
    ~children: element=?,
    unit
  ) =>
  element =
  "default";