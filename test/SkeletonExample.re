open React;
open Antd;
open Skeleton;

[@react.component]
let make = () => {
  <>
    <h1 id="skeleton-example"> {string("Skeleton Example")} </h1>
    // TODO better example
    <Skeleton active=true />
  </>;
};