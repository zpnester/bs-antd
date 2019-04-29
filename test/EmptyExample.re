

open React;
open Antd;
open Empty;

[@react.component]
let make = () => {

    <>
        <h1 id="empty-example">{string("Empty Example")}</h1>

        <Empty/>
        <Empty image=presentedImageDefault/>
        <Empty image=presentedImageSimple/>
    </>
};