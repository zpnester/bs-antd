

open React;

type t;

[@bs.send] external blur: t => unit = "blur";
[@bs.send] external focus: t => unit = "focus";

type treeNode;

type labeledValue = {
    .
    "value": string,
    "label": element,
    "halfChecked": array(string)
};

// TODO
type treeNodeNormal = {
    .
    "value": string, // number skipped
    // label deprecated
    "title": element,
    "key": string,
    "isLeaf": bool,
    "disabled": bool,
    "disableCheckbox": bool,
    "selectable": bool,
    "children": array(treeNodeNormal)
};

module TreeDataSimpleMode = {
    type t;

    external bool: bool => t = "%identity";

    [@bs.obj] external make: (
        ~id: string=?,
        ~pId: string=?,
        ~rootPId: string=?,
        unit
    ) => t = "";
};


module LabelInValue = Antd_Select.LabelInValue;

[@react.component] [@bs.module]
external make: (
    // TODO abstract select
    // ***** BEGIN TREE SELECT *****
    ~autoFocus: bool=?,
    ~defaultValue: array(string)=?,
    ~dropdownStyle: ReactDOMRe.Style.t=?,
    ~filterTreeNode: (string, treeNode) => bool=?,
    ~loadData: 'node => unit=?,
    ~maxTagCount: int=?,
    ~maxTagPlaceholder: array('todo2) => element=?,
    ~multiple: bool=?,
    ~notFoundContent: element=?,
    ~onChange: ('todo5, 'todo6, 'todo7) => unit=?,
    ~onSearch: ('todo8) => unit=?,
    ~onSelect: ('todo9) => unit=?,
    ~onTreeExpand: array(string) => unit=?,
    ~onFocus: ReactEvent.Synthetic.t => unit=?,
    ~onBlur: ReactEvent.Synthetic.t => unit=?, // TODO test param
    ~searchPlaceholder: string=?,
    ~searchValue: string=?,
    ~showCheckedStrategy: [@bs.string] [
        | [@bs.as "SHOW_ALL"] `showAll
        | [@bs.as "SHOW_PARENT"] `showParent
        | [@bs.as "SHOW_CHILD"] `showChild
    ]=?,
    ~suffixIcon: element=?,
    ~treeCheckable: bool=?, // reactnode skipped, bool on website
    
    ~treeCheckStrictly: bool=?,

    ~allowClear: bool=?,
    ~autoClearSearchValue: bool=?,
    ~disabled: bool=?,
    ~dropdownClassName: string=?,
    ~dropdownMatchSelectWidth: bool=?,
    ~getPopupContainer: Dom.element => Dom.htmlElement=?,
    ~placeholder: string=?,
    ~treeIcon: bool=?,
    ~showSearch: bool=?,
    ~size: [@bs.string] [
        | `default
        | `large
        | `small
    ]=?,
    // treeNodeNormal used instead of treeNode 
    ~treeData: array(treeNodeNormal)=?,
    ~treeDataSimpleMode: TreeDataSimpleMode.t=?,
    ~treeDefaultExpandAll: bool=?,  
    ~treeDefaultExpandedKeys: array(string)=?,
    ~treeExpandedKeys: array(string)=?,
    ~treeNodeFilterProp: string=?,
    ~treeNodeLabelProp: string=?,
    ~value: array(string)=?, // TODO test, string skipped
    
    ~style: ReactDOMRe.Style.t=?,
    // ***** END TREE SELECT *****
    ~children: element=?,
    ~ref: Ref.t(Js.nullable(t))=?,

    unit
) => element = "antd/lib/tree-select";


module TreeNode = {
    [@react.component] [@bs.module "antd/lib/tree-select"]
external make: (
    ~selectable: bool=?,
    ~disableCheckbox: bool=?,
    ~disabled: bool=?,
    ~isLeaf: bool=?,
    ~key: string=?,
    ~title: element=?,
    ~value: string=?,
    ~children: element=?,

    unit
) => element = "TreeNode";
   
}