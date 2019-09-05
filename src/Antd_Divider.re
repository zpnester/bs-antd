open React;

[@react.component] [@bs.module "antd/es/divider"]
external make:
  (
    ~className: string=?,
    ~dashed: bool=?,
    ~orientation: [@bs.string] [ | `left | `right]=?,
    ~style: ReactDOMRe.Style.t=?,
    ~_type: [@bs.string] [ | `horizontal | `vertical]=?,
    ~prefixCls: string=?,
    ~children: element=?,
    unit
  ) =>
  element =
  "default";