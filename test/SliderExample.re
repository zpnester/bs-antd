open React;
open Antd;
open Slider;
open Expect_;

[@react.component]
let make = () => {
  <>
    <h1 id="slider-example"> {string("Slider Example")} </h1>
    <Slider
      range=Range.false_
      onChange={v =>
        // Js.log2("conChange", v)
        expectNumber(v)}
      onAfterChange={v =>
        // Js.log2("onAfterChange", v)
        expectNumber(v)}
    />
    <Slider
      range=Range.true_
      step={Js.Null.return(0.3)}
      onChange={v =>
        // Js.log2("conChange", v);
        expectNumberTuple2(v)}
      onAfterChange={v =>
        // Js.log2("onAfterChange", v)
        expectNumberTuple2(v)}
    />
  </>;
};