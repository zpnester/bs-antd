open React;
open Antd;
open Radio;
open Expect_;

module RadioGroup = Radio.Group;

let expectRadioChangeEvent = e => {
  expectBool(e##target##checked);
  expectString(e##target##value);
  expectMaybeString(e##target##name);
  expectDomMouseEvent(e##nativeEvent);
};

[@react.component]
let make = () => {
  let (v1, setV1) = useState(() => "2");

  <>
    <h1 id="radio-example"> {string("Radio Example")} </h1>
    <RadioGroup 
    size=`small
    onMouseEnter={e => ()}
      onChange={e => {
        expectRadioChangeEvent(e);
        setV1(_ => e##target##value);
      }}
      value=v1>
      <Radio value="1"
        onChange={e => {
        expectRadioChangeEvent(e);
      }}
      > {string("A")} </Radio>
      <Radio value="2"> {string("B")} </Radio>
      <Radio value="3"> {string("C")} </Radio>
      <Radio value="4"> {string("D")} </Radio>
    </RadioGroup>

    <Radio.Group defaultValue="c" buttonStyle=`solid
     size=`large
    onChange={e => {
        expectRadioChangeEvent(e);
        setV1(_ => e##target##value);
      }}
    >
      <Radio.Button value="a"> {string("Hangzhou")} </Radio.Button>
      <Radio.Button value="b" disabled=true>
        {string("Shanghai")}
      </Radio.Button>
      <Radio.Button value="c"> {string("Beijing")} </Radio.Button>
      <Radio.Button value="d"> {string("Chengdu")} </Radio.Button>
    </Radio.Group>
  </>;
};