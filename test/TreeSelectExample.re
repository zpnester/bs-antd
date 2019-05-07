open React;
open Antd;
open TreeSelect;
open Expect_;
open Js.Promise;

module TreeNode = TreeSelect.TreeNode;

let expectLabeledValue = x => {
  expectString(x##value);
  expectElement(x##label);
};

// let expectNullLabeledValue = expectNullOf(expectLabeledValue);

let expectLabeledValueArray = expectArrayOf(expectLabeledValue);

let expectLabeledValueOption = expectOptionOf(expectLabeledValue);

let expectTreeNode = treeNode => {
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
};

[@react.component]
let make = () => {
  let (value, setValue) =
    useState(() => [|{"value": "1-0", "label": null}|]);

  let (value2, setValue2) =
    useState(() => Some({"value": "1-0", "label": null}));

  let t =
    <b style={ReactDOMRe.Style.make(~color="#08c", ())}>
      {string("sss")}
    </b>;

  let treeData = [|
    Node.make(
      ~value="a",
      ~title=string("A"),
      ~children=[|Node.make(~value="aa", ~title=string("AA"), ())|],
      (),
    ),
    Node.make(~value="b", ~title=string("B"), ()),
  |];

  <>
    <h1 id="treeselect-example"> {string("TreeSelect Example")} </h1>
    <TreeSelect
      labelInValue=LabelInValue.true_
      treeCheckStrictly=TreeCheckStrictly.true_
      maxTagCount=2
      maxTagPlaceholder={omitted => {
        expectLabeledValueArray(omitted);
        string("+++");
      }}
      multiple=Multiple.true_
      showSearch=true
      style={ReactDOMRe.Style.make(~width="300px", ())}
      value
      dropdownStyle={ReactDOMRe.Style.make(
        ~maxHeight="400px",
        ~overflow="auto",
        (),
      )}
      placeholder={string("Please select")}
      allowClear=true
      treeDefaultExpandAll=true
      onSearch={x => expectString(x)}
      loadData={node => {
        expectTreeNode(node);
        resolve();
      }}
      onBlur={e => expectFocusEvent(e)}
      onSelect={value => expectLabeledValue(value)}
      onChange={(value, b, extra) => {
        expectLabeledValueArray(value);
        // TODO b
        expectObject(extra);

        setValue(_ => value);
      }}>
      <TreeNode
        value="parent 1" title={<h2> {string("parent 1")} </h2>} key="0-1">
        <TreeNode value="parent 1-0" title={string("parent 1-0")} key="0-1-1">
          <TreeNode value="leaf1" title={string("my leaf")} key="random" />
          <TreeNode value="leaf2" title={string("your leaf")} key="random1" />
        </TreeNode>
        <TreeNode
          value="parent 1-1"
          label={string("Parent 1-1 label")}
          title={string("parent 1-1")}
          key="random2">
          <TreeNode value="sss" title=t key="random3" />
        </TreeNode>
      </TreeNode>
    </TreeSelect>
    <h2> {string("multiple: false")} </h2>
    <TreeSelect
      labelInValue=LabelInValue.true_
      treeCheckStrictly=TreeCheckStrictly.true_
      filterTreeNode={(s, node) => {
        [%debugger];
        expectString(s);
        expectTreeNode(node);
        true;
      }}
      loadData={node => {
        expectTreeNode(node);
        resolve();
      }}
      multiple=Multiple.false_
      showSearch=true
      onSearch={x => expectString(x)}
      onSelect={value => expectLabeledValue(value)}
      value=value2
      dropdownStyle={ReactDOMRe.Style.make(
        ~maxHeight="400px",
        ~overflow="auto",
        (),
      )}
      placeholder={string("Please select")}
      style={ReactDOMRe.Style.make(~width="300px", ())}
      allowClear=true
      treeDefaultExpandAll=true
      onChange={(value, b, extra) => {
        expectLabeledValueOption(value);
        // TODO b
        expectObject(extra);

        setValue2(_ => value);
      }}>
      <TreeNode
        value="parent 1" title={<h2> {string("parent 1")} </h2>} key="0-1">
        <TreeNode value="parent 1-0" title={string("parent 1-0")} key="0-1-1">
          <TreeNode value="leaf1" title={string("my leaf")} key="random" />
          <TreeNode value="leaf2" title={string("your leaf")} key="random1" />
        </TreeNode>
        <TreeNode
          value="parent 1-1"
          label={string("Parent 1-1 label")}
          title={string("parent 1-1")}
          key="random2">
          <TreeNode value="sss" title=t key="random3" />
        </TreeNode>
      </TreeNode>
    </TreeSelect>
    <h2> {string("With treeData single")} </h2>
    <TreeSelect
      treeData
      showSearch=true
      onSelect={value => expectLabeledValue(value)}
      style={ReactDOMRe.Style.make(~width="300px", ())}
      onChange={(value, b, extra) => {
        expectLabeledValueOption(value);
        // TODO b
        expectObject(extra);
      }}
      allowClear=true
      multiple=Multiple.false_
      labelInValue=LabelInValue.true_
    />
    <h2> {string("With treeData multiple")} </h2>
    <TreeSelect
      treeData
      allowClear=true
      showSearch=true
      style={ReactDOMRe.Style.make(~width="300px", ())}
      onSelect={value => expectLabeledValue(value)}
      onChange={(value, b, extra) => {
        expectLabeledValueArray(value);
        // TODO b
        expectObject(extra);
      }}
      multiple=Multiple.true_
      labelInValue=LabelInValue.true_
    />
  </>;
};