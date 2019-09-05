open React;

[@bs.module "antd/lib/empty"]
external presentedImageDefault: element = "PRESENTED_IMAGE_DEFAULT";
[@bs.module "antd/lib/empty"]
external presentedImageSimple: element = "PRESENTED_IMAGE_SIMPLE";

[@react.component] [@bs.module "antd/lib/empty"]
external make:
  (
    ~description: element=?,
    ~imageStyle: ReactDOMRe.Style.t=?,
    // "Will tread as image url when string provided"
    ~image: element=?,
    ~children: element=?,
    ~prefixCls: string=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  element =
  "default";