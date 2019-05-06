open React;

[@react.component] [@bs.module]
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
  "antd/lib/divider";