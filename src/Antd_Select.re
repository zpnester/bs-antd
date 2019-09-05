open React;
open Antd__;

type t;

[@bs.send] external blur: t => unit = "blur";
[@bs.send] external focus: t => unit = "focus";

module Option = {
  [@bs.deriving abstract]
  type makeProps = {
    [@bs.optional]
    disabled: bool,
    [@bs.optional]
    key: string,
    [@bs.optional]
    value: string,
    [@bs.optional]
    className: string,
    [@bs.optional]
    title: string,
    [@bs.optional]
    children: React.element,
  };

  [@bs.module "antd/es/select"] [@bs.scope "default"]
  external make: component(makeProps) = "Option";
};

type labeledValue = {
  .
  "key": string,
  "label": element,
};

module Mode = {
  type t('value, 'valueSingle, 'optionElement, 'optionElementSingle);

  let default:
    t(
      option(labeledValue),
      labeledValue,
      option(reactElement(Option.makeProps)),
      reactElement(Option.makeProps),
    ) = [%raw
    {| ("default") |}
  ];
  let multiple:
    t(
      array(labeledValue),
      labeledValue,
      array(reactElement(Option.makeProps)),
      reactElement(Option.makeProps),
    ) = [%raw
    {| ("multiple") |}
  ];
  let tags:
    t(
      array(labeledValue),
      labeledValue,
      array(reactElement(Option.makeProps)),
      reactElement(Option.makeProps),
    ) = [%raw
    {| ("tags") |}
  ];
};

module LabelInValue = {
  type t;

  let true_: t = [%raw {| (true) |}];
};

[@react.component] [@bs.module "antd/es/select"]
// ***** BEGIN ABSTRACT SELECT *****
external make:
  (
    ~prefixCls: string=?,
    ~className: string=?,
    ~showAction: array(string)=?, // single string skipped
    ~size: [@bs.string] [ | `default | `large | `small]=?,
    ~notFoundContent: Js.null(element)=?,
    ~transitionName: string=?,
    ~choiceTransitionName: string=?,
    ~showSearch: bool=?,
    ~allowClear: bool=?,
    ~disabled: bool=?,
    ~showArrow: bool=?,
    ~style: ReactDOMRe.Style.t=?,
    ~tabIndex: int=?,
    ~placeholder: element=?,
    ~defaultActiveFirstOption: bool=?,
    ~dropdownClassName: string=?,
    ~dropdownStyle: ReactDOMRe.Style.t=?,
    ~dropdownMenuStyle: ReactDOMRe.Style.t=?,
    ~dropdownMatchSelectWidth: bool=?,
    ~onSearch: string => unit=?, // return any skipped
    ~getPopupContainer: Dom.element => Dom.htmlElement=?,
    ~filterOption: (string, reactElement(Option.makeProps)) => bool=?,
    ~id: string=?,
    ~defaultOpen: bool=?,
    ~_open: bool=?,
    ~onDropdownVisibleChange: bool => unit=?,
    ~autoClearSearchValue: bool=?,
    ~dropdownRender: (element, Js.t({..})) => element=?, // select props as obj
    ~loading: bool=?,
    // ***** END ABSTRACT SELECT *****
    // ***** BEGIN SELECT *****
    ~value: 'selectValue=?,
    ~defaultValue: 'selectValue=?,
    ~mode: Mode.t(
             'selectValue,
             'selectValueSingle,
             'optionElement,
             'optionElementSingle,
           ), // required
    ~optionLabelProp: string=?,
    ~firstActiveValue: string=?, // doc says string[], fails at runtime
    ~onChange: ('selectValue, 'optionElement) => unit=?,
    ~onSelect: ('selectValueSingle, 'optionElementSingle) => unit=?,
    ~onDeselect: 'selectValueSingle => unit=?, // return any skipped
    ~onBlur: 'selectValue => unit=?,
    ~onFocus: unit => unit=?,
    ~onPopupScroll: ReactEvent.Synthetic.t => unit=?,
    ~onInputKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
    ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
    ~maxTagCount: int=?, // only for multiple/tags
    ~maxTagPlaceholder: 'selectValue => element=?, // only for multiple/tags
    ~optionFilterProp: string=?,
    ~labelInValue: LabelInValue.t, // required
    ~tokenSeparators: array(string)=?,
    ~getInputElement: unit => element=?,
    ~autoFocus: bool=?,
    ~suffixIcon: element=?,
    ~removeIcon: element=?,
    ~clearIcon: element=?,
    ~menuItemSelectedIcon: element=?,
    // ***** END SELECT *****
    ~children: element=?,
    ~ref: Ref.t(Js.nullable(t))=?,
    unit
  ) =>
  element =
  "default";

module OptGroup = {
  [@react.component] [@bs.module "antd/es/select"] [@bs.scope "default"]
  external make:
    (~label: element=?, ~key: string=?, ~children: element=?, unit) => element =
    "OptGroup";
};