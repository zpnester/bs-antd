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
      onKeyDown={e => {
        ()
      }}
      onBlur={() => {
        ()
      }}
      onChange={f => {
        expectNumber(f)
        }}
      tooltips=[|"One", "Two", "Three"|]
    />
  </>;
};