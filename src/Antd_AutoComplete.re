open React;

// export interface DataSourceItemObject {
//     value: string;
//     text: string;
// }
// export declare type DataSourceItemType = string | DataSourceItemObject |
// React.ReactElement<OptionProps> | React.ReactElement<OptGroupProps>;

// module DataSourceItem = {
//     type t;
//     external makeString: string => t = "%identity";
//     external makeObject: {
//         .
//         "value": string,
//         "text": string
//     } => t = "%identity";

//     // React.ReactElement<OptionProps> | React.ReactElement<OptGroupProps>
//     external makeElement: element => t = "%identity";
// };

// module FitlerOption = {
//     type t;

//     external makeBool: bool => t = "%identity";
//     external makeFn: ((string, 'todo) => bool) => t = "%identity";
// };

module Option = Antd_Select.Option;
module OptGroup = Antd_Select.OptGroup;

// not really equal, just same 2 methods
module Ref = Antd_Select.Ref;

module Make = (M: {
    // type dataSourceItem;
}) => {
  [@react.component] [@bs.module]
  external make:
    (
      ~ref: React.Ref.t(Js.Nullable.t(Ref.t))=?,
      // ~prefixCls: string=?,
      ~className: string=?,
      ~allowClear: bool=?,
      ~defaultActiveFirstOption: bool=?,
      ~disabled: bool=?,
      ~filterOption: (string, element) => bool=?,
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
      // HTMLInputElement | HTMLTextAreaElement | React.ReactElement<AutoCompleteInputProps> | ...
      ~children: 'children=?,
      unit
    ) =>
    element =
    "antd/lib/auto-complete";
};

include Make({
    
});