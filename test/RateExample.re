open Antd;
open React;
open Rate;
open Expect_;

[@react.component]
let make = () => {
  <>
    <h1 id="rate-example"> {string("Rate Example")} </h1>
    <Rate
      allowHalf=true
      onChange={f =>
        // Js.log2("onChange", f);
        expectNumber(f)}
      tooltips=[|"One", "Two", "Three"|]
    />
  </>;
};