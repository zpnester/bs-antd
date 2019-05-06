open React;
open Antd;
open Expect_;

[@react.component]
let make = () => {
  <>
    <h1 id="alert-example"> {string("Alert Example")} </h1>
    <Alert
      message={string("Alert 1")}
      _type=`success
      closable=true
      closeText={string("CLOSE")}
      onClose={event =>
        expectToEqual(
          event->ReactEvent.Mouse.clientX->Js.typeof,
          "number",
          // Js.log("on close");
        )
      }
      // afterClose={() => {
      //   // Js.log("after close")
      //   }}
    />
    <Alert
      message={string("Alert 2")}
      _type=`error
      closable=false
      showIcon=true
      iconType=Icon.Type.pieChart
    />
    <Alert
      message={string("Alert 3")}
      _type=`info
      description={string("This is info")}
    />
    <Alert
      message={string("Alert 4")}
      _type=`warning
      showIcon=true
      banner=true
    />
    <Alert
      message={string("Alert 5")}
      _type=`warning
      showIcon=true
      icon={string("X")}
    />
  </>;
};