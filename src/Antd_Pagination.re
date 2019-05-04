
open React;

module ItemRenderType = {
    type t = string;

    [@bs.inline] let page = "page";
    [@bs.inline] let prev = "prev";
    [@bs.inline] let next = "next";
    [@bs.inline] let jumpPrev = "jump-prev";
    [@bs.inline] let jumpNext = "jump-next";

};

module ShowQuickJumper = {
    type t;

    external bool: bool => t = "%identity";
    [@bs.obj] external make: (
        ~goButton: element
    ) => t = "";
};

[@react.component] [@bs.module]
external make: (
    ~current: int=?,
    ~defaultCurrent: int=?,
    ~defaultPageSize: int=?,
    ~hideOnSinglePage: bool=?,
    ~itemRender: (int, ItemRenderType.t, element) => element=?,
    ~pageSize: int=?,
    ~pageSizeOptions: array(string)=?,
    ~showLessItems: bool=?,
    ~showQuickJumper: ShowQuickJumper.t=?,
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
    unit
) => element = "antd/lib/pagination";