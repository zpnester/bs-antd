open React;
open Antd;
open Notification;

Notification.config(GlobalConfig.make(~bottom=5.0, ()));

[@react.component]
let make = () => {
  <>
    <h1 id="notification-example"> {string("Notification Example")} </h1>
    <button
      onClick={_ =>
        Notification.info(
          Config.make(~key="a", ~message=string("Message content"), ()),
        )
      }>
      {string("Show")}
    </button>
    <button onClick={_ => Notification.close("a")}>
      {string("Close")}
    </button>
    <button onClick={_ => Notification.destroy()}>
      {string("Destroy")}
    </button>
  </>;
};