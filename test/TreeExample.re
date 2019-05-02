open React;
open Antd;
open Tree;
open Expect_;

module TreeNode = Tree.TreeNode;

[@react.component]
let make = () => {

let t = <span style={ReactDOMRe.Style.make(~color="#1890ff", ())}>
                            {string("sss")}
                        </span>;

    <>
        <h1 id="tree-example">{string("Tree Example")}</h1>
        <h1>{string("TODO improve tree typings")}</h1>
         <Tree
            checkable=true
            defaultExpandedKeys={[|"0-0-0", "0-0-1"|]}
            defaultSelectedKeys={[|"0-0-0", "0-0-1"|]}
            defaultCheckedKeys={[|"0-0-0", "0-0-1"|]}
            onSelect={(selectedKeys, info) => {
                Js.log3("onSelect", selectedKeys, info);
            }}
            onCheck={(checkedKeys, info) => {
                Js.log3("onCheck", checkedKeys, info);
            }}
        >
            <TreeNode title=string("parent 1") key="0-0">
                <TreeNode title=string("parent 1-0") key="0-0-0" disabled=true>
                    <TreeNode title=string("leaf") key="0-0-0-0" disableCheckbox=true />
                    <TreeNode title=string("leaf") key="0-0-0-1" />
                </TreeNode>
                <TreeNode title=string("parent 1-1") key="0-0-1">
                    <TreeNode 
                        title={t} key="0-0-1-0" />
                    </TreeNode>
                </TreeNode>
        </Tree>
        
    </>
};