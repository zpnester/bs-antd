open React;
open Antd;
open Modal;

[@react.component]
let make = () => {
  let (m1, setM1) = useState(() => false);

  <>
    <h1 id="modal-example"> {string("Modal Example")} </h1>
    <button onClick={_ => setM1(_ => true)}> {string("show modal")} </button>
    <button
      onClick={_ => {
        let d =
          Modal.error(
            Config.make(
              ~content=string("Error content"),
              ~okType=`dashed,
              ~okText=string("Okay"),
              ~okCancel=true,
              (),
            ),
          );

        Js.Global.setTimeout(() => d->Dialog.destroy, 3000) |> ignore;
      }}>
      {string("show error and destroy")}
    </button>
    <button
      onClick={_ => {
        Modal.warning(Config.make(~content=string("First"), ()));

        Js.Global.setTimeout(
          () =>
            Modal.warning(Config.make(~content=string("Second"), ()))
            |> ignore,
          1000,
        )
        |> ignore;

        Js.Global.setTimeout(() => Modal.destroyAll(), 3000) |> ignore;
      }}>
      {string("show 2 modals and destroy all")}
    </button>
    <Modal
      visible=m1
      onOk={e => {
        // Js.log2("onOk", e);
        setM1(_ => false);
        Js.Promise.resolve();
      }}
      onCancel={e => {
        // Js.log2("onCancel", e);
        setM1(_ => false);

        Js.Promise.resolve();
      }}>
      {string("Modal content")}
    </Modal>
  </>;
};