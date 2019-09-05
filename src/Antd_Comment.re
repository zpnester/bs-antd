open React;

[@react.component] [@bs.module "antd/lib/comment"]
external make:
  (
    ~actions: array(element)=?,
    ~author: element=?,
    ~avatar: element=?,
    ~children: element=?,
    ~content: element=?,
    ~datetime: element=?,
    ~prefixCls: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~className: string=?,
    unit
  ) =>
  element =
  "default";