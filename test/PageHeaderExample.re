open React;
open Antd;
open PageHeader;

[@react.component]
let make = () => {
  <>
    <h1 id="pageheader-example"> {string("PageHeader Example")} </h1>
    <PageHeader
      title={string("Title")}
      subTitle={string("Subtitle")}
      onBack={e => Js.log2("onBack", e)}
    />
  </>;
};