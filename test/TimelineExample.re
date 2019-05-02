open React;
open Antd;
open Timeline;
open Expect_;


[@react.component]
let make = () => {

    let (reverse, setReverse) = useState(() => false);

    <>
        <h1 id="timeline-example">{string("Timeline Example")}</h1>
        
        <div>
        <Timeline pending=string("Recording...") 
        reverse>
          <Timeline.Item>{string("Create a services site 2015-09-01")}</Timeline.Item>
          <Timeline.Item>{string("Solve initial network problems 2015-09-01")}</Timeline.Item>
          <Timeline.Item>{string("Technical testing 2015-09-01")}</Timeline.Item>
        </Timeline>
        <Button _type=`primary 
         onClick={_ => {
             setReverse(r => !r)
         }}>{string("Toggle Reverse")}</Button>
      </div>
    </>
};