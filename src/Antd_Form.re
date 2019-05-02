open React;

[@react.component] [@bs.module]
external make:
  (
    ~hideRequiredMark: bool=?,
    ~labelAlign: [@bs.string] [ | `left | `right]=?,
    ~labelCol: Antd_Grid.Col.props=?,
    ~layout: [@bs.string] [ | `horizontal | `inline | `vertical]=?,
    ~onSubmit: ReactEvent.Form.t => unit=?,
    ~wrapperCol: Antd_Grid.Col.props=?,
    ~colon: bool=?,
    ~style: ReactDOMRe.Style.t=?,
    ~className: string=?,
    ~prefixCls: string=?,
    ~children: React.element=?,
    ~key: string=?,
    unit
  ) =>
  element =
  "antd/lib/form";

module Item = {
  [@react.component] [@bs.module "antd/lib/form/"]
  external make:
    (
      ~colon: bool=?,
      ~extra: element=?,
      ~hasFeedback: bool=?,
      ~help: element=?,
      ~label: element=?,
      ~labelCol: Antd_Grid.Col.props=?,
      ~required: bool=?,
      ~validateStatus: [@bs.string] [
                         | `success
                         | `warning
                         | `error
                         | `validating
                       ]
                         =?,
      ~wrapperCol: Antd_Grid.Col.props=?,
      ~prefixCls: string=?,
      ~className: string=?,
      ~id: string=?,
      ~labelAlign: [@bs.string] [ | `left | `right]=?,
      ~style: ReactDOMRe.Style.t=?,
      ~children: element=?,
      unit
    ) =>
    element =
    "Item";
};
