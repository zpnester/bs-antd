open React;

module Size = {
  type t;
  let large: t = [%raw {| ("large") |}];
  let small: t = [%raw {| ("small") |}];
  let default: t = [%raw {| ("default") |}];

  external number: float => t = "%identity";
};

[@react.component] [@bs.module "antd/lib/avatar"]
external make:
  (
    ~shape: [@bs.string] [ | `circle | `square]=?,
    ~size: Size.t=?, // cannot be made polyvar
    ~src: string=?,
    ~srcSet: string=?,
    ~icon: Antd_IconType.t=?,
    ~style: ReactDOMRe.Style.t=?,
    ~alt: string=?,
    ~onError: unit => bool=?,
    unit
  ) =>
  element =
  "default";