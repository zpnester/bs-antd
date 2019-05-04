open React;

type changeEvent = {
  .
  "target": {
    .
    "checked": bool, // TODO test
    "value": option(string) // TODO test, not in TS
  },
  [@bs.meth] "stopPropagation": unit => unit,
  [@bs.meth] "preventDefault": unit => unit,
  "nativeEvent": Dom.mouseEvent,
};


type t;

[@bs.send] external blur: t => unit = "blur";
[@bs.send] external focus: t => unit = "focus";

[@react.component] [@bs.module]
external make:
  (
    ~ref: Ref.t(Js.nullable(t))=?,
    ~autoFocus: bool=?,
    ~checked: bool=?,
    ~defaultChecked: bool=?,
    ~disabled: bool=?,
    ~value: string=?, // any TODO test
    // AbstractCheckboxProps
    ~prefixCls: string=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~onChange: changeEvent=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
    ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
    ~onKeyPress: ReactEvent.Keyboard.t => unit=?,
    ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~tabIndex: int=?,
    ~name: string=?,
    ~children: element=?,
    unit
  ) =>
  element =
  "antd/lib/radio/radio";

module Option = {
  type t;

  external string: string => t = "%identity";

  [@bs.obj]
  external make:
    (
      ~label: element=?,
      ~value: string=?, // (any) TODO test
      ~disabled: bool=?,
      ~onChange: changeEvent => unit=?, // TODO test
      unit
    ) =>
    t =
    "";
};

module Group = {
  // TODO blur/focus and ref too?

  [@react.component] [@bs.module]
  external make:
    (
      ~defaultValue: string=?, // any TODO  test
      ~disabled: bool=?,
      ~name: string=?,
      ~options: array(Option.t)=?,
      ~size: [@bs.string] [ | `large | `default | `small]=?,
      ~value: string=?, // TODO test
      ~onChange: changeEvent => unit=?,
      ~buttonStyle: [@bs.string] [ | `outline | `solid]=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~children: element=?,
      ~id: string=?,
      ~prefixCls: string=?,
      ~className: string=?,
      ~style: ReactDOMRe.Style.t=?,
      unit
    ) =>
    element =
    "antd/lib/radio/group";
};

module Button = {
  // copy pasted

  [@react.component] [@bs.module]
  external make:
    (
      ~ref: Ref.t(Js.nullable(t))=?,
      ~autoFocus: bool=?,
      ~checked: bool=?,
      ~defaultChecked: bool=?,
      ~disabled: bool=?,
      ~value: string=?, // any TODO test
      // AbstractCheckboxProps
      ~prefixCls: string=?,
      ~className: string=?,
      ~style: ReactDOMRe.Style.t=?,
      ~onChange: changeEvent=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onKeyPress: ReactEvent.Keyboard.t => unit=?,
      ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
      ~tabIndex: int=?,
      ~name: string=?,
      ~children: element=?,
      unit
    ) =>
    element =
    "antd/lib/radio/radioButton";
};
