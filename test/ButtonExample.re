open Antd;
open Button;
open React;

[@react.component]
let make = () => {
  <>
    <h1 id="button-example"> {string("Button Exampl")} </h1>
    <Button
      shape=Shape.round
      _type=Type.primary
      size=Size.large
      onClick={e => Js.log("click")}>
      {string("Button 1")}
    </Button>
    <Button
      onClick={e => Js.log("click")}
      shape=Shape.circle
      _type=Type.danger
      loading=Loading.bool(true)
      size=Size.large
    />
  </>;
};
