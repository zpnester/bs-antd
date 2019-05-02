open React;
open Antd;
open Typography;
open Expect_;


[@react.component]
let make = () => {

    <>
        <h1 id="typography-example">{string("Typography Example")}</h1>
        
        <Title>{string("h1. Ant Design")}</Title>
        <Title level=`h2>{string("h2. Ant Design")}</Title>
        <Title level=`h3>{string("h3. Ant Design")}</Title>
        <Title level=`h4>{string("h4. Ant Design")}</Title>

        <Text>{string("Ant Design")}</Text>
    <br />
    <Text _type=`secondary>{string("Ant Design")}</Text>
    <br />
    <Text _type=`warning>{string("Ant Design")}</Text>
    <br />
    <Text _type=`danger>{string("Ant Design")}</Text>
    <br />
    <Text disabled=true>{string("Ant Design")}</Text>
    <br />
    <Text mark=true>{string("Ant Design")}</Text>
    <br />
    <Text code=true>{string("Ant Design")}</Text>
    <br />
    <Text underline=true>{string("Ant Design")}</Text>
    <br />
    <Text delete=true>{string("Ant Design")}</Text>
    <br />
    <Text strong=true>{string("Ant Design")}</Text>
    </>
};