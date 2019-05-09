open React;

type transferItem('data) =
  {
    ..
    "key": string,
    "title": string,
    "description": option(string),
    "disabled": bool,
  } as 'data;

// list props skipped, dataSource SSR crash, kept as Js.t({..})

module Direction = {
  type t = string;
  [@bs.inline]
  let left = "left";
  [@bs.inline]
  let right = "right";
};

type locale = {
  .
  "searchPlaceholder": string,
  "itemUnit": string,
  "itemsUnit": string,
};

[@react.component] [@bs.module]
external make:
  (
    ~prefixCls: string=?,
    ~className: string=?,
    ~disabled: bool=?,
    ~dataSource: array(transferItem('data)), // requried
    ~targetKeys: array(string)=?,
    ~selectedKeys: array(string)=?,
    ~render: transferItem('data) => element, // requried
    ~onChange: (
                 ~targetKeys: array(string),
                 ~direction: Direction.t,
                 ~moveKeys: array(string)
               ) =>
               unit
                 =?,
    ~onSelectChange: (
                       ~sourceSelectedKeys: array(string),
                       ~targetSelectedKeys: array(string)
                     ) =>
                     unit
                       =?,
    ~style: ReactDOMRe.Style.t=?,
    ~listStyle: ReactDOMRe.Style.t=?,
    ~operationStyle: ReactDOMRe.Style.t=?,
    ~titles: array(string)=?,
    ~operations: array(string)=?,
    ~showSearch: bool=?,
    ~filterOption: (string, transferItem('data)) => bool=?,
    ~footer: Js.t({..}) => element=?,
    ~body: Js.t({..}) => element=?,
    ~rowKey: transferItem('data) => string=?, // not required as key is required in 'data
    // onSearchChange deprecated
    // ~onSearchChange: (Direction.t, ReactEvent.Synthetic.t) => unit=?,
    ~onSearch: (Direction.t, string) => unit=?,
    ~_lazy: bool=?, // obj skipped
    ~locale: locale=?,
    ~onScroll: (Direction.t, ReactEvent.Synthetic.t) => unit=?,
    unit
  ) =>
  element =
  "antd/lib/transfer";