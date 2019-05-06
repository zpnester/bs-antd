open Antd;
open Statistic;
open React;
open MomentRe;

[@react.component]
let make = () => {
  let deadline =
    momentNow() |> Moment.add(~duration=duration(10.0, `seconds));

  <>
    <h1 id="statistic-example"> {string("Statistic Example")} </h1>
    <Statistic
      title={string("Active Users")}
      value={Value.number(112893.0)}
    />
    <Statistic
      title={string("Active")}
      value={Value.number(11.28)}
      precision=2
      valueStyle={ReactDOMRe.Style.make(~color="#3f8600", ())}
      prefix={<Icon _type=Icon.Type.arrowUp />}
      suffix={string("%")}
    />
    <Countdown
      title={string("Countdown")}
      value={Countdown.Value.moment(deadline)}
      onFinish={() =>
        // Js.log("onFinish")
        ()}
    />
  </>;
};