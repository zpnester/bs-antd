open React;
open Antd;
open Notification;
open Expect_;

Notification.config(GlobalConfig.make(~bottom=5.0, ()));

[@react.component]
let make = () => {
  <>
    <h1 id="notification-example"> {string("Notification Example")} </h1>
    <button
      onClick={_ => {
        Notification.info(
          Config.make(~key="a", 
          ~onClose={() => {
            Js.log("onClose");
          }},
          ~placement=`bottomRight,
          ~onClick={e => {
            expectReactMouseEvent(e);
            Js.log("notification click");
          }},
          ~message=string("Message content"), ()),
        )
      }}>
      {string("Show")}
    </button>
    <button onClick={_ => {
      
      Notification.close("a")
      
      }}>
      {string("Close")}
    </button>
    <button onClick={_ => Notification.destroy()}>
      {string("Destroy")}
    </button>
  </>;
};