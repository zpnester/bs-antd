open React;
open Antd;
open Menu;
open Expect_;

let expectClickParam = e => {
  expectString(e##key);
  expectStringArray(e##keyPath);
  expectReactElementObj(e##item)
  expectSynEvent(e##domEvent);
};

let expectSelectParam = e => {
  expectString(e##key);
  expectStringArray(e##keyPath);
  expectStringArray(e##selectedKeys);
  expectReactElementObj(e##item)
  expectSynEvent(e##domEvent);
};

let expectMouseEnter = e => {
  expectString(e##key);
  expectReactMouseEvent(e##domEvent);
};

let expectSynKey = e => {
  expectString(e##key);
  expectSynEvent(e##domEvent);
};

[@react.component]
let make = () => {
  <>
    <h1 id="menu-example"> {string("Menu Example")} </h1>
    <Menu mode=`horizontal
    theme=`dark
    onMouseEnter={e => {
      ()
    }}
    multiple=true
      onDeselect={e => {
        expectSelectParam(e);
      }}
      onSelect={e => {
        expectSelectParam(e);
      }}
      onClick={e => {
         expectClickParam(e);
      }}
      // overflowedIndicator=string("over")
    >

        <Menu.Item 
        onMouseEnter={e => {
          expectMouseEnter(e);
        }}
        onMouseLeave={e => {
          expectMouseEnter(e);
        }}
        >
          <Icon _type=Icon.Type.mail />
          {string("Navigation One")}
        </Menu.Item>
        <Menu.Item key="app" disabled=false>
          <Icon _type=Icon.Type.appstore />
          {string("Navigation Two")}
        </Menu.Item>
        <Menu.SubMenu
        onTitleClick={e => {
          expectSynKey(e);
        }}
        onTitleMouseEnter={e => {
          expectSynKey(e);
        }}
        onTitleMouseLeave={e => {
          expectSynKey(e);
        }}
        
          title={
            <span className="submenu-title-wrapper">
              <Icon _type=Icon.Type.setting />
              {string("Navigation Three - Submenu")}
            </span>
          }>
          <Menu.ItemGroup title={string("Item 1")}>
            <Menu.Item key="setting:1"> {string("Option 1")} </Menu.Item>
            <Menu.Item key="setting:2"> {string("Option 2")} </Menu.Item>
          </Menu.ItemGroup>
        </Menu.SubMenu>
        <Menu.Item key="alipay">
          <a
            href="https://ant.design"
            target="_blank"
            rel="noopener noreferrer">
            {string("Navigation Four - Link")}
          </a>
        </Menu.Item>
      </Menu>
  </>;
};