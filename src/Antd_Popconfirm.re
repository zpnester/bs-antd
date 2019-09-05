open React;

[@react.component] [@bs.module "antd/lib/popconfirm"]
external make:
  (
    ~cancelText: element=?,
    ~okText: element=?,
    ~okType: [@bs.string] [ | `default | `dashed | `primary | `ghost | `danger]
               =?,
    ~title: element=?,
    ~onCancel: ReactEvent.Mouse.t => unit=?,
    ~onConfirm: ReactEvent.Mouse.t => unit=?,
    ~okButtonProps: Antd_Button.makeProps=?, // actually NativeButtonProps but they are "same enough"
    ~cancelButtonProps: Antd_Button.makeProps=?,
    ~icon: element=?,
    ~onVisibleChange: bool => unit=?, // second param skipped, got undefined
    ~children: element=?,
    unit
  ) =>
  element =
  "default";