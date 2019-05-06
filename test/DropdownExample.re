open React;

module Dropdown = Antd.Dropdown;
module Button = Antd.Button;
module Menu = Antd.Menu;
module Icon = Antd.Icon;

[@react.component]
let make = () => {
  let menu =
    <Menu>
      <Menu.Item>
        <a target="_blank" rel="noopener noreferrer" href="#">
          {string("1st menu item")}
        </a>
      </Menu.Item>
      <Menu.Item>
        <a target="_blank" rel="noopener noreferrer" href="#">
          {string("2nd menu item")}
        </a>
      </Menu.Item>
      <Menu.Item>
        <a target="_blank" rel="noopener noreferrer" href="#">
          {string("3rd menu item")}
        </a>
      </Menu.Item>
    </Menu>;

  let onButtonClick = _ => {
    Antd.Message.info(string("Menu button clicked")) |> ignore;
  };

  <>
    <h1 id="dropdown-example"> {string("Dropdown Example")} </h1>
    <Dropdown overlay={() => menu}>
      <a className="ant-dropdown-link" href="#">
        {string("Hover me")}
        <Icon _type="down" />
      </a>
    </Dropdown>
    <Dropdown overlay={() => menu} placement=`bottomLeft>
      <Button> {string("bottomLeft")} </Button>
    </Dropdown>
    <Dropdown overlay={() => menu} placement=`bottomCenter>
      <Button> {string("bottomCenter")} </Button>
    </Dropdown>
    <br />
    <Dropdown.Button onClick=onButtonClick overlay={() => menu}>
      {string("Dropdown")}
    </Dropdown.Button>
    <Dropdown.Button
      onClick=onButtonClick
      overlay={() => menu}
      disabled=true
      style={ReactDOMRe.Style.make(~marginLeft="8", ())}>
      {string("Dropdown")}
    </Dropdown.Button>
    <Dropdown overlay={() => menu}>
      <Button style={ReactDOMRe.Style.make(~marginLeft="8", ())}>
        {string("Button")}
        <Icon _type="down" />
      </Button>
    </Dropdown>
  </>;
};