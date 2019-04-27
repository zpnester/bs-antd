

open React;
open Antd;
open Breadcrumb;


[@react.component]
let make = () => {
    let routes = [|
        {
            "path": "#a",
            "breadcrumbName": "A"
        },
        {
            "path": "#b",
            "breadcrumbName": "B"
        }
    |];

    <>
    <h1 id="breadcrumb-example">{string("Breadcrumb Example")}</h1>
        <Breadcrumb >
            <Item>
                {string("Home")}
            </Item>
            <Item>
                <a href="#">{string("App Center")}</a>
            </Item>
            <Item>
                <a href="#">{string("App List")}</a>
            </Item>
        </Breadcrumb>

        <Breadcrumb.Routes routes separator=string("|") params={"a": 1}
         itemRender={(route, b, c, d) => {
            Js.log4(route, b, c, d);
            string(route##path);
        }} />
    </>
};