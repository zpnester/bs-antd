
open React;

[@react.component] [@bs.module]
external make: (
  ~addonAfter: element=?,
  ~addonBefore: element=?,
  ~defaultValue: string=?,
  ~disabled: bool=?,
  ~id: string=?,
  ~prefix: element=?,
  ~size: [@bs.string] [
      | `large 
       | `default 
       | `small
  ]=?,
  ~suffix: element=?,
  ~_type: string=?,
  ~value: string=?,
  ~onPressEnter: ReactEvent.Keyboard.t=?,
  ~allowClear: bool=?,
  ~onChange: ReactEvent.Form.t=?, // TODO
  // react
  ~placeholder: string=?,
  unit
) => element = "antd/lib/input"

// TODO modules