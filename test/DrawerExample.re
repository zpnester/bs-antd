open Antd;
open React;
open Drawer;

[@react.component]
let make = () => {
  let (drawerOpen, setDrawerOpen) = useState(() => false);

  <>
    <h1 id="drawer-example"> {string("Drawer Example")} </h1>
    <button onClick={_ => setDrawerOpen(o => !o)}>
      {string("Toggle drawer")}
    </button>
    <Drawer
      title={string("Drawer title")}
      placement=`right
      onClose={e =>
        // Js.log2("onClose", e);
        setDrawerOpen(_ => false)}
      visible=drawerOpen>
      <p> {string("Drawer content")} </p>
    </Drawer>
  </>;
};