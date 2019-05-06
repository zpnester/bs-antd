open Antd;
open BackTop;
open React;

[@react.component]
let make = () => {
  <>
    <h1> {string("BackTop Example")} </h1>
    {string("Scroll down to see the bottom-right button")}
    <BackTop />
  </>;
};