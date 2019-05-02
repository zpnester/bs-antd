

open React;

type filterItem = {
    .
    "text": element,
    "value": string,
    "children": array(filterItem)
};

module SortOrder = {
    type t = string;

    [@bs.inline] let descend: t = "descend";
    [@bs.inline] let ascend: t = "ascend";
};

module SortOrderProp = {
    type t = string;

    // input only
    external bool: bool => t = "%identity";

    [@bs.inline] let descend: t = "descend";
    [@bs.inline] let ascend: t = "ascend";
};

module Sorter = {
    type t('a);

    external bool: bool => t('a) = "%identity";

    external make: (('a, 'a, SortOrder.t) => float) => t('a) = "%identity"; // TODO test
};

module Width = {
    type t;

    external string: string => t = "%identity";
    external number: float => t = "%identity";
};

module Column = {
    type t('c);

    [@bs.obj] external make: (
        ~align: [@bs.string] [
            | `left
            | `right
            | `center
        ]=?,
        ~className: string=?,
        ~colSpan: int=?,
        ~dataIndex: string=?,
        ~defaultSortOrder: [@bs.string] [
            | `descend
            | `ascend
        ]=?,
        ~filterDropdown: Js.t({..}) => element=?, // TODO stricter props if possible, TODO test
        ~filterDropdownVisible: bool=?,
        ~filtered: bool=?,
        ~filteredValue: array(string)=?,
        ~filterIcon: bool => element=?, // TODO test
        ~filterMultiple: bool=?,
        ~filters: array(filterItem)=?,
        // bool skipped
        ~fixed: [@bs.string] [
            | `left
            | `right
        ]=?,
        ~key: string=?,
        ~render: (Js.t({..}), 'c, int) => element=?, // TODO test, do  types  1,2
        ~sorter: Sorter.t('c)=?,  
        ~sortOrder: SortOrderProp.t=?,
        ~sortDirections: array(SortOrder.t)=?,
        // TODO test
        ~title: {
            .
            "filters": Js.Dict.t(array(string)),
            "sortOrder": SortOrder.t
        } => element=?,
        ~width: Width.t=?,
        ~onCell: ('c, int) => unit=?, // TODO ret any, TODO test
        ~onFilter: ('todo, 'c) => bool=?, // TODO test, TODO types
        ~onFilterDropdownVisibleChange: bool => unit=?, // TODO test
        ~onHeaderCell: t('c) => unit=?, // TODO any ret, TODO test
        ~children: element=?,
        unit
    ) => t('c) = "";
};

type components = {
    .
    "table": option(element),
    "header": option({
        .
        "wrapper": option(element),
        "row": option(element),
        "cell": option(element)
    }),
    "body": option({
        .
        "wrapper": option(element),
        "row": option(element),
        "cell": option(element)
    })
};

// TODO test
type expandIconProps('c) = {
    .
    "prefixCls": string, // TODO opt?
    "expanded": bool,
    "record": 'c,
    "needIndentSpaced": bool,
    "expandable": bool,
    "onExpand": ('c, ReactEvent.Mouse.t) => unit // TODO dom vs react
};

module Loading = {
    type t;

    external bool: bool => t = "%identity";

    // possible to reuse real spin props
    // but do copy paste instead
    [@bs.obj] external make: (
        ~delay: float=?,
        ~indicator: element=?,
        ~size: [@bs.string] [
            | `small
            | `default
            | `large
        ]=?,
        ~spinning: bool=?,
        ~tip: string=?,
        ~wrapperClassName: string=?,
        ~prefixCls: string=?,
        ~className: string=?,
        ~style: ReactDOMRe.Style.t=?,
    ) => t = "";
}

module Locale = {
    type t;

    [@bs.obj] external make: (
        ~filterTitle: string=?,
        ~filterConfirm: element=?,
        ~filterReset: element=?,
        ~emptyText: unit => element=?,
        ~selectAll: element=?,
        ~selectInvert: element=?,
        ~sortTitle: string=?,
        unit
    ) => t = "";
};

module Pagination = {
    type t;

    let false_: t = [%raw {| (false) |}];

    // copy pasted from antd_pagination + position
    [@bs.obj] external make: (
        ~position: [@bs.string] [
            | `top
            | `bottom
            | `both
        ]=?,
        ~current: int=?,
        ~defaultCurrent: int=?,
        ~defaultPageSize: int=?,
        ~hideOnSinglePage: bool=?,
        ~itemRender: (int, Antd_Pagination.ItemRenderType.t, element) => element=?,
        ~pageSize: int=?,
        ~pageSizeOptions: array(string)=?,
        ~showLessItems: bool=?,
        ~showQuickJumper: Antd_Pagination.ShowQuickJumper.t=?,
        ~showSizeChanger: bool=?,
        ~showTotal: (~total: int, ~range: (int, int)) => element=?, // TODO test 
        ~simple: bool=?,
        ~size: string=?,
        ~total: int=?,
        ~onChange: (~page: int, ~pageSize: int) => unit=?, // TODO test second type
        ~style: ReactDOMRe.Style.t=?,
        ~className: string=?,
        ~prefixCls: string=?,
        ~selectPrefixCls: string=?,
        ~role: string=?,
    ) => t = "";
};

module RowSelection = {
    type t('c);

    [@bs.obj] external make: (
        ~_type: [@bs.string] [
            | `checkbox
            | `radio
        ]=?,
        ~selectedRowKeys: array(string)=?, // number[] skipped
        ~onChange: (array(string), array('c)) => unit=?,
        ~getCheckboxProps: 'c => Js.t({..})=?, // TODO
        ~onSelect: ('c, bool, array('todo), ReactEvent.Synthetic.t) => 'todo2=?, // TODO
        ~onSelectMultiple: (bool, ~selectedRows: array('c), ~changeRows: array('c)) => unit=?,
        ~onSelectAll: (bool, ~selectedRows: array('c), ~changeRows: array('c)) => unit=?,
        ~onSelectInvert: array(string) => unit=?, // number[] skipped
        // bool skipped
        ~selections: array({
            .
            "key": string,
            "text": element,
            "onSelect": option((array(string)) => unit) // any ret skipped
        })=?,
        ~hideDefaultSelections: bool=?,
        ~fixed: bool=?,
        ~columnWidth: Width.t=?,
        ~selectWay: [@bs.string] [
            | `onSelect
            | `onSelectMultiple
            | `onSelectAll
            | `onSelectInvert
        ]=?,
        ~columnTitle: element=?,
        unit
    ) => t('c) = "";
};

module Scroll = {
    type t;

    external bool: bool => t = "%identity";
    external number: float => t = "%identity";
    external string: string => t = "%identity";
};

type onChange;


[@react.component] [@bs.module]
external make: (
    ~bordered: bool=?,
    ~childrenColumnName: array(string)=?, // TODO test, str vs str[]
    ~columns: array(Column.t('c)),  // TODO make optional if needed

    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~children: element=?,
    ~components: components=?, // TODO test
    ~dataSource: array('c), // TODO make optional if needed
    ~defaultExpandAllRows: bool=?,
    ~defaultExpandedRowKeys: array(string)=?, // skipped: TS: string[] | number[]
    ~expandedRowKeys: array(string)=?, // skipped: TS: string[] | number[]
    ~expandedRowRender: (~record: 'c, ~index: int, ~indent: int, ~expanded: bool) => element=?, // TODO test
    ~expandIcon: expandIconProps('c) => element=?,
    ~expandRowByClick: bool=?,
    ~footer: Js.t({..}) => element=?, // TODO
    ~indentSize: float=?,
    ~loading: Loading.t=?,
    ~locale: Locale.t=?,
    ~pagination: Pagination.t=?,
    ~rowClassName: ('c, int) => string=?, // TODO test
    ~rowKey: ('c, int) => string=?, // TODO tes
    ~rowSelection: RowSelection.t('c)=?,
    ~scroll: {
        .
        "x": option(Scroll.t),
        "y": option(Scroll.t)
    }=?,
    ~showHeader: bool=?,
    ~size: [@bs.string] [
        | `default
        | `middle
        | `small
    ]=?,
    ~title: array(Js.t({..})) => element=?, // TODO
    ~onChange: onChange=?, // TODO
    ~onExpand: (bool, 'c) => unit=?,
    ~onExpandedRowsChange: array(string) => unit=?, // num[] skipped
    ~onHeaderRow: (Column.t('c), int) => Js.t({..})=?, // TODO
    ~onRow: ('c, int) => Js.t({..})=?, // TODO
    unit
) => element = "antd/lib/table"