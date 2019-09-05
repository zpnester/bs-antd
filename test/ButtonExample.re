open Antd;
open Button;
open React;

[@react.component]
let make = () => {

  <>
    <h1 id="button-example"> {string("Button Example")} </h1>
    <Button
      shape=Shape.round
      type_=Type.primary
      size=Size.large
      onClick={e => {
        Js.log("click")
      }}>
      {string("Button 1")}
    </Button>
    <Button
      onClick={e => Js.log("click")}
      shape=Shape.circle
      type_=Type.danger
      loading={Loading.bool(true)}
      size=Size.large
    />
  </>;
};