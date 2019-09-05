open React;

type t;

[@bs.send] external blur: t => unit = "blur";
[@bs.send] external focus: t => unit = "focus";

type radioChangeEventTraget = {
  .
  "checked": bool,
  "value": string, // not optional ensured in other places
  "name": option(string),
  // TODO other, lowest priority
};

type radioChangeEvent = {
  .
  "target": radioChangeEventTraget,
  [@bs.meth] "stopPropagation": unit => unit,
  [@bs.meth] "preventDefault": unit => unit,
  "nativeEvent": Dom.mouseEvent,
};

[@react.component] [@bs.module "antd/es/radio/radio"]
// ***** BEGIN ABSTRACT CHECKBOX *****
external make:
  (
    ~prefixCls: string=?,
    ~className: string=?,
    ~defaultChecked: bool=?,
    ~checked: bool=?,
    ~style: ReactDOMRe.Style.t=?,
    ~disabled: bool=?,
    // replaced below
    // ~onChange: checkboxChangeEvent => unit=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
    ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
    ~onKeyPress: ReactEvent.Keyboard.t => unit=?,
    ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~value: string, // value is required to ensure type on Group
    ~tabIndex: int=?,
    ~name: string=?,
    ~children: element=?,
    // ***** END ABSTRACT CHECKBOX *****
    // ***** BEGIN ABSTRACT CHECKBOX ONCHANGE *****
    ~onChange: radioChangeEvent => unit=?,
    // ***** END ABSTRACT CHECKBOX ONCHANGE *****
    // ***** BEGIN RADIO FROM WEBSITE *****
    ~autoFocus: bool=?,
    // ***** END RADIO FROM WEBSITE *****
    ~ref: Ref.t(Js.nullable(t))=?,
    unit
  ) =>
  element =
  "default";

type checkboxOption('a) = Antd_Checkbox.checkboxOption('a);

module Group = {
  // TODO blur/focus and ref too?

  [@react.component] [@bs.module "antd/es/radio/group"]
  // ***** BEGIN ABSTRACT CHECKBOX GROUP ****
  external make:
    (
      ~prefixCls: string=?,
      ~className: string=?,
      ~options: array(checkboxOption('option))=?,
      ~disabled: bool=?,
      ~style: ReactDOMRe.Style.t=?,
      // ***** END ABSTRACT CHECKBOX GROUP ****
      // ***** BEGIN RADIO GROUP *****
      ~defaultValue: string=?, // any skipped
      ~value: string=?, // any skipped
      ~onChange: radioChangeEvent => unit=?,
      ~size: [@bs.string] [ | `large | `default | `small]=?, // only for buttons
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~name: string=?,
      ~children: element=?,
      ~id: string=?,
      ~buttonStyle: [@bs.string] [ | `outline | `solid]=?,
      // ***** END RADIO GROUP *****
      unit
    ) =>
    element =
    "default";
};

module Button = {
  // complete copy paste of radio

  [@react.component] [@bs.module "antd/es/radio/radioButton"]
  // ***** BEGIN ABSTRACT CHECKBOX *****
  external make:
    (
      ~prefixCls: string=?,
      ~className: string=?,
      ~defaultChecked: bool=?,
      ~checked: bool=?,
      ~style: ReactDOMRe.Style.t=?,
      ~disabled: bool=?,
      // replaced below
      // ~onChange: checkboxChangeEvent => unit=?,
      ~onClick: ReactEvent.Mouse.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onKeyPress: ReactEvent.Keyboard.t => unit=?,
      ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
      ~value: string, // value is required to ensure type on Group
      ~tabIndex: int=?,
      ~name: string=?,
      ~children: element=?,
      // ***** END ABSTRACT CHECKBOX *****
      // ***** BEGIN ABSTRACT CHECKBOX ONCHANGE *****
      ~onChange: radioChangeEvent => unit=?,
      // ***** END ABSTRACT CHECKBOX ONCHANGE *****
      // ***** BEGIN RADIO FROM WEBSITE *****
      ~autoFocus: bool=?,
      // ***** END RADIO FROM WEBSITE *****
      ~ref: Ref.t(Js.nullable(t))=?,
      unit
    ) =>
    element =
    "default";
};