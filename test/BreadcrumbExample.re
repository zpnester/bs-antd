open React;
open Antd;
open Breadcrumb;
open Expect_;


let expectCustomRoute = r => {
  expectString(r##path);
  expectString(r##breadcrumbName);
  expectInt(r##custom);
};
let expectCustomRouteArray = expectArrayOf(expectCustomRoute);

let expectParams = p => {
  expectString(p##a);
  expectInt(p##b);
};

[@react.component]
let make = () => {
  let routes = [|
    {"path": "#a", "breadcrumbName": "A", "custom": 321},
    {"path": "#b", "breadcrumbName": "B", "custom": 322},
  |];

  <>
    <h1 id="breadcrumb-example"> {string("Breadcrumb Example")} </h1>
    <Breadcrumb>
      <Item> {string("Home")} </Item>
      <Item> <a href="#"> {string("App Center")} </a> </Item>
      <Item> <a href="#"> {string("App List")} </a> </Item>
    </Breadcrumb>
    <Breadcrumb.Routes
      routes
      separator={string("|")}
      params={ "a": "A", "b": 1 }
      itemRender={(route, params, rs, paths) => {
        expectCustomRoute(route);
        expectCustomRouteArray(rs)
        expectStringArray(paths);
        expectParams(params);
        string(route##path)
      }}
    />
  </>;
};