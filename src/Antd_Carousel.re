open React;

type t;

    [@bs.send] external goTo: (t, int, bool) => unit = "goTo";
    [@bs.send] external next: t => unit = "next";
    [@bs.send] external prev: t => unit = "prev";

// module Effect = {
//     type t = string;
//     [@bs.inline] let scrollx = "scrollx";
//     [@bs.inline] let fade = "fade";
// };


[@react.component] [@bs.module]
external make: (
    ~ref: Ref.t(Js.Nullable.t(t))=?,
    ~afterChange: int => unit=?,
    ~autoplay: bool=?,
    ~beforeChange: (int, int) => unit=?,
    ~dots: bool=?,
    ~easing: string=?,
    ~effect: [@bs.string] [
        | `scrollx
        | `fade
    ]=?,
    ~vertical: bool=?,
    ~children: element=?,
    unit
) => element = "antd/lib/carousel";