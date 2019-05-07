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
      // valueRender={e => {
      //   e
      // }}
      title={string("Active Users")}
      value={112893.0->Js.Float.toString}
    />
    <Statistic
      title={string("Active")}
      // formatter={Formatter.make(value => {
      //   string(value ++ "!")
      // })}
      // formatter=Formatter.false_
      decimalSeparator="o"
      // value={Value.number(11.2899)}
      value={"112.289999"}
      precision=2
      valueStyle={ReactDOMRe.Style.make(~color="#3f8600", ())}
      prefix={<Icon _type=Icon.Type.arrowUp />}
      suffix={string("%")}
    />
    <Countdown
      title={string("Countdown")}
      value={deadline}
      onFinish={() => {
        Js.log("onFinish")
        }}
    />
  </>;
};