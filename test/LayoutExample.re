
open Antd;
open Layout;
open React;


[@react.component]
let make = () => {

    <>
        <h1 id="layout-example">{string("Layout Example TODO after menu")}</h1>

        <Layout>
            <Layout.Sider>
                {string("Sider")}
            </Layout.Sider>
            <Layout.Header>
                {string("Header")}
            </Layout.Header>
            <Layout.Content>
                {string("Layout")}
            </Layout.Content>
            <Layout.Footer>
                {string("Footer")}
            </Layout.Footer>
        </Layout>
    </>
};