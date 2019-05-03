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
    children: React.element
  };

  [@bs.module "antd/lib/select"] external make: component(makeProps) = "Option";

};


module Mode = {
  type default;
  type multiple;
  type tags;

  let default: default = [%raw {| ("default") |}];
  let multiple: multiple = [%raw {| ("multiple") |}];
  let tags: tags = [%raw {| ("tags") |}];
};

module LabelInValue = {
  type true_;

  let true_: true_ = [%raw {| (true) |}];
};

////////////////////

module Make =
       (
         M: {
           type selectValue;
           type selectValueSingle;
           type optionElement;
           type optionElementSingle;
           type labelInValue;
           type mode;
         }
       ) => {

[@react.component] [@bs.module]
  external make:
    (
      // ***** BEGIN ABSTRACT SELECT *****
      ~prefixCls: string=?,
      ~className: string=?,
      ~showAction: array(string)=?, // single string skipped
      ~size: [@bs.string] [
          | `default
          | `large
          | `small
      ]=?, 
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
      ~getPopupContainer: Dom.element => Dom.htmlElement=?, // TODO test input null
      ~filterOption: (string, reactElement(Option.makeProps)) => bool=?, // TODO test
      ~id: string=?,
      ~defaultOpen: bool=?,
      ~_open: bool=?,
      ~onDropdownVisibleChange: bool => unit=?,
      ~autoClearSearchValue: bool=?,
      ~dropdownRender: (element, Js.t({..})) => element=?, // select props as obj
      ~loading: bool=?,
      // ***** END ABSTRACT SELECT *****
      // ***** BEGIN SELECT *****
      ~value: M.selectValue=?,
      ~defaultValue: M.selectValue=?,
      ~mode: M.mode, // required
      ~optionLabelProp: string=?, // TODO test
      ~firstActiveValue: string=?, // doc says string[], fails at runtime
      ~onChange: (M.selectValue, M.optionElement) => unit=?,
      ~onSelect: (M.selectValueSingle, M.optionElementSingle) => unit=?, // TODO tst
      ~onDeselect: M.selectValueSingle => unit=?, // return any skipped
      ~onBlur: M.selectValue => unit=?,
      ~onFocus: unit => unit=?,
      ~onPopupScroll: ReactEvent.Synthetic.t => unit=?,
      ~onInputKeyDown: ReactEvent.Keyboard.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~maxTagCount: int=?, // only for multiple/tags
      ~maxTagPlaceholder: M.selectValue => element=?, // only for multiple/tags
      ~optionFilterProp: string=?, // TODO test, probably remove
      ~labelInValue: M.labelInValue, // required
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
    "antd/lib/select";

};
////////////////////


type labeledValue = {
  .
  "key": string,
  "label": element,
};

module Default = {
  include Make({
    type selectValue = option(labeledValue);
    type selectValueSingle = labeledValue;
    type optionElement = option(element);
    type optionElementSingle = element;
    type mode = Mode.default;
    type labelInValue = LabelInValue.true_;
  });
  
};

module Multiple = {
  include Make({
    type selectValue = array(labeledValue);
    type selectValueSingle = labeledValue;
    type optionElement = array(element);
    type optionElementSingle = element;
    type mode = Mode.multiple;
    type labelInValue = LabelInValue.true_;
  });

};

module Tags = {
  include Make({
    type selectValue = array(labeledValue);
    type selectValueSingle = labeledValue;
    type optionElement = array(element);
    type optionElementSingle = element;
    type mode = Mode.tags;
    type labelInValue = LabelInValue.true_;
  });

};

module OptGroup = {
  [@react.component] [@bs.module "antd/lib/select"]
  external make:
    (~label: element=?, ~key: string=?, ~children: element=?, unit) => element =
    "OptGroup";
};
