

open React;
open Antd;
open Grid;


[@react.component]
let make = () => {


    <>
        <h1 id="grid-example">{string("Grid Example")}</h1>

        <Row>
            <Col span={8}>
                {string("Col 1")}
            </Col>
            <Col span={8}>
                {string("Col 2")}
            </Col>
            <Col span={8}>
                {string("Col 3")}
            </Col>
        </Row>
    </>
};