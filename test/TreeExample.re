open React;
open Expect_;
open Js.Promise;

// type data = {
//     .
//     "title": string,
//     "key": string,
//     "isLeaf": bool
// };

type data = {
  title: string,
  key: string,
  isLeaf: bool,
  mutable children: array(data),
};

module Icon = Antd.Icon;

module Tree = Antd.Tree;
module TreeNode = Tree.TreeNode;

module Tree1 =
  Antd.Tree.Make({
    type dataRef = string;
  });
module TreeNode1 = Tree1.TreeNode;

module Tree2 =
  Antd.Tree.Make({
    type dataRef = data;
  });
module TreeNode2 = Tree2.TreeNode;

let expectTreeNode = (f, treeNode) => {
  expectReactElement(treeNode);
  expectBool(treeNode##props##checked);
  expectBool(treeNode##props##dragOver);
  expectBool(treeNode##props##dragOverGapTop);
  expectBool(treeNode##props##dragOverGapBottom);
  expectString(treeNode##props##eventKey);
  expectBool(treeNode##props##expanded);
  expectBool(treeNode##props##halfChecked);
  expectBool(treeNode##props##loaded);
  expectBool(treeNode##props##loading);
  expectString(treeNode##props##pos);
  expectBool(treeNode##props##selected);
  expectElement(treeNode##props##title);
  f(treeNode##props##dataRef);
};

let expectTreeNodeProps = (f, props) => {
  expectBool(props##checked);
  expectBool(props##dragOver);
  expectBool(props##dragOverGapTop);
  expectBool(props##dragOverGapBottom);
  expectString(props##eventKey);
  expectBool(props##expanded);
  expectBool(props##halfChecked);
  expectBool(props##loaded);
  expectBool(props##loading);
  expectString(props##pos);
  expectBool(props##selected);
  expectElement(props##title);
  f(props##dataRef);
};

let dataRef = "custom data";

let expectCustomData = d => {
  expectToEqual(d, dataRef);
};

let expectTreeNode1 = expectTreeNode(expectCustomData);

let expectTreeNodeProps1 = expectTreeNodeProps(expectCustomData);

// let expeectTreeNodeArray = (xs) => {
//     expectArray(xs);
//     xs->Array.forEach(expectTreeNode);
// };

// TODO remove
// let expectTreeNodeLess = (t: treeNodeLess) => {
//     expectString(t##props##key);
//     expectElement(t##props##title);
//     expectElement(t##props##children);
// };

// let expectTreeNodeLessArray = expectArrayOf(expectTreeNodeLess);

let expectTreeMouseEvent = (f, e) => {
  expectTreeNode(f, e##node);
  e##event->ReactEvent.Mouse.persist;
  expectReactMouseEvent(e##event);
};

let expectTreeMouseEvent1 = expectTreeMouseEvent(expectCustomData);

let expectTreeSelectedEvent = e => {
  expectBool(
    e##selected,
    // expeectTreeNodeArray(e##selectedNodes);
  );
};

let expectStrictCheck = sc => {
  expectStringArray(sc##checked);
  expectStringArray(sc##halfChecked);
};

[@react.component]
let make = () => {
  Js.log("render");

  let t =
    <span style={ReactDOMRe.Style.make(~color="#1890ff", ())}>
      {string("LEAF")}
    </span>;

  // let initTreeData = [|
  //     { "title": "Expand to load", "key": "0", "isLeaf": false },
  //   { "title": "Expand to load", "key": "1", "isLeaf": false },
  //   {"title": "Tree Node", "key": "2", "isLeaf": true },
  // |];
  let initTreeData = [|
    {title: "Expand to load", key: "0", isLeaf: false, children: [||]},
    {title: "Expand to load", key: "1", isLeaf: false, children: [||]},
    {title: "Tree Node", key: "2", isLeaf: true, children: [||]},
  |];

  let (treeData, setTreeData) = useState(() => initTreeData);

  let onLoadData = (node): Js.Promise.t(unit) => {
    Js.Promise.make((~resolve, ~reject) =>
      switch (node##props##dataRef.children) {
      | empty when empty->Array.length == 0 =>
        Js.Global.setTimeout(
          () => {
            node##props##dataRef.children = [|
              {
                title: "Child Node 1",
                key: node##props##eventKey ++ "-0",
                isLeaf: false,
                children: [||],
              },
              {
                title: "Child Node 2",
                key: node##props##eventKey ++ "-1",
                isLeaf: false,
                children: [||],
              },
            |];
            // mutated above
            setTreeData(data => data->Array.map(x => x));
            resolve(. "");
          },
          1000,
        )
        |> ignore
      | _ => resolve(. "")
      }
    )
    |> then_(_ => resolve());
  };

  let rec renderTreeNodes = data => {
    data->Array.map(item =>
      switch (item.children) {
      | children when children->Array.length > 0 =>
        <TreeNode2 title={string(item.title)} key={item.key} dataRef=item>
          {renderTreeNodes(children)}
        </TreeNode2>
      | _ =>
        <TreeNode2
          title={string(item.title)}
          key={item.key}
          dataRef=item
          isLeaf={item.isLeaf}
        />
      }
    )
    |> array;
  };

  <>
    <h1 id="tree-example"> {string("Tree Example")} </h1>
    <Tree2 loadData=onLoadData checkStrictly=Tree2.CheckStrictly.false_>
      {renderTreeNodes(treeData)}
    </Tree2>
    <Tree1
      checkStrictly=Tree1.CheckStrictly.false_
      loadData={treeNode => {
        expectTreeNode1(treeNode);
        Js.log2("loadData", treeNode);
        resolve();
      }}
      filterTreeNode={node => {
        expectTreeNode1(node);
        true;
      }}
      onLoad={(ss, e) => {
        expectStringArray(ss);
        expectTreeNode1(e##node);
        Js.log3("onLoad", ss, e);
      }}
      onRightClick={e => {
        Js.log("onRightClick");
        expectTreeMouseEvent1(e);
      }}
      checkable=true
      defaultExpandedKeys=[|"0-0-0", "0-0-1"|]
      defaultSelectedKeys=[|"0-0-0", "0-0-1"|]
      // defaultCheckedKeys={[|"0-0-0", "0-0-1"|]}
      onSelect={(selectedKeys, e) => {
        expectStringArray(selectedKeys);
        expectTreeSelectedEvent(e);
      }}
      onExpand={(ss, e) => {
        expectStringArray(ss);
        expectTreeNode1(e##node);
        expectBool(e##expanded);
        expectDomMouseEvent(e##nativeEvent);
        resolve();
      }}
      onCheck={(x, e) => {
        expectStringArray(x);
        expectTreeNode1(e##node);
        expectBool(e##checked);
      }}
      onDragStart={e => expectTreeMouseEvent1(e)}
      onDragEnd={e => {
        expectTreeNode1(e##node);
        e##event->ReactEvent.Mouse.persist;
        expectReactMouseEvent(e##event);
      }}
      onDragEnter={e => {
        expectTreeNode1(e##node);
        e##event->ReactEvent.Mouse.persist;
        expectReactMouseEvent(e##event);
      }}
      onDragLeave={e => {
        expectTreeNode1(e##node);
        e##event->ReactEvent.Mouse.persist;
        expectReactMouseEvent(e##event);
      }}
      onDragOver={e => {
        expectTreeNode1(e##node);
        e##event->ReactEvent.Mouse.persist;
        expectReactMouseEvent(e##event);
      }}
      onDrop={e => {
        expectStringArray(e##dragNodesKeys);
        expectNumber(e##dropPosition);
        expectBool(e##dropToGap);
        expectTreeNode1(e##node);
        expectTreeNode1(e##dragNode);
        e##event->ReactEvent.Mouse.persist;
        expectReactMouseEvent(e##event);
      }}
      draggable=true
      defaultCheckedKeys=[|"0-0-0-0", "0-0-0-1"|]
      showIcon=true>
      <TreeNode1
        title={string("parent 1")}
        key="0-0"
        dataRef
        icon={props => {
          expectTreeNodeProps1(props);
          <Icon _type=Icon.Type.user />;
        }}>
        <TreeNode1 key="0-0-0" dataRef disabled=false>
          <TreeNode1
            title={string("0-0-0-0")}
            key="0-0-0-0"
            dataRef
            disableCheckbox=false
          />
          <TreeNode1 dataRef title={string("0-0-0-1")} key="0-0-0-1" />
        </TreeNode1>
        <TreeNode1 title={string("parent 1-1")} key="0-0-1" dataRef>
          <TreeNode1 dataRef isLeaf=true title=t key="0-0-1-0" />
        </TreeNode1>
      </TreeNode1>
    </Tree1>
    <Tree1
      checkStrictly=Tree1.CheckStrictly.true_
      checkable=true
      autoExpandParent=true
      // defaultCheckedKeys=[|
      //     "0-0-0-0",
      //     "0-0-0-1"
      // |]
      checkedKeys={"checked": [|"0-0-0-0"|], "halfChecked": [|"0-0-0-1"|]}
      onCheck={(check, e) => {
        expectStrictCheck(check);
        expectTreeNode1(e##node);
        expectBool(e##checked);
      }}>
      <TreeNode1 title={string("parent 1")} key="0-0" dataRef>
        <TreeNode1 title={string("parent 1-0")} key="0-0-0" dataRef>
          <TreeNode1 title={string("0-0-0-0")} key="0-0-0-0" dataRef />
          <TreeNode1 dataRef title={string("0-0-0-1")} key="0-0-0-1" />
        </TreeNode1>
        <TreeNode1 title={string("parent 1-1")} key="0-0-1" dataRef>
          <TreeNode1
            dataRef
            isLeaf=true
            title={string("0-0-1-0")}
            key="0-0-1-0"
          />
        </TreeNode1>
      </TreeNode1>
    </Tree1>
    <Tree.DirectoryTree
      checkStrictly=Tree.CheckStrictly.false_
      multiple=true
      defaultExpandAll=true>
      <TreeNode title={string("parent 0")} key="0-0">
        <TreeNode title={string("leaf 0-0")} key="0-0-0" isLeaf=true />
        <TreeNode title={string("leaf 0-1")} key="0-0-1" isLeaf=true />
      </TreeNode>
      <TreeNode title={string("parent 1")} key="0-1">
        <TreeNode title={string("leaf 1-0")} key="0-1-0" isLeaf=true />
        <TreeNode title={string("leaf 1-1")} key="0-1-1" isLeaf=true />
      </TreeNode>
    </Tree.DirectoryTree>
  </>;
};