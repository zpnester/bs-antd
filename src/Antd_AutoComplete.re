open React;
open Antd__;

module Option = Antd_Select.Option;
module OptGroup = Antd_Select.OptGroup;
module Mode = Antd_Select.Mode;
module LabelInValue = Antd_Select.LabelInValue;

type t;

[@bs.send] external blur: t => unit = "blur";
[@bs.send] external focus: t => unit = "focus";



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
      ~getPopupContainer: Dom.element => Dom.htmlElement=?,
      ~filterOption: (string, reactElement(Option.makeProps)) => bool=?, 
      ~id: string=?,
      ~defaultOpen: bool=?,
      ~_open: bool=?,
      ~onDropdownVisibleChange: bool => unit=?,
      ~autoClearSearchValue: bool=?,
      ~dropdownRender: (element, Js.t({..})) => element=?, // select props as obj
      ~loading: bool=?,
      // ***** END ABSTRACT SELECT ***** EDITED
      // ***** BEGIN SELECT *****
      ~value: option(Antd_Select.labeledValue)=?,
      ~defaultValue: Antd_Select.labeledValue=?,
      ~optionLabelProp: string=?,
      ~firstActiveValue: string=?, // doc says string[], fails at runtime
      ~onChange: option(Antd_Select.labeledValue) => unit=?,
      ~onSelect: (Antd_Select.labeledValue, reactElement(Js.t({..}))) => unit=?,
      ~onDeselect: Antd_Select.labeledValue => unit=?, // return any skipped
      ~onBlur: option(Antd_Select.labeledValue) => unit=?,
      ~onFocus: unit => unit=?,
      ~onPopupScroll: ReactEvent.Synthetic.t => unit=?,
      ~onInputKeyDown: ReactEvent.Keyboard.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
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
      // ***** BEGIN AUTOCOMPLETE *****
      ~backfill: bool=?,
      ~dataSource: array(element), // Option simpler variants skipped
      // ***** END AUTOCOMPLETE *****
      ~children: element=?,
      ~ref: Ref.t(Js.Nullable.t(t))=?,
      unit
    ) =>
    element =
    "antd/lib/auto-complete";

