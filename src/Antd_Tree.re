

open React;



type antTreeNode = {
    .
    "className": option(string),
    "disabled": option(bool),
    "disableCheckbox": option(bool),
    "title": option(element),
    "key": option(string),
    "eventKey": option(string),
    "isLeaf": option(bool), // TODO not null?
    "checked": option(bool),
    "expanded": option(bool), // TODO not null?
    "loading": option(bool),
    "selected": option(bool),
    "selectable": option(bool),
    // "icon" // skip dynamic type for input type
    // "children" // skip
};

// TODO tst
type antdTreeNodeAttribute = {
    .
    "eventKey": string,
    "prefixCls": string,
    "className": string,
    "expanded": bool,
    "selected": bool,
    "checked": bool,
    "halfChecked": bool,
    "children": element,
    "title":element,
    "pos": string,
    "dragOver": bool,
    "dragOverGapTop": bool,
    "dragOverGapBottom": bool,
    "isLeaf": bool,
    "selectable": bool,
    "disabled": bool,
    "disableCheckbox": bool,
};

module TreeNode = {
    
    [@react.component] [@bs.module "antd/lib/tree"]
    external make: (
        ~className: string=?,
        ~disabled: bool=?,
        ~disableCheckbox: bool=?,
        ~title: element=?,
        ~key: string=?,
        ~eventKey: string=?,
        ~isLeaf: bool=?,
        ~checked: bool=?,
        ~expanded: bool=?,
        ~loading: bool=?,
        ~selected: bool=?,
        ~selectable: bool=?,
        ~icon: antdTreeNodeAttribute => element=?, // TODO test
        ~children: element=?,
        unit
    ) => element = "TreeNode";

};

type antTreeNodeCheckedEvent = {
        .
        "event": string,
        "checked": bool,
        "checkedNodes": array(antTreeNode),
        "node": antTreeNode,
        "nativeEvent": Dom.mouseEvent
    };

type antTreeNodeMouseEvent = {
    .
    "node": antTreeNode,
    "event": ReactEvent.Mouse.t // TODO test, TS says handler, not event
};


type antTreeNodeDropEvent = {
    .
    "node": antTreeNode,
    "dragNode": antTreeNode,
    "dragNodesKeys": array(string),
    "dropPosition": float,
    "dropToGap": bool,
    "event": ReactEvent.Mouse.t // TODO test
};

type antTreeNodeExpandedEvent = {
    .
    "expanded": bool,
    "node": antTreeNode,
    "nativeEvent": Dom.mouseEvent
};

type antTreeNodeSelectedEvent = {
    .
    "event": string,
    "selected": bool,
    "selectedNodes": array(antTreeNode)
};

[@react.component] [@bs.module]
external make: (
    ~autoExpandParent: bool=?,
    ~blockNode: bool=?,
    ~checkable: bool=?,
    ~checkedKeys: {
        .
        "checked": array(string),
        "halfChecked": array(string)
    }=?,
    ~checkStrictly: bool=?,
    ~defaultCheckedKeys: array(string)=?,
    ~defaultExpandAll: bool=?,
    ~defaultExpandedKeys: array(string)=?,
    ~defaultExpandParent: bool=?,
    ~defaultSelectedKeys: array(string)=?,
    ~disabled: bool=?,
    ~draggable: bool=?,
    ~expandedKeys: array(string)=?,
    ~filterTreeNode: 'todo => bool=?,
    ~loadData: 'todo => Js.Promise.t('data)=?,
    ~loadedKeys: array(string)=?,
    ~multiple: bool=?,
    ~selectedKeys: array(string)=?,
    ~showIcon: bool=?,
    ~switcherIcon: element=?,
    ~showLine: bool=?,
    ~onCheck: ('todo2, antTreeNodeCheckedEvent) => unit=?,
    ~onDragEnd: antTreeNodeMouseEvent => unit=?,
    ~onDragEnter: antTreeNodeMouseEvent => unit=?,
    ~onDragLeave: antTreeNodeMouseEvent => unit=?,
    ~onDragOver: antTreeNodeMouseEvent => unit=?,
    ~onDragStart: antTreeNodeMouseEvent => unit=?,
    ~onDrop: antTreeNodeDropEvent => unit=?,
    ~onExpand: (array(string), antTreeNodeExpandedEvent) => Js.Promise.t(unit)=?, // TODO promise type?
    ~onLoad: (array(string), {
        .
        "event": string,
        "node": antTreeNode
    }) => unit=?,
    ~onRightClick: antTreeNodeMouseEvent => unit=?,
    ~onSelect: (array(string), antTreeNodeSelectedEvent) => unit=?,
    
    ~children: element=?,
    ~className: string=?,

    unit
) => element = "antd/lib/tree";


module DirectoryTree = {
    [@react.component] [@bs.module]
    external make: (
        ~expandAction: [@bs.string] [
            | `click
            | `doubleClick
        ]=?,
        ~children: element=?,
        ~className: string=?,
        // TODO copy paste tree when ready
        unit
    ) => element = "antd/lib/tree/DirectoryTree";

    
};