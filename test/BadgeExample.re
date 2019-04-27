open Antd;
open Badge;
open React;

[@react.component]
let make = () => {
  let style =
    ReactDOMRe.Style.make(
      ~width="42px",
      ~height="42px",
      ~borderRadius="4px",
      ~display="inline-block",
      ~background="#eee",
      ~verticalAlign="middle",
      ~marginLeft="20px",
      (),
    );
  <>
    <h1> {string("Badge Example")} </h1>
    <div>
      <Badge count={string("5")}> <a href="#" style /> </Badge>
      <Badge count={<Icon _type=Icon.Type.clockCircle />}>
        <a href="#" style />
      </Badge>
      <br />
      <Badge
        count={string("109")}
        style={ReactDOMRe.Style.make(~backgroundColor="#52c41a", ())}
      />
      <br />
      <Badge status=Status.processing text={string("...")} />
      <br />
      <Badge status=Status.error text={string("!")} />
      <br />
    </div>
  </>;
};
