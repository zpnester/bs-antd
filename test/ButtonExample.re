open Antd;
open Button;
open React;

[@react.component]
let make = () => {
  <>
    <h1 id="button-example"> {string("Button Exampl")} </h1>
    <Button
      shape=`round
      _type=`primary
      size=`large
      onClick={e => Js.log("click")}>
      {string("Button 1")}
    </Button>
    <Button
      onClick={e => Js.log("click")}
      shape=`circle
      _type=`danger
      loading=Loading.bool(true)
      size=`large
    />
  </>;
};
