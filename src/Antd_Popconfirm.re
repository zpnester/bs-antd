open React;

[@react.component] [@bs.module]
external make: (
    ~cancelText: element=?,
    ~okText: element=?,
    ~okType: [@bs.string] [
        | `default
        | `dashed
        | `primary
        | `ghost
        | `danger
    ]=?,
    ~title: element=?,
    ~onCancel: ReactEvent.Mouse.t => unit=?,
    ~onConfirm: ReactEvent.Mouse.t => unit=?,
    ~okButtonProps: Antd_Button.NativeProps.t=?,
    ~cancelButtonProps: Antd_Button.NativeProps.t=?,
    ~icon: element=?,
    ~onVisibleChange: bool => unit=?, // second param skipped, got undefined
    ~children: element=?,
    unit
) => element = "antd/lib/popconfirm";