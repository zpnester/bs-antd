open React;
open Antd;
open Popconfirm;
open Expect_;

[@react.component]
let make = () => {
  <>
    <h1 id="popconfirm-example"> {string("Popconfirm Example")} </h1>
    <Popconfirm
      title={string("Are you sure delete this task?")}
      onConfirm={e => Js.log2("onConfirm", e)}
      onCancel={e => Js.log2("onCancel", e)}
      okText={string("Yes")}
      cancelText={string("No")}
      onVisibleChange={visible =>
        expectBool(
          visible,
          //   Js.log2("onVisibleChange", visible);
        )
      }>
      <a href="#"> {string("Delete")} </a>
    </Popconfirm>
  </>;
};