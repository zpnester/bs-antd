

open React;
open Antd;
open Divider;

[@react.component]
let make = () => {

    <>
        <h1 id="divider-example">{string("Divider Example")}</h1>
        <p>{string("hello")}</p>
        <Divider />
        <p>{string("world")}</p>

        <hr />
        {string("Text")}
        <Divider _type=`vertical  />

        <a href="#">{string("Link")}</a>
        <Divider _type=`vertical  />
        <a href="#">{string("Link")}</a>
    </>
};