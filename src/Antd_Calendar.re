open React;
open MomentRe;

module Mode = {
  type t = string;
  [@bs.inline]
  let month = "month";
  [@bs.inline]
  let year = "year";
};

[@react.component] [@bs.module "antd/lib/calendar"]
external make:
  (
    ~prefixCls: string=?,
    ~className: string=?,
    ~value: Moment.t=?, // null not allowed
    ~defaultValue: Moment.t=?,
    ~mode: Mode.t=?, // polyvar not used so input and output use same time
    ~fullscreen: bool=?,
    ~dateCellRender: Moment.t => element=?,
    ~monthCellRender: Moment.t => element=?,
    ~dateFullCellRender: Moment.t => element=?,
    ~monthFullCellRender: Moment.t => element=?,
    ~locale: Js.t({..})=?, // TODO
    ~style: ReactDOMRe.Style.t=?,
    ~onPanelChange: (Moment.t, Mode.t) => unit=?,
    ~onSelect: Moment.t => unit=?,
    ~onChange: Moment.t => unit=?,
    ~disabledDate: Moment.t => bool=?,
    ~validRange: (Moment.t, Moment.t)=?,
    unit
  ) =>
  element =
  "default";