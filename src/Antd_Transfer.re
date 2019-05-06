open React;

type transferItem('a) =
  {
    ..
    "key": string,
    "title": string,
    "description": option(string),
    "disabled": bool,
  } as 'a;

module List = {
  type t;

  // TODO it is outout type, not input, REDO
  [@bs.obj]
  external make:
    (
      ~prefixCls: string=?,
      ~titleText: string=?,
      // probably should be removed
      // ~dataSource: array(transferItem('a))=?,
      ~filter: string=?,
      ~filterOption: ('todo, 'todo2) => bool=?,
      ~style: ReactDOMRe.Style.t=?,
      ~checkedKeys: array(string)=?,
      ~handleFilter: 'todo3 => unit=?,
      ~handleSelect: ('todo4, bool) => unit=?,
      ~handleSelectAll: (array('todo5), bool) => unit=?,
      ~handleClear: unit => unit=?,
      ~render: 'todo6 => 'todo7=?,
      ~showSearch: bool=?,
      ~searchPlaceholder: string=?,
      ~notFoundContent: element=?,
      ~itemUnit: string=?,
      ~itemsUnit: string=?,
      // TODO self props
      ~body: Js.t({..}) => element=?,
      ~footer: Js.t({..}) => element=?,
      ~_lazy: bool=?, // obj skipped
      ~onScroll: 'todo8 => 'todo9=?,
      ~disabled: bool=?,
      unit
    ) =>
    t =
    "";
};

module Direction = {
  type t = string;
  [@bs.inline]
  let left = "left";
  [@bs.inline]
  let right = "right";
};

[@react.component] [@bs.module]
external make:
  (
    ~className: string=?,
    ~dataSource: array(transferItem('a)), // requried
    ~disabled: bool=?,
    ~filterOption: ('todo, 'todo2) => bool=?,
    ~footer: List.t => element=?, // tODO test
    ~_lazy: bool=?, // obj skipped
    ~listStyle: ReactDOMRe.Style.t=?,
    ~locale: Js.t({..})=?, // TODO
    ~operations: array(string)=?,
    ~operationStyle: ReactDOMRe.Style.t=?,
    ~render: transferItem('a) => element=?,
    ~selectedKeys: array(string)=?,
    ~showSearch: bool=?,
    ~style: ReactDOMRe.Style.t=?,
    ~targetKeys: array(string)=?,
    ~titles: array(string)=?,
    ~onChange: (array(string), string, 'todo3) => unit=?,
    ~onScroll: (Direction.t, ReactEvent.Synthetic.t) => unit=?,
    ~onSearch: (Direction.t, string) => unit=?, // TODO test
    // won't be needed as key is required in transferItem
    ~rowKey: transferItem('a) => string=?,
    unit
  ) =>
  element =
  "antd/lib/transfer";