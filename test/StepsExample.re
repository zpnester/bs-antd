open React;
open Antd;
open Steps;
open Expect_;

[@react.component]
let make = () => {
  <>
    <h1 id="steps-example"> {string("Steps Example")} </h1>
    <Steps current=1>
      <Step
        title={string("Finished")}
        description={string("This is a description.")}
      />
      <Step
        title={string("In Progress")}
        description={string("This is a description.")}
      />
      <Step
        title={string("Waiting")}
        description={string("This is a description.")}
      />
    </Steps>
    <Steps
      current=1
      progressDot={ProgressDot.make((dot, o) => {
        let index = o##index;
        let status = o##status;
        let title = o##title;
        let description = o##description;
        Js.log3("progressDot", dot, o);

        expectInt(index);
        let content =
          <span>
            {string("step " ++ index->string_of_int ++ " status: " ++ status)}
          </span>;
        <Popover content> dot </Popover>;
      })}>
      <Steps.Step
        title={string("Finished")}
        description={string("You can hover on the dot.")}
      />
      <Step description={string("You can hover on the dot.")} />
      <Step title={string("Waiting")} />
      <Step title={string("Waiting")} />
    </Steps>
  </>;
};
