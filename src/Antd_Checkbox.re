open React;

type t;

[@bs.send] external blur: t => unit = "blur";
[@bs.send] external focus: t => unit = "focus";

type checkboxChangeEvent = {
  .
  // ideally target should be of makeProps type but recursion won't work here
  "target": {
    .
    "checked": bool,
    "value": string, // any skipped, not optional ensured in other places
    "name": option(string),
  },
  [@bs.meth] "stopPropagation": unit => unit,
  [@bs.meth] "preventDefault": unit => unit,
  "nativeEvent": Dom.mouseEvent,
};

[@react.component] [@bs.module "antd/es/checkbox"]
// ***** BEGIN ABSTRACT CHECKBOX *****
external make:
  (
    ~prefixCls: string=?,
    ~className: string=?,
    ~defaultChecked: bool=?,
    ~checked: bool=?,
    ~style: ReactDOMRe.Style.t=?,
    ~disabled: bool=?,
    ~onChange: checkboxChangeEvent => unit=?,
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
    // ***** BEGIN CHECKBOX *****
    ~indeterminate: bool=?,
    // ***** END CHECKBOX *****
    // ***** BEGIN CHECKBOX FROM WEBSITE *****
    ~autoFocus: bool=?,
    // ***** END CHECKBOX FROM WEBSITE *****
    ~ref: Ref.t(Js.nullable(t))=?,
    unit
  ) =>
  element =
  "default";

type checkboxOption('a) =
  {
    ..
    "label": element,
    "value": string, // not optional ensured in other places
    "disabled": bool,
    "onChange": option(checkboxChangeEvent => unit),
  } as 'a;

module Group = {
  [@react.component] [@bs.module "antd/es/checkbox/Group"]
  // ***** BEGIN ABSTRACT CHECKBOX GROUP ****
  external make:
    (
      ~prefixCls: string=?,
      ~className: string=?,
      ~options: array(checkboxOption('option))=?,
      ~disabled: bool=?,
      ~style: ReactDOMRe.Style.t=?,
      // ***** END ABSTRACT CHECKBOX GROUP ****
      // ***** BEGIN CHECKBOX GROUP *****
      ~name: string=?,
      ~defaultValue: array(string)=?, // other than string skipped
      ~value: array(string)=?,
      ~onChange: array(string) => unit=?,
      // ***** END CHECKBOX GROUP *****
      ~children: element=?,
      unit
    ) =>
    element =
    "default";
};