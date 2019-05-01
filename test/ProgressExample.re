
open React;
open Antd;
open Expect_;
open Progress;

[@react.component] 
let make = () => {

    <>
        <h1 id="progress-example">{string("Progress Example")}</h1>
        <Progress percent=31 />
        <Progress _type=`dashboard percent=75 />

        <Progress _type=`circle 
        percent={75} 
        successPercent=50

        format={(~percent, ~successPercent) => {
            Js.log3("format", percent, successPercent);
            expectInt(percent);
            expectInt(successPercent);
            string(percent->string_of_int ++ " Days");
        }} 
        />
        <Progress _type=`circle percent={100} 
        format={(~percent, ~successPercent) => {
            Js.log3("format", percent, successPercent);

            string("Done")
        }} />
    </>

};