open React;

module Accordion = {
  type t('value);

  let true_: t(option(string)) = [%raw {| (true) |}];
  let false_: t(array(string)) = [%raw {| (false) |}];
};

[@react.component] [@bs.module]
// ***** BEGIN COLLAPSE *****
external make:
  (
    ~activeKey: 'value=?,
    ~defaultActiveKey: 'value=?, // TODO test, TS says always str[]
    ~accordion: Accordion.t('value), // required
    ~destroyInactivePanel: bool=?,
    ~onChange: 'value => unit=?,
    ~style: ReactDOMRe.Style.t=?,
    ~className: string=?,
    ~bordered: bool=?,
    ~prefixCls: string=?,
    ~expandIcon: Js.t({..}) => element=?, // TODO
    // ***** END COLLAPSE *****
    ~children: element=?,
    ~key: string=?,
    unit
  ) =>
  element =
  "antd/lib/collapse";

module Panel = {
  [@react.component] [@bs.module]
  // ***** BEGIN Panel *****
  external make:
    (
      ~isActive: bool=?,
      ~header: element=?,
      ~className: string=?,
      ~style: ReactDOMRe.Style.t=?,
      ~showArrow: bool=?,
      ~forceRender: bool=?,
      ~disabled: bool=?,
      ~extra: element=?,
      // ***** END Panel *****
      ~children: element=?,
      ~key: string=?,
      unit
    ) =>
    element =
    "antd/lib/collapse/CollapsePanel";
};