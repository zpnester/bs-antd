open React;
open Antd;
open Js.Promise;

Message.config(Message.GlobalConfig.make(~top=50.0, ()));

[@react.component]
let make = () => {
  <>
    <h1 id="message-example"> {string("Message Example")} </h1>
    <button
      onClick={_ => {
        let m = Message.success(string("This is success"));
        m##promise
        |> then_(()
             // Js.log("after close promise");
             => resolve())
        |> ignore;
      }}>
      {string("info")}
    </button>
    <button
      onClick={_ => {
        let m =
          Message.open_(
            Message.Config.make(
              ~content=string("This is custom icon"),
              // ~onClose={() => {
              //     // Js.log("onClose");
              // }},
              ~_type=`warning,
              ~duration=Js.Null.return(5.0),
              ~icon={<Icon _type=Icon.Type.user />},
              (),
            ),
          );
        // Js.log2("m", m);

        m##promise
        |> then_(()
             // Js.log("after close promise");
             => resolve())
        |> ignore;
      }}>
      {string("open")}
    </button>
    <button
      onClick={_ =>
        Message.loading(string("Something is loading")) |> ignore
      }>
      {string("loading")}
    </button>
    <button onClick={_ => Message.destroy()}> {string("destroy")} </button>
  </>;
};