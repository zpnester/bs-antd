open Antd;
open Layout;
open React;

[@react.component]
let make = () => {
  <>
    <h1 id="layout-example"> {string("Layout Example")} </h1>
    <Layout className="layout">
      <Header>
        <div className="logo" />
        <Menu
          theme=`dark
          mode=`horizontal
          defaultSelectedKeys=[|"2"|]
          style={ReactDOMRe.Style.make(~lineHeight="64px", ())}>
          <Menu.Item key="1"> {string("nav 1")} </Menu.Item>
          <Menu.Item key="2"> {string("nav 2")} </Menu.Item>
          <Menu.Item key="3"> {string("nav 3")} </Menu.Item>
        </Menu>
      </Header>
      <Content style={ReactDOMRe.Style.make(~padding="0 50px", ())}>
        <Breadcrumb style={ReactDOMRe.Style.make(~margin="16px 0", ())}>
          <Breadcrumb.Item> {string("Home")} </Breadcrumb.Item>
          <Breadcrumb.Item> {string("List")} </Breadcrumb.Item>
          <Breadcrumb.Item> {string("App")} </Breadcrumb.Item>
        </Breadcrumb>
        <div
          style={ReactDOMRe.Style.make(
            ~background="#fff",
            ~padding="24px",
            ~minHeight="280px",
            (),
          )}>
          {string("Content")}
        </div>
      </Content>
      <Footer style={ReactDOMRe.Style.make(~textAlign="center", ())}>
        {string("Ant Design ©2018 Created by Ant UED")}
      </Footer>
    </Layout>
  </>;
};