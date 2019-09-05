open React;
open Antd__;

type t;

[@bs.send] external blur: t => unit = "blur";
[@bs.send] external focus: t => unit = "focus";

type labeledValue = {
  .
  "value": string,
  "label": element,
};

module Node = {
  [@bs.deriving abstract]
  type make = {
    [@bs.optional]
    value: string, // number skipped
    // label deprecated
    [@bs.optional]
    title: element,
    [@bs.optional]
    key: string,
    [@bs.optional]
    isLeaf: bool,
    [@bs.optional]
    disabled: bool,
    [@bs.optional]
    disableCheckbox: bool,
    [@bs.optional]
    selectable: bool,
    [@bs.optional]
    children: array(make),
  };
};

module TreeDataSimpleMode = {
  type t;

  external bool: bool => t = "%identity";

  [@bs.obj]
  external make: (~id: string=?, ~pId: string=?, ~rootPId: string=?, unit) => t =
    "";
};

// assumes labelInValue supports only true

module LabelInValue = Antd_Select.LabelInValue;
module TreeCheckStrictly = {
  type t;
  let true_: t = [%raw {| true |}];
  let false_: t = [%raw {| false |}];
};
module Option = Antd_Select.Option;

module Multiple = {
  type t('a);

  let true_: t(array(labeledValue)) = [%raw {| true |}];
  let false_: t(option(labeledValue)) = [%raw {| false |}];
};

[@react.component] [@bs.module "antd/lib/tree-select"]
// ***** BEGIN ABSTRACT SELECT *****
external make:
  (
    ~prefixCls: string=?,
    ~className: string=?,
    ~showAction: array(string)=?, // single string skipped
    ~size: [@bs.string] [ | `default | `large | `small]=?,
    //   ~notFoundContent: Js.null(element)=?,
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
    //   ~dropdownStyle: ReactDOMRe.Style.t=?,
    ~dropdownMenuStyle: ReactDOMRe.Style.t=?,
    ~dropdownMatchSelectWidth: bool=?,
    //   ~onSearch: string => unit=?, // return any skipped
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
    // ***** BEGIN TREE SELECT *****
    ~autoFocus: bool=?,
    ~defaultValue: 'value=?,
    ~dropdownStyle: ReactDOMRe.Style.t=?,
    ~filterTreeNode: (string, Antd_Tree.treeNode) => bool=?,
    ~labelInValue: LabelInValue.t, // required
    ~loadData: Antd_Tree.treeNode => Js.Promise.t(unit)=?, // TS lying, promise is required
    ~maxTagCount: int=?,
    ~maxTagPlaceholder: array(labeledValue) => element=?,
    ~multiple: Multiple.t('value), // required
    ~notFoundContent: element=?,
    ~onChange: ('value, 'todoLabelAlwaysNull, Js.t({..})) => unit=?,
    ~onSearch: string => unit=?,
    ~onSelect: labeledValue => unit=?,
    ~onTreeExpand: array(string) => unit=?,
    ~onFocus: ReactEvent.Focus.t => unit=?,
    ~onBlur: ReactEvent.Focus.t => unit=?,
    ~searchPlaceholder: string=?,
    ~searchValue: string=?,
    ~showCheckedStrategy: [@bs.string] [
                            | [@bs.as "SHOW_ALL"] `showAll
                            | [@bs.as "SHOW_PARENT"] `showParent
                            | [@bs.as "SHOW_CHILD"] `showChild
                          ]
                            =?,
    ~suffixIcon: element=?,
    ~treeCheckable: bool=?, // reactnode skipped, bool on website
    ~treeCheckStrictly: TreeCheckStrictly.t=?,
    ~treeData: array(Node.make)=?,
    ~treeDataSimpleMode: TreeDataSimpleMode.t=?, // todo test
    ~treeDefaultExpandAll: bool=?,
    ~treeDefaultExpandedKeys: array(string)=?,
    ~treeExpandedKeys: array(string)=?,
    ~treeIcon: bool=?,
    ~treeNodeFilterProp: string=?,
    ~treeNodeLabelProp: string=?,
    ~value: 'value=?,
    // ***** END TREE SELECT *****
    ~children: element=?,
    ~ref: Ref.t(Js.nullable(t))=?,
    unit
  ) =>
  element =
  "default";

module TreeNode = {
  [@react.component] [@bs.module "antd/lib/tree-select"] [@bs.scope "default"]
  external make:
    (
      ~selectable: bool=?,
      ~disableCheckbox: bool=?,
      ~disabled: bool=?,
      ~isLeaf: bool=?,
      ~key: string=?,
      ~title: element=?,
      ~label: element=?,
      ~value: string=?,
      ~children: element=?,
      unit
    ) =>
    element =
    "TreeNode";
};