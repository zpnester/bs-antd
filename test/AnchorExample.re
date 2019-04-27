open React;
open Antd;

[@react.component]
let make = () => {
  <>
    <h1>{string("Anchor Example")}</h1>
    <Anchor>
      <Anchor.Link href="#alert-example" title={string("Alert Example")} />
      <Anchor.Link href="#avatar-example" title={string("Avatar Example")} />
      <Anchor.Link href="#breadcrumb-example" title={string("Breadcrumb Example")} />
      <Anchor.Link href="#affix-example" title={string("Affix Example")} />
      
    </Anchor>
  </>;
};
