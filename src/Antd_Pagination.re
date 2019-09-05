open React;

module ItemRenderType = {
  type t = string;

  [@bs.inline]
  let page = "page";
  [@bs.inline]
  let prev = "prev";
  [@bs.inline]
  let next = "next";
  [@bs.inline]
  let jumpPrev = "jump-prev";
  [@bs.inline]
  let jumpNext = "jump-next";
};

module ShowQuickJumper = {
  type t;

  external bool: bool => t = "%identity";
  [@bs.obj] external make: (~goButton: element) => t = "";
};

module Size = {
  type t = string;

  [@bs.inline]
  let small = "small";
};

[@bs.deriving abstract]
type makeProps = {
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
};

[@bs.module "antd/lib/pagination"] external make: component(makeProps) = "default";