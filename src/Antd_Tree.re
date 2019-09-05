open React;

type treeNodeProps = {
  .
  "checked": bool,
  "dragOver": bool,
  "dragOverGapTop": bool,
  "dragOverGapBottom": bool,
  "eventKey": string,
  "expanded": bool,
  "halfChecked": bool,
  "loaded": bool,
  "loading": bool,
  "pos": string,
  "selected": bool,
  "title": element,
};

type treeNode = Antd__.reactElement(treeNodeProps);

module TreeNode = {
  [@react.component] [@bs.module "antd/es/tree"] [@bs.scope "default"]
  external make:
    (
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
      ~icon: treeNodeProps => element=?,
      ~children: element=?,
      unit
    ) =>
    element =
    "TreeNode";
};

type treeNodeCheckedEvent = {
  .
  "checked": bool,
  "node": treeNode,
  "nativeEvent": Dom.mouseEvent,
};

type treeNodeMouseEvent = {
  .
  "node": treeNode,
  "event": ReactEvent.Mouse.t,
};

type treeNodeDropEvent = {
  .
  "node": treeNode,
  "dragNode": treeNode,
  "dragNodesKeys": array(string),
  "dropPosition": float,
  "dropToGap": bool,
  "event": ReactEvent.Mouse.t,
};

type treeNodeExpandedEvent = {
  .
  "expanded": bool,
  "node": treeNode,
  "nativeEvent": Dom.mouseEvent,
};

type treeNodeSelectedEvent = {
  .
  "selected": bool,
  // selectedNodes skipped
};

type strictCheck = {
  .
  "checked": array(string),
  "halfChecked": array(string),
};

module CheckStrictly = {
  type t('a);

  let false_: t(array(string)) = [%raw {| false |}];
  let true_: t(strictCheck) = [%raw {| true |}];
};

[@react.component] [@bs.module "antd/es/tree"]
// ***** BEGIN TREE *****
external make:
  (
    ~autoExpandParent: bool=?,
    ~blockNode: bool=?,
    ~checkable: bool=?,
    ~checkedKeys: 'check=?,
    ~checkStrictly: CheckStrictly.t('check), // requried
    ~defaultCheckedKeys: array(string)=?, // always str[], does not depend on checkStrictly
    ~defaultExpandAll: bool=?,
    ~defaultExpandedKeys: array(string)=?,
    ~defaultExpandParent: bool=?,
    ~defaultSelectedKeys: array(string)=?,
    ~disabled: bool=?,
    ~draggable: bool=?,
    ~expandedKeys: array(string)=?,
    ~filterTreeNode: treeNode => bool=?,
    ~loadData: treeNode => Js.Promise.t(unit)=?, // web example does not resolve, it just does setState
    ~loadedKeys: array(string)=?,
    ~multiple: bool=?,
    ~selectedKeys: array(string)=?,
    ~showIcon: bool=?,
    ~switcherIcon: element=?,
    ~showLine: bool=?,
    ~onCheck: ('check, treeNodeCheckedEvent) => unit=?,
    ~onDragEnd: treeNodeMouseEvent => unit=?,
    ~onDragEnter: treeNodeMouseEvent => unit=?,
    ~onDragLeave: treeNodeMouseEvent => unit=?,
    ~onDragOver: treeNodeMouseEvent => unit=?,
    ~onDragStart: treeNodeMouseEvent => unit=?,
    ~onDrop: treeNodeDropEvent => unit=?,
    ~onExpand: (array(string), treeNodeExpandedEvent) => Js.Promise.t(unit)=?, // promise type skipped
    ~onLoad: (array(string), {. "node": treeNode}) => unit=?,
    ~onRightClick: treeNodeMouseEvent => unit=?,
    ~onSelect: (array(string), treeNodeSelectedEvent) => unit=?,
    ~className: string=?,
    // ***** END TREE *****
    ~children: element=?,
    unit
  ) =>
  element =
  "default";

module ExpandAction = {
  type t;

  let false_: t = [%raw {| false |}];
  let click: t = [%raw {| "click" |}];
  let doubleClick: t = [%raw {| "doubleClick" |}];
};

module DirectoryTree = {
  [@react.component] [@bs.module "antd/es/tree/DirectoryTree"]
  // ***** BEGIN TREE *****
  external make:
    (
      ~autoExpandParent: bool=?,
      ~blockNode: bool=?,
      ~checkable: bool=?,
      ~checkedKeys: 'check=?,
      ~checkStrictly: CheckStrictly.t('check), // requried
      ~defaultCheckedKeys: array(string)=?, // always str[], does not depend on checkStrictly
      ~defaultExpandAll: bool=?,
      ~defaultExpandedKeys: array(string)=?,
      ~defaultExpandParent: bool=?,
      ~defaultSelectedKeys: array(string)=?,
      ~disabled: bool=?,
      ~draggable: bool=?,
      ~expandedKeys: array(string)=?,
      ~filterTreeNode: treeNode => bool=?,
      ~loadData: treeNode => Js.Promise.t(unit)=?, // web example does not resolve, it just does setState
      ~loadedKeys: array(string)=?,
      ~multiple: bool=?,
      ~selectedKeys: array(string)=?,
      ~showIcon: bool=?,
      ~switcherIcon: element=?,
      ~showLine: bool=?,
      ~onCheck: ('check, treeNodeCheckedEvent) => unit=?,
      ~onDragEnd: treeNodeMouseEvent => unit=?,
      ~onDragEnter: treeNodeMouseEvent => unit=?,
      ~onDragLeave: treeNodeMouseEvent => unit=?,
      ~onDragOver: treeNodeMouseEvent => unit=?,
      ~onDragStart: treeNodeMouseEvent => unit=?,
      ~onDrop: treeNodeDropEvent => unit=?,
      ~onExpand: (array(string), treeNodeExpandedEvent) => Js.Promise.t(unit)
                   =?, // promise type skipped
      ~onLoad: (array(string), {. "node": treeNode}) => unit=?,
      ~onRightClick: treeNodeMouseEvent => unit=?,
      ~onSelect: (array(string), treeNodeSelectedEvent) => unit=?,
      ~className: string=?,
      // ***** END TREE *****
      // ***** BEGIN DIRECTORY TREE *****
      ~expandAction: ExpandAction.t=?,
      // ***** END DIRECTORY TREE *****
      ~children: element=?,
      unit
    ) =>
    element =
    "default";
};

// ********** copy paste + dataRef prop

module Make = (M: {type dataRef;}) => {
  // this type generated by manual testing
  // every field is not optional when tested, if not - change this type
  // can break
  type treeNodeProps = {
    .
    "checked": bool,
    "dragOver": bool,
    "dragOverGapTop": bool,
    "dragOverGapBottom": bool,
    "eventKey": string,
    "expanded": bool,
    "halfChecked": bool,
    "loaded": bool,
    "loading": bool,
    "pos": string,
    "selected": bool,
    "title": element,
    "dataRef": M.dataRef,
  };

  type treeNode = Antd__.reactElement(treeNodeProps);

  module TreeNode = {
    [@react.component] [@bs.module "antd/es/tree"] [@bs.scope "default"]
    external make:
      (
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
        ~icon: treeNodeProps => element=?,
        ~children: element=?,
        ~dataRef: M.dataRef, // required, custom props from website example
        unit
      ) =>
      element =
      "TreeNode";
  };

  type treeNodeCheckedEvent = {
    .
    "checked": bool,
    "node": treeNode,
    "nativeEvent": Dom.mouseEvent,
  };

  type treeNodeMouseEvent = {
    .
    "node": treeNode,
    "event": ReactEvent.Mouse.t,
  };

  type treeNodeDropEvent = {
    .
    "node": treeNode,
    "dragNode": treeNode,
    "dragNodesKeys": array(string),
    "dropPosition": float,
    "dropToGap": bool,
    "event": ReactEvent.Mouse.t,
  };

  type treeNodeExpandedEvent = {
    .
    "expanded": bool,
    "node": treeNode,
    "nativeEvent": Dom.mouseEvent,
  };

  type treeNodeSelectedEvent = {
    .
    "selected": bool,
    // selectedNodes skipped
  };

  type strictCheck = {
    .
    "checked": array(string),
    "halfChecked": array(string),
  };

  module CheckStrictly = {
    type t('a);

    let false_: t(array(string)) = [%raw {| false |}];
    let true_: t(strictCheck) = [%raw {| true |}];
  };

  [@react.component] [@bs.module "antd/es/tree"]
  // ***** BEGIN TREE *****
  external make:
    (
      ~autoExpandParent: bool=?,
      ~blockNode: bool=?,
      ~checkable: bool=?,
      ~checkedKeys: 'check=?,
      ~checkStrictly: CheckStrictly.t('check), // requried
      ~defaultCheckedKeys: array(string)=?, // always str[], does not depend on checkStrictly
      ~defaultExpandAll: bool=?,
      ~defaultExpandedKeys: array(string)=?,
      ~defaultExpandParent: bool=?,
      ~defaultSelectedKeys: array(string)=?,
      ~disabled: bool=?,
      ~draggable: bool=?,
      ~expandedKeys: array(string)=?,
      ~filterTreeNode: treeNode => bool=?,
      ~loadData: treeNode => Js.Promise.t(unit)=?, // web example does not resolve, it just does setState
      ~loadedKeys: array(string)=?,
      ~multiple: bool=?,
      ~selectedKeys: array(string)=?,
      ~showIcon: bool=?,
      ~switcherIcon: element=?,
      ~showLine: bool=?,
      ~onCheck: ('check, treeNodeCheckedEvent) => unit=?,
      ~onDragEnd: treeNodeMouseEvent => unit=?,
      ~onDragEnter: treeNodeMouseEvent => unit=?,
      ~onDragLeave: treeNodeMouseEvent => unit=?,
      ~onDragOver: treeNodeMouseEvent => unit=?,
      ~onDragStart: treeNodeMouseEvent => unit=?,
      ~onDrop: treeNodeDropEvent => unit=?,
      ~onExpand: (array(string), treeNodeExpandedEvent) => Js.Promise.t(unit)
                   =?, // promise type skipped
      ~onLoad: (array(string), {. "node": treeNode}) => unit=?,
      ~onRightClick: treeNodeMouseEvent => unit=?,
      ~onSelect: (array(string), treeNodeSelectedEvent) => unit=?,
      ~className: string=?,
      // ***** END TREE *****
      ~children: element=?,
      unit
    ) =>
    element =
    "default";

  module ExpandAction = {
    type t;

    let false_: t = [%raw {| false |}];
    let click: t = [%raw {| "click" |}];
    let doubleClick: t = [%raw {| "doubleClick" |}];
  };

  module DirectoryTree = {
    [@react.component] [@bs.module "antd/es/tree/DirectoryTree"]
    // ***** BEGIN TREE *****
    external make:
      (
        ~autoExpandParent: bool=?,
        ~blockNode: bool=?,
        ~checkable: bool=?,
        ~checkedKeys: 'check=?,
        ~checkStrictly: CheckStrictly.t('check), // requried
        ~defaultCheckedKeys: array(string)=?, // always str[], does not depend on checkStrictly
        ~defaultExpandAll: bool=?,
        ~defaultExpandedKeys: array(string)=?,
        ~defaultExpandParent: bool=?,
        ~defaultSelectedKeys: array(string)=?,
        ~disabled: bool=?,
        ~draggable: bool=?,
        ~expandedKeys: array(string)=?,
        ~filterTreeNode: treeNode => bool=?,
        ~loadData: treeNode => Js.Promise.t(unit)=?, // web example does not resolve, it just does setState
        ~loadedKeys: array(string)=?,
        ~multiple: bool=?,
        ~selectedKeys: array(string)=?,
        ~showIcon: bool=?,
        ~switcherIcon: element=?,
        ~showLine: bool=?,
        ~onCheck: ('check, treeNodeCheckedEvent) => unit=?,
        ~onDragEnd: treeNodeMouseEvent => unit=?,
        ~onDragEnter: treeNodeMouseEvent => unit=?,
        ~onDragLeave: treeNodeMouseEvent => unit=?,
        ~onDragOver: treeNodeMouseEvent => unit=?,
        ~onDragStart: treeNodeMouseEvent => unit=?,
        ~onDrop: treeNodeDropEvent => unit=?,
        ~onExpand: (array(string), treeNodeExpandedEvent) =>
                   Js.Promise.t(unit)
                     =?, // promise type skipped
        ~onLoad: (array(string), {. "node": treeNode}) => unit=?,
        ~onRightClick: treeNodeMouseEvent => unit=?,
        ~onSelect: (array(string), treeNodeSelectedEvent) => unit=?,
        ~className: string=?,
        // ***** END TREE *****
        // ***** BEGIN DIRECTORY TREE *****
        ~expandAction: ExpandAction.t=?,
        // ***** END DIRECTORY TREE *****
        ~children: element=?,
        unit
      ) =>
      element =
      "default";
  };
};