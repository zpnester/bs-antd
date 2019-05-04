

open React;
open Antd;
open Radio;
open Expect_;

module RadioGroup = Radio.Group;

[@react.component]
let make = () => {

    let (v1, setV1) = useState(() => "2");

    <>
        <h1 id="radio-example">{string("Radio Example")}</h1>

        <RadioGroup 
        onChange={e => {
            // Js.log2("onChange", e);
            expectBool(e##target##checked);
            expectMaybeString(e##target##value);
            setV1(_ => e##target##value->Belt.Option.getWithDefault(""))
        }}
         value=v1
         >
            <Radio value="1">{string("A")}</Radio>
            <Radio value="2">{string("B")}</Radio>
            <Radio value="3">{string("C")}</Radio>
            <Radio>{string("D")}</Radio>
      </RadioGroup>

      <Radio.Group defaultValue="c" buttonStyle=`solid>
        <Radio.Button value="a">{string("Hangzhou")}</Radio.Button>
        <Radio.Button value="b" disabled=true>{string("Shanghai")}</Radio.Button>
        <Radio.Button value="c">{string("Beijing")}</Radio.Button>
        <Radio.Button value="d">{string("Chengdu")}</Radio.Button>
      </Radio.Group>
    </>
};
