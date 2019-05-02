

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

    external fromBool: bool => t = "%identity";

    [@bs.obj] external make: (
        ~id: string=?,
        ~pId: string=?,
        ~rootPId: string=?,
        unit
    ) => t = "";
};

[@react.component] [@bs.module]
external make: (
    ~ref: Ref.t(Js.nullable(t))=?,
    ~allowClear: bool=?,
    ~autoClearSearchValue: bool=?,
    ~defaultValue: array(string)=?,
    ~disabled: bool=?,
    ~dropdownClassName: string=?,
    ~dropdownMatchSelectWidth: bool=?,
    ~dropdownStyle: ReactDOMRe.Style.t=?,
    ~filterTreeNode: (string, treeNode) => bool=?,
    ~getPopupContainer: Dom.element => Dom.htmlElement=?,
    ~labelInValue: bool=?,
    ~loadData: 'node => unit=?,
    ~maxTagCount: int=?,
    ~maxTagPlaceholder: array('todo2) => element=?,
    ~multiple: bool=?,
    ~placeholder: string=?,
    ~searchPlaceholder: string=?,
    ~searchValue: string=?,
    ~treeIcon: bool=?,
    ~showCheckedStrategy: [@bs.string] [
        | [@bs.as "SHOW_ALL"] `showAll
        | [@bs.as "SHOW_PARENT"] `showParent
        | [@bs.as "SHOW_CHILD"] `showChild
    ]=?,
    ~showSearch: bool=?,
    ~size: [@bs.string] [
        | `default
        | `large
        | `small
    ]=?,
    ~suffixIcon: element=?,
    ~treeCheckable: bool=?, // reactnode skipped, bool on website
    ~treeCheckStrictly: bool=?,
    // treeNodeNormal used instead of treeNode 
    ~treeData: array(treeNodeNormal)=?,
    ~treeDataSimpleMode: TreeDataSimpleMode.t=?,
    ~treeDefaultExpandAll: bool=?,  
    ~treeDefaultExpandedKeys: array(string)=?,
    ~treeExpandedKeys: array(string)=?,
    ~treeNodeFilterProp: string=?,
    ~treeNodeLabelProp: string=?,
    ~value: array(string)=?, // TODO test, string skipped
    ~onChange: ('todo5, 'todo6, 'todo7) => unit=?,
    ~onSearch: ('todo8) => unit=?,
    ~onSelect: ('todo9) => unit=?,
    ~onTreeExpand: array(string) => unit=?,
    ~style: ReactDOMRe.Style.t=?,
    ~children: element=?,
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