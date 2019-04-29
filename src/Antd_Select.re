open React;

type t;

[@bs.send] external blur: t => unit = "blur";
[@bs.send] external focus: t => unit = "focus";

module Option = {
  [@react.component] [@bs.module "antd/lib/select"]
  external make:
    (
      ~disabled: bool=?,
      ~key: string=?,
      ~value: string=?,
      ~className: string=?,
      ~title: string=?,
      ~children: React.element,
      unit
    ) =>
    React.element =
    "Option";
};

module Make =
       (
         M: {
           type selectValue;
           type selectValueNotNull;
           type selectValueSingle;
           type optionElement;
         },
       ) => {
  [@react.component] [@bs.module]
  external make:
    (
      ~ref: Ref.t(Js.nullable(t))=?,
      ~allowClear: bool=?,
      ~autoClearSearchValue: bool=?,
      ~autoFocus: bool=?,
      ~defaultActiveFirstOption: bool=?,
      ~defaultValue: M.selectValueNotNull=?,
      ~disabled: bool=?,
      ~dropdownClassName: string=?,
      ~dropdownMatchSelectWidth: bool=?,
      ~dropdownRender: (element, Js.t({..})) => element=?,
      ~dropdownStyle: ReactDOMRe.Style.t=?,
      ~filterOption: (string, element) => bool=?, // TODO exampe not working
      ~firstActiveValue: string=?, // doc says string[], fails at runtime
      ~getPopupContainer: Dom.element => Dom.htmlElement=?,
      ~labelInValue: bool=?,
      ~maxTagCount: int=?,
      ~maxTagPlaceholder: M.selectValue => element=?, // only for multiple/tags
      ~mode: string=?,
      ~notFoundContent: Js.null(element)=?,
      ~optionFilterProp: string=?, // TODO test, probably remove
      ~optionLabelProp: string=?, // TODO test
      ~placeholder: element=?,
      ~showArrow: bool=?,
      ~showSearch: bool=?,
      ~size: string=?, // TODO
      ~suffixIcon: element=?,
      ~removeIcon: element=?,
      ~clearIcon: element=?,
      ~menuItemSelectedIcon: element=?,
      ~tokenSeparators: array(string)=?,
      ~value: M.selectValue=?,
      ~onBlur: M.selectValue => unit=?,
      ~onChange: (M.selectValue, M.optionElement) => unit=?,
      ~onSelect: (M.selectValueSingle, element) => unit=?,
      ~onDeselect: M.selectValueSingle => unit=?,
      ~onFocus: unit => unit=?,
      ~onInputKeyDown: ReactEvent.Keyboard.t => unit=?,
      ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
      ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
      ~onPopupScroll: ReactEvent.Synthetic.t => unit=?,
      ~onSearch: string => unit=?,
      ~defaultOpen: bool=?,
      ~_open: bool=?,
      ~onDropdownVisibleChange: bool => unit=?,
      ~loading: bool=?,
      ~children: element=?,
      ~style: ReactDOMRe.Style.t=?,
      unit
    ) =>
    element =
    "antd/lib/select";
};

module Default = {
  include Make({
    type selectValue =
      option({
        .
        "key": string,
        "label": element,
      });
    type optionElement = option(element);
    type selectValueNotNull = {
      .
      "key": string,
      "label": element,
    };
    type selectValueSingle = {
      .
      "key": string,
      "label": element,
    };
  });
  let makeProps =
    makeProps(
      ~mode="default",
      ~labelInValue=true,
      ~maxTagPlaceholder=?None,
      ~maxTagCount=?None,
      ~onDeselect=?None,
      ~tokenSeparators=?None,
      ~autoClearSearchValue=?None,
    );
};

module Multiple = {
  include Make({
    type selectValue =
      array({
        .
        "key": string,
        "label": element,
      });
    type selectValueSingle = {
      .
      "key": string,
      "label": element,
    };
    type optionElement = array(element);
    type selectValueNotNull =
      array({
        .
        "key": string,
        "label": element,
      });
  });

  let makeProps =
    makeProps(~mode="multiple", ~labelInValue=true, ~showSearch=?None);
};

module Tags = {
  include Make({
    type selectValue =
      array({
        .
        "key": string,
        "label": element,
      });
    type selectValueSingle = {
      .
      "key": string,
      "label": element,
    };
    type optionElement = array(element);
    type selectValueNotNull =
      array({
        .
        "key": string,
        "label": element,
      });
  });

  let makeProps =
    makeProps(~mode="tags", ~labelInValue=true, ~showSearch=?None);
};

module OptGroup = {
  [@react.component] [@bs.module "antd/lib/select"]
  external make:
    (~label: element=?, ~key: string=?, ~children: element=?, unit) => element =
    "OptGroup";
};

// module Value = {
//   type t;
//   type labeledValue = {
//     .
//     "key": string,
//     "label": element,
//   };

//   external makeString: string => t = "%identity";
//   external asStringUnsafe: t => t = "%identity";

//   external makeStrings: array(string) => t = "%identity";
//   external asStringsUnsafe: t => array(string) = "%identity";

//   external makeNumber: float => t = "%identity";
//   external asNumberUnsafe: t => float = "%identity";

//   external makeNumbers: array(float) => t = "%identity";
//   external asNumbersUnsafe: t => array(float) = "%identity";

//   external makeLabeledValue: labeledValue => t = "%identity";

//   external asLabeledValueUnsafe: t => labeledValue = "%identity";

//   external makeLabeledValues: array(labeledValue) => t = "%identity";
//   external asLabeledValuesUnsafe: t => array(labeledValue) = "%identity";
// };
