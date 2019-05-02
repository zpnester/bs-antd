open React;

module Shape = {
  type t = string;
  [@bs.inline]
  let circle = "circle";
  [@bs.inline]
  let square = "square";
};

module Size = {
  type t;
  let large: t = [%raw {| ("large") |}];
  let small: t = [%raw {| ("small") |}];
  let default: t = [%raw {| ("default") |}];

  external number: float => t = "%identity";
};

[@react.component] [@bs.module]
external make:
  (
    ~shape: Shape.t=?,
    ~size: Size.t=?,
    ~src: string=?,
    ~srcSet: string=?,
    ~icon: Antd_IconType.t=?,
    ~style: ReactDOMRe.Style.t=?,
    ~alt: string=?,
    ~onError: unit => bool=?,
    unit
  ) =>
  element =
  "antd/lib/avatar";
