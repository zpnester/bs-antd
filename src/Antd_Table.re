open React;
open Antd__;

type filterItem = {
  .
  "text": element,
  "value": string,
  "children": array(filterItem),
};

module SortOrder = {
  type t = string;

  [@bs.inline]
  let descend: t = "descend";
  [@bs.inline]
  let ascend: t = "ascend";
};

// made every field of sorterResult optional after testing

type sorterResult('a) =
  {
    .
    "column": option(Js.t({..})), // TODO
    "order": option(SortOrder.t),
    "field": option(string),
    "columnKey": option(string),
  } as 'a;

module Sorter = {
  type t('a);

  external bool: bool => t('a) = "%identity";

  external make: (('a, 'a, SortOrder.t) => float) => t('a) = "%identity";
};

module Width = {
  type t;

  external string: string => t = "%identity";
  external number: float => t = "%identity";
};

module Column = {
  type t('record);

  [@bs.obj]
  external make:
    (
      ~align: [@bs.string] [ | `left | `right | `center]=?,
      ~className: string=?,
      ~colSpan: int=?,
      ~dataIndex: string=?,
      ~defaultSortOrder: [@bs.string] [ | `descend | `ascend]=?,
      ~filterDropdown: Js.t({..}) => element=?,
      ~filterDropdownVisible: bool=?,
      ~filtered: bool=?,
      ~filteredValue: array(string)=?,
      ~filterIcon: bool => element=?,
      ~filterMultiple: bool=?,
      ~filters: array(filterItem)=?,
      // bool skipped
      ~fixed: [@bs.string] [ | `left | `right]=?,
      ~key: string=?,
      // assumed 1st as 'record after testing, change if not correct
      ~render: ('record, 'record, int) => element=?,
      ~sorter: Sorter.t('record)=?,
      ~sortOrder: SortOrder.t=?, // bool skipped
      ~sortDirections: array(SortOrder.t)=?,
      ~title: {
                .
                "filters": Js.Dict.t(array(string)),
                "sortOrder": Js.null(SortOrder.t),
              } =>
              element
                =?,
      ~width: Width.t=?,
      ~onCell: ('record, int) => Js.t({..})=?,
      // assumed string after testing (got filter .value), change if not correct
      ~onFilter: (string, 'record) => bool=?,
      ~onFilterDropdownVisibleChange: bool => unit=?,
      ~onHeaderCell: t('record) => Js.t({..})=?, // abstract atm, not useful
      ~children: element=?,
      unit
    ) =>
    t('record) =
    "";
};

type components;

type expandIconProps('record) = {
  .
  "prefixCls": string,
  "expanded": bool,
  "record": 'record,
  "needIndentSpaced": bool,
  "expandable": bool,
  // onExpand skipped
};

module Loading = {
  type t;

  external bool: bool => t = "%identity";
  external make: Antd_Spin.makeProps => t = "%identity";
};

module Locale = {
  type t;

  [@bs.obj]
  external make:
    (
      ~filterTitle: string=?,
      ~filterConfirm: element=?,
      ~filterReset: element=?,
      ~emptyText: unit => element=?,
      ~selectAll: element=?,
      ~selectInvert: element=?,
      ~sortTitle: string=?,
      unit
    ) =>
    t =
    "";
};

module Position = {
  type t = string;
  [@bs.inline]
  let top = "top";
  [@bs.inline]
  let bottom = "bottom";
  [@bs.inline]
  let both = "both";
};

module Pagination = {
  type t;

  let false_: t = [%raw {| false |}];

  module ItemRenderType = Antd_Pagination.ItemRenderType;
  module ShowQuickJumper = Antd_Pagination.ShowQuickJumper;
  module Size = Antd_Pagination.Size;

  module Config = {
    [@bs.deriving abstract]
    type make = {
      // ***** BEGIN PAGINATION *****
      [@bs.optional]
      current: int,
      [@bs.optional]
      defaultCurrent: int,
      [@bs.optional]
      defaultPageSize: int,
      [@bs.optional]
      hideOnSinglePage: bool,
      [@bs.optional]
      itemRender: (int, ItemRenderType.t, element) => element,
      [@bs.optional]
      pageSize: int,
      [@bs.optional]
      pageSizeOptions: array(string),
      [@bs.optional]
      showLessItems: bool,
      [@bs.optional]
      showQuickJumper: ShowQuickJumper.t,
      [@bs.optional]
      showSizeChanger: bool,
      [@bs.optional]
      showTotal: (~total: int, ~range: (int, int)) => element,
      [@bs.optional]
      simple: bool,
      [@bs.optional]
      size: Size.t,
      [@bs.optional]
      total: int,
      [@bs.optional]
      onChange: (~page: int, ~pageSize: option(int)) => unit,
      [@bs.optional]
      style: ReactDOMRe.Style.t,
      [@bs.optional]
      className: string,
      [@bs.optional]
      prefixCls: string,
      [@bs.optional]
      selectPrefixCls: string,
      [@bs.optional]
      role: string,
      // ***** END PAGINATION *****
      [@bs.optional]
      position: Position.t,
    };
  };

  external make: Config.make => t = "%identity";
};

module RowSelection = {
  type t('record);

  [@bs.obj]
  external make:
    (
      ~_type: [@bs.string] [ | `checkbox | `radio]=?,
      ~selectedRowKeys: array(string)=?, // number[] skipped
      ~onChange: (array(string), array('record)) => unit=?,
      ~getCheckboxProps: 'record => Js.t({..})=?,
      ~onSelect: ('record, bool, array('record), Dom.event) => unit=?, // ret any skipped
      ~onSelectMultiple: (
                           bool,
                           ~selectedRows: array('record),
                           ~changeRows: array('record)
                         ) =>
                         unit
                           =?,
      ~onSelectAll: (
                      bool,
                      ~selectedRows: array('record),
                      ~changeRows: array('record)
                    ) =>
                    unit
                      =?,
      ~onSelectInvert: array(string) => unit=?, // number[] skipped
      // bool skipped
      ~selections: array({
                     .
                     "key": string,
                     "text": element,
                     "onSelect": option(array(string) => unit),
                   })
                     =?, // any ret skipped
      ~hideDefaultSelections: bool=?,
      ~fixed: bool=?,
      ~columnWidth: Width.t=?,
      ~selectWay: [@bs.string] [
                    | `onSelect
                    | `onSelectMultiple
                    | `onSelectAll
                    | `onSelectInvert
                  ]
                    =?,
      ~columnTitle: element=?,
      unit
    ) =>
    t('record) =
    "";
};

module Scroll = {
  type t;

  external bool: bool => t = "%identity";
  external number: float => t = "%identity";
  external string: string => t = "%identity";
};

type tableCurrentDataSource('record) = {
  .
  "currentDataSource": array('record),
};

[@react.component] [@bs.module]
external make:
  (
    ~bordered: bool=?,
    ~childrenColumnName: string=?, // array fails at runtime
    ~columns: array(Column.t('record)),
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~children: element=?,
    ~components: components=?, // TODO lowest priority
    ~dataSource: array('record), // required
    ~defaultExpandAllRows: bool=?,
    ~defaultExpandedRowKeys: array(string)=?, // skipped: TS: string[] | number[]
    ~expandedRowKeys: array(string)=?, // skipped: TS: string[] | number[]
    ~expandedRowRender: ('record, int, int, bool) => element=?,
    ~expandIcon: expandIconProps('record) => element=?,
    ~expandRowByClick: bool=?,
    ~footer: array('record) => element=?,
    ~indentSize: float=?,
    ~loading: Loading.t=?,
    ~locale: Locale.t=?,
    ~pagination: Pagination.t=?,
    ~rowClassName: ('record, int) => string=?,
    ~rowKey: ('record, int) => string=?,
    ~rowSelection: RowSelection.t('record)=?,
    ~scroll: {
               .
               "x": option(Scroll.t),
               "y": option(Scroll.t),
             }
               =?,
    ~showHeader: bool=?,
    ~size: [@bs.string] [ | `default | `middle | `small]=?,
    ~title: array('record) => element=?,
    ~onChange: (
                 Pagination.Config.make,
                 Js.Dict.t(array(string)),
                 sorterResult('todo),
                 tableCurrentDataSource('record)
               ) =>
               unit
                 =?,
    ~onExpand: (bool, 'record) => unit=?,
    ~onExpandedRowsChange: array(string) => unit=?, // num[] skipped
    ~onHeaderRow: (array(Column.t('record)), int) => Js.t({..})=?,
    ~onRow: ('record, int) => Js.t({..})=?,
    unit
  ) =>
  element =
  "antd/lib/table";