

open React;

// bsc -bs-re-out ./lib/bs/src/Antd_Grid.cmi

module Col = {
 module Span = {
       type t;
       external number: int => t = "%identity";

       [@bs.obj]
       external make: (
           ~offset: int=?,
            ~order: int=?,
            ~pull: int=?,
            ~push: int=?,
            ~span: int=?,
            unit
       ) => t = "";

    };

    type props =  {. "children": option(React.element), "className": option(string),
        "lg": option(Span.t), "md": option(Span.t), "offset": option(int),
        "order": option(int), "prefixCls": option(string),
        "pull": option(int), "push": option(int), "sm": option(Span.t),
        "span": option(int), "style": option(ReactDOMRe.Style.t),
        "tabIndex": option(int), "title": option(string),
        "xl": option(Span.t), "xs": option(Span.t), "xxl": option(Span.t)};

   

    [@bs.obj] external makeProps:
      (~offset: int=?, ~order: int=?, ~pull: int=?, ~push: int=?,
      ~span: int=?, ~xs: Span.t=?, ~sm: Span.t=?, ~md: Span.t=?,
      ~lg: Span.t=?, ~xl: Span.t=?, ~xxl: Span.t=?, ~prefixCls: string=?,
      ~children: React.element=?, ~style: ReactDOMRe.Style.t=?,
      ~title: string=?, ~tabIndex: int=?, ~className: string=?,
      ~key: string=?, unit) =>
     props
      = "";
    [@bs.module] external make: component(props)
      = "antd/lib/grid/col";

    // [@react.component] [@bs.module] external make: (
    //     ~offset: int=?,
    //     ~order: int=?,
    //     ~pull: int=?,
    //     ~push: int=?,
    //     ~span: int=?,
    //     ~xs: Span.t=?,
    //     ~sm: Span.t=?,
    //     ~md: Span.t=?,
    //     ~lg: Span.t=?,
    //     ~xl: Span.t=?,
    //     ~xxl: Span.t=?,
    //     ~prefixCls: string=?,
    //     ~children: element=?,
    //     ~style: ReactDOMRe.Style.t=?,
    //     // html
    //     ~title: string=?,
    //     ~tabIndex: int=?,
    //     ~className: string=?,
    //     unit
    // ) => element = "antd/lib/grid/col";
};

module Row = {
    type props;

    module Gutter = {
        type t;
        external number: float => t = "%identity";

        [@bs.obj]
        external make: (
            ~xxl: float=?,
            ~xl: float=?,
            ~lg: float=?,
            ~md: float=?,
            ~sm: float=?,
            ~xs: float=?,
            unit
        ) => t = "";
    };
 

    [@react.component] [@bs.module] external make: (
        ~align: [@bs.string] [
            | `top
            | `middle
            | `bottom
        ]=?,
        ~gutter: Gutter.t=?,
        ~justify: [@bs.string] [
            | `start
            | [@bs.as "end"]`end_
            | `center
            | [@bs.as "space-around"] `spaceAround
            | [@bs.as "space-between"] `spaceBetween
        ]=?,
        ~_type: [@bs.string] [ | `flex ]=?,
        ~prefixCls: string=?,
        ~children: element=?,
        ~style: ReactDOMRe.Style.t=?,
        // html
        ~title: string=?,
        ~tabIndex: int=?,
        ~className: string=?,
        unit
    ) => element = "antd/lib/grid/row"
};