open React;
open Antd;

[@react.component]
let customIcon = () => {
  string("_O_");
};

[@react.component]
let make = () => {
  <>
    <h1>{string("Icon Example")}</h1>
    <Icon _type=Icon.Type.copy theme=Icon.Theme.filled rotate=45.0 tabIndex=3 />
    <Icon _type=Icon.Type.copy theme=Icon.Theme.outlined spin=true tabIndex=3 />
    <Icon
      _type=Icon.Type.copy
      theme=Icon.Theme.twoTone
      title="icon title"
      twoToneColor="red"
      tabIndex=3
      role="custom-role"
      onKeyUp={e => Js.log2("icon key up", e->ReactEvent.Keyboard.keyCode)}
      onClick={e => Js.log2("icon click", e)}
    />
    <Icon component=customIcon />
  </>;
};
