open React;
open Antd;
open Spin;
open Expect_;


[@react.component]
let make = () => {

    <>
        <h1 id="spin-example">{string("Spin Example")}</h1>
        
        <Spin />

        <Spin tip="Loading...">
            <Alert
                message=string("Alert message title")
                description=string("Further details about the context of this alert.")
                _type=`info
            />
        </Spin>
    </>
};