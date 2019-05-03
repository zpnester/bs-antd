open React;

type optionElement('o) = {
  ..
  "key": option(string),
  "value": option(string),
  "text": option(string)
} as 'o;

module Option = Antd_Select.Option;
module OptGroup = Antd_Select.OptGroup;

type t;

[@bs.send] external blur: t => unit = "blur";
[@bs.send] external focus: t => unit = "focus";



  [@react.component] [@bs.module]
  external make:
    (
      ~ref: Ref.t(Js.Nullable.t(t))=?,
      ~prefixCls: string=?,
      ~className: string=?,
      ~allowClear: bool=?,
      ~defaultActiveFirstOption: bool=?,
      ~disabled: bool=?,
      ~filterOption: (string, optionElement('o)) => bool=?,
      ~placeholder: element=?,
      ~onSearch: string => unit=?,
      ~value: string=?,
      ~defaultValue: string=?,
      ~dataSource: array(element)
                     =?,
      ~autoFocus: bool=?,
      ~backfill: bool=?,
      ~optionLabelProp: string=?,
      ~onChange: option(string) => unit=?,
      ~onSelect: (string, element) => unit=?,
      ~onBlur: option(string) => unit=?,
      ~onFocus: unit => unit=?,
      ~defaultOpen: bool=?,
      ~_open: bool=?,
      ~onDropdownVisibleChange: bool => unit=?,
      ~children: element=?,
      unit
    ) =>
    element =
    "antd/lib/auto-complete";

