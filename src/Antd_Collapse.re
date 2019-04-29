open React;

module Make = (M: {type value;}) => {
  [@react.component] [@bs.module]
  external make:
    (
      ~activeKey: M.value=?,
      ~defaultActiveKey: array(string)=?,
      ~accordion: bool=?,
      ~bordered: bool=?,
      ~onChange: M.value => unit=?,
      ~expandIcon: Js.t({..}) => element=?,
      ~destroyInactivePanel: bool=?,
      ~children: element=?,
      unit
    ) =>
    element =
    "antd/lib/collapse";
};

include Make({
  type value = array(string);
});

let makeProps = makeProps(~accordion=false);

module Accordion = {
  include Make({
    type value = option(string);
  });

  let makeProps = makeProps(~accordion=true);
};

module Panel = {
  [@react.component] [@bs.module]
  external make:
    (
      ~disabled: bool=?,
      ~forceRender: bool=?,
      ~header: element=?,
      ~key: string=?,
      ~showArrow: bool=?,
      ~extra: element=?,
      ~children: element=?,
      unit
    ) =>
    element =
    "antd/lib/collapse/CollapsePanel";
};
