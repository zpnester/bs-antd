open React;
open Antd;
open TreeSelect;
open Expect_;


module TreeNode = TreeSelect.TreeNode;

[@react.component]
let make = () => {

    let (value, setValue) = useState(() => [||]);
    let t = <b style={ReactDOMRe.Style.make(~color="#08c", ())}>{string("sss")}</b>;

    <>
        <h1 id="treeselect-example">{string("TreeSelect Example")}</h1>
        
        <TreeSelect
            showSearch=true
            style={ReactDOMRe.Style.make(~width="300", ())}
            value
            dropdownStyle={ReactDOMRe.Style.make(~maxHeight="400", ~overflow="auto", ())}
            placeholder="Please select"
            allowClear=true
            treeDefaultExpandAll=true
            onChange={(value, b, c) => {
                Js.log4("onChange", value, b, c);
                
                // TODO
                setValue(_ => value)
        }}
      >
        <TreeNode value="parent 1" title=string("parent 1") key="0-1">
          <TreeNode value="parent 1-0" title=string("parent 1-0") key="0-1-1">
            <TreeNode value="leaf1" title=string("my leaf") key="random" />
            <TreeNode value="leaf2" title=string("your leaf") key="random1" />
          </TreeNode>
          <TreeNode value="parent 1-1" title=string("parent 1-1") key="random2">
            <TreeNode value="sss" title={t} key="random3" />
          </TreeNode>
        </TreeNode>
      </TreeSelect>

        
    </>
};