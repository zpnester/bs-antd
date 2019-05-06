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
  "onExpand": ('record, Dom.mouseEvent) => unit,
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

module Pagination = {
  type t;

  let false_: t = [%raw {| (false) |}];

  // copy pasted from antd_pagination + position
  [@bs.obj]
  external make:
    (
      ~position: [@bs.string] [ | `top | `bottom | `both]=?,
      ~current: int=?,
      ~defaultCurrent: int=?,
      ~defaultPageSize: int=?,
      ~hideOnSinglePage: bool=?,
      ~itemRender: (
                     int,
                     Antd_Pagination.ItemRenderType.t,
                     reactElement(Js.t({..}))
                   ) =>
                   element
                     =?,
      ~pageSize: int=?,
      ~pageSizeOptions: array(string)=?,
      ~showLessItems: bool=?,
      ~showQuickJumper: Antd_Pagination.ShowQuickJumper.t=?,
      ~showSizeChanger: bool=?,
      ~showTotal: (~total: int, ~range: (int, int)) => element=?,
      ~simple: bool=?,
      ~size: string=?,
      ~total: int=?,
      ~onChange: (~page: int, ~pageSize: option(int)) => unit=?,
      ~style: ReactDOMRe.Style.t=?,
      ~className: string=?,
      ~prefixCls: string=?,
      ~selectPrefixCls: string=?,
      ~role: string=?,
      unit
    ) =>
    t =
    "";
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
      ~onSelect: ('record, bool, array('record), Dom.event) => Js.t({..})=?, // TODO validate ret works
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

type onChange;

[@react.component] [@bs.module]
external make:
  (
    ~bordered: bool=?,
    ~childrenColumnName: string=?, // array fails at runtime
    ~columns: array(Column.t('record)), // TODO optional?
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~children: element=?,
    ~components: components=?, // TODO later
    ~dataSource: array('record), // required
    ~defaultExpandAllRows: bool=?,
    ~defaultExpandedRowKeys: array(string)=?, // skipped: TS: string[] | number[]
    ~expandedRowKeys: array(string)=?, // skipped: TS: string[] | number[]
    ~expandedRowRender: (
                          ~record: 'record,
                          ~index: int,
                          ~indent: int,
                          ~expanded: bool
                        ) =>
                        element
                          =?,
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
    ~onChange: onChange=?, // TODO later
    ~onExpand: (bool, 'record) => unit=?,
    ~onExpandedRowsChange: array(string) => unit=?, // num[] skipped
    ~onHeaderRow: (array(Column.t('record)), int) => Js.t({..})=?,
    ~onRow: ('record, int) => Js.t({..})=?,
    unit
  ) =>
  element =
  "antd/lib/table";