open React;
open Antd;
open Card;


[@react.component]
let make = () => {

    <>
        <h1 id="card-example">{string("Card Example")}</h1>

        <Card title=string("Title 1") extra=string("Extra 1")
            size=Size.small
            actions=[|
                <Button>{string("action 1")}</Button>,
                <Button>{string("action 2")}</Button>
            |]
            >
            {string("Card 1")}
        </Card>
    </>
};  