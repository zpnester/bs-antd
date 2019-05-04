
open React;
open Antd;
open Menu;

[@react.component]
let make = () => {

    <>
        <h1 id="menu-example">{string("Menu Example")}</h1>

        <Menu mode=`horizontal
        //  onClick={e => {
        //     // Js.log2("menu click", e)
        // }}
        >
            <Menu.Item>
                <Icon _type={Icon.Type.mail}/>
                {string("Navigation One")}
            </Menu.Item>
            <Menu.Item key="app" disabled=false>
                <Icon _type={Icon.Type.appstore}/>
                {string("Navigation Two")}
            </Menu.Item>

            <Menu.SubMenu title={
                <span className="submenu-title-wrapper">
                    <Icon _type=Icon.Type.setting />
                    {string("Navigation Three - Submenu")}
                </span>
                }>
                <Menu.ItemGroup title={string("Item 1")}>
                     <Menu.Item key="setting:1">{string("Option 1")}</Menu.Item>
                    <Menu.Item key="setting:2">{string("Option 2")}</Menu.Item>
                </Menu.ItemGroup>

            </Menu.SubMenu>
            <Menu.Item key="alipay">
                <a href="https://ant.design" target="_blank" rel="noopener noreferrer">
                    {string("Navigation Four - Link")}
                </a>
            </Menu.Item>

        </Menu>
    </>
};