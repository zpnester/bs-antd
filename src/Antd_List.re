open React;

module ColumnCount = {
  type t = int;

  [@bs.inline]
  let _1 = 1;
  [@bs.inline]
  let _2 = 2;
  [@bs.inline]
  let _3 = 3;
  [@bs.inline]
  let _4 = 4;
  [@bs.inline]
  let _6 = 6;
  [@bs.inline]
  let _8 = 8;
  [@bs.inline]
  let _12 = 12;
  [@bs.inline]
  let _24 = 24;
};

module Grid = {
  type t;

  [@bs.obj]
  external make:
    (
      ~gutter: float=?,
      ~column: ColumnCount.t=?,
      ~xs: ColumnCount.t=?,
      ~sm: ColumnCount.t=?,
      ~md: ColumnCount.t=?,
      ~lg: ColumnCount.t=?,
      ~xl: ColumnCount.t=?,
      ~xxl: ColumnCount.t=?,
      unit
    ) =>
    t =
    "";
};

module Loading = {
  type t;

  external bool: bool => t = "%identity";
  external spinProps: Antd_Spin.makeProps => t = "%identity";
};

module Pagination = {
  module Position = {
    type t = string;
    [@bs.inline]
    let top = "top";
    [@bs.inline]
    let bottom = "bottom";
    [@bs.inline]
    let both = "both";
  };

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

  type t;

  let false_: t = [%raw {| false |}];
  external make: Config.make => t = "%identity";
};

module Locale = {
  // docs are lying, func won't work for emptyText
  // "Functions are not valid as a React child"

  type t = {. "emptyText": element};
  // don't do bs.obj for simple objects
};

[@react.component] [@bs.module "antd/lib/list"]
external make:
  (
    ~bordered: bool=?,
    ~className: string=?,
    ~children: element=?,
    ~dataSource: array('data), // required
    ~extra: element=?,
    ~grid: Grid.t=?,
    ~id: string=?,
    ~itemLayout: [@bs.string] [ | `horizontal | `vertical]=?,
    ~loading: Loading.t=?,
    ~loadMore: element=?,
    ~pagination: Pagination.t=?,
    ~prefixCls: string=?,
    ~rowKey: 'data => string=?,
    ~renderItem: ('data, int) => element, // required (not really, just an api decision)
    ~size: [@bs.string] [ | `small | `default | `large]=?,
    ~split: bool=?,
    ~header: element=?,
    ~footer: element=?,
    ~locale: Locale.t=?,
    unit
  ) =>
  element =
  "default";

module Item = {
  [@bs.deriving abstract]
  type makeProps = {
    // ***** BEGIN HTML *****
    [@bs.optional]
    key: string,
    [@bs.optional]
    ref: ReactDOMRe.domRef,
    [@bs.optional] [@bs.as "aria-details"]
    ariaDetails: string,
    [@bs.optional] [@bs.as "aria-disabled"]
    ariaDisabled: bool,
    [@bs.optional] [@bs.as "aria-hidden"]
    ariaHidden: bool,
    [@bs.optional] [@bs.as "aria-keyshortcuts"]
    ariaKeyshortcuts: string,
    [@bs.optional] [@bs.as "aria-label"]
    ariaLabel: string,
    [@bs.optional] [@bs.as "aria-roledescription"]
    ariaRoledescription: string,
    [@bs.optional] [@bs.as "aria-expanded"]
    ariaExpanded: bool,
    [@bs.optional] [@bs.as "aria-level"]
    ariaLevel: int,
    [@bs.optional] [@bs.as "aria-modal"]
    ariaModal: bool,
    [@bs.optional] [@bs.as "aria-multiline"]
    ariaMultiline: bool,
    [@bs.optional] [@bs.as "aria-multiselectable"]
    ariaMultiselectable: bool,
    [@bs.optional] [@bs.as "aria-placeholder"]
    ariaPlaceholder: string,
    [@bs.optional] [@bs.as "aria-readonly"]
    ariaReadonly: bool,
    [@bs.optional] [@bs.as "aria-required"]
    ariaRequired: bool,
    [@bs.optional] [@bs.as "aria-selected"]
    ariaSelected: bool,
    [@bs.optional] [@bs.as "aria-sort"]
    ariaSort: string,
    [@bs.optional] [@bs.as "aria-valuemax"]
    ariaValuemax: float,
    [@bs.optional] [@bs.as "aria-valuemin"]
    ariaValuemin: float,
    [@bs.optional] [@bs.as "aria-valuenow"]
    ariaValuenow: float,
    [@bs.optional] [@bs.as "aria-valuetext"]
    ariaValuetext: string,
    [@bs.optional] [@bs.as "aria-atomic"]
    ariaAtomic: bool,
    [@bs.optional] [@bs.as "aria-busy"]
    ariaBusy: bool,
    [@bs.optional] [@bs.as "aria-relevant"]
    ariaRelevant: string,
    [@bs.optional] [@bs.as "aria-grabbed"]
    ariaGrabbed: bool,
    /* Relationship Attributes */
    [@bs.optional] [@bs.as "aria-activedescendant"]
    ariaActivedescendant: string,
    [@bs.optional] [@bs.as "aria-colcount"]
    ariaColcount: int,
    [@bs.optional] [@bs.as "aria-colindex"]
    ariaColindex: int,
    [@bs.optional] [@bs.as "aria-colspan"]
    ariaColspan: int,
    [@bs.optional] [@bs.as "aria-controls"]
    ariaControls: string,
    [@bs.optional] [@bs.as "aria-describedby"]
    ariaDescribedby: string,
    [@bs.optional] [@bs.as "aria-errormessage"]
    ariaErrormessage: string,
    [@bs.optional] [@bs.as "aria-flowto"]
    ariaFlowto: string,
    [@bs.optional] [@bs.as "aria-labelledby"]
    ariaLabelledby: string,
    [@bs.optional] [@bs.as "aria-owns"]
    ariaOwns: string,
    [@bs.optional] [@bs.as "aria-posinset"]
    ariaPosinset: int,
    [@bs.optional] [@bs.as "aria-rowcount"]
    ariaRowcount: int,
    [@bs.optional] [@bs.as "aria-rowindex"]
    ariaRowindex: int,
    [@bs.optional] [@bs.as "aria-rowspan"]
    ariaRowspan: int,
    [@bs.optional] [@bs.as "aria-setsize"]
    ariaSetsize: int,
    /* react textarea/input */
    [@bs.optional]
    defaultChecked: bool,
    [@bs.optional]
    defaultValue: string,
    /* global html attributes */
    [@bs.optional]
    accessKey: string,
    //   [@bs.optional]
    //   className: string, /* substitute for "class" */
    [@bs.optional]
    contentEditable: bool,
    [@bs.optional]
    contextMenu: string,
    [@bs.optional]
    dir: string, /* "ltr", "rtl" or "auto" */
    [@bs.optional]
    draggable: bool,
    [@bs.optional]
    hidden: bool,
    [@bs.optional]
    id: string,
    [@bs.optional]
    lang: string,
    [@bs.optional]
    role: string, /* ARIA role */
    //   [@bs.optional]
    //   style: ReactDOMRe.Style.t,
    [@bs.optional]
    spellCheck: bool,
    [@bs.optional]
    tabIndex: int,
    [@bs.optional]
    title: string,
    /* html5 microdata */
    [@bs.optional]
    itemID: string,
    [@bs.optional]
    itemProp: string,
    [@bs.optional]
    itemRef: string,
    [@bs.optional]
    itemScope: bool,
    [@bs.optional]
    itemType: string, /* uri */
    /* tag-specific html attributes */
    [@bs.optional]
    accept: string,
    [@bs.optional]
    acceptCharset: string,
    [@bs.optional]
    action: string, /* uri */
    [@bs.optional]
    allowFullScreen: bool,
    [@bs.optional]
    alt: string,
    [@bs.optional]
    async: bool,
    [@bs.optional]
    autoComplete: string, /* has a fixed, but large-ish, set of possible values */
    [@bs.optional]
    autoFocus: bool,
    [@bs.optional]
    autoPlay: bool,
    [@bs.optional]
    challenge: string,
    [@bs.optional]
    charSet: string,
    [@bs.optional]
    checked: bool,
    [@bs.optional]
    cite: string, /* uri */
    [@bs.optional]
    crossorigin: bool,
    [@bs.optional]
    cols: int,
    [@bs.optional]
    colSpan: int,
    [@bs.optional]
    content: string,
    [@bs.optional]
    controls: bool,
    [@bs.optional]
    coords: string, /* set of values specifying the coordinates of a region */
    [@bs.optional]
    data: string, /* uri */
    [@bs.optional]
    dateTime: string, /* "valid date string with optional time" */
    [@bs.optional]
    default: bool,
    [@bs.optional]
    defer: bool,
    [@bs.optional]
    disabled: bool,
    [@bs.optional]
    download: string, /* should really be either a boolean, signifying presence, or a string */
    [@bs.optional]
    encType: string, /* "application/x-www-form-urlencoded", "multipart/form-data" or "text/plain" */
    [@bs.optional]
    form: string,
    [@bs.optional]
    formAction: string, /* uri */
    [@bs.optional]
    formTarget: string, /* "_blank", "_self", etc. */
    [@bs.optional]
    formMethod: string, /* "post", "get", "put" */
    [@bs.optional]
    headers: string,
    [@bs.optional]
    height: string, /* in html5 this can only be a number, but in html4 it can ba a percentage as well */
    [@bs.optional]
    high: int,
    [@bs.optional]
    href: string, /* uri */
    [@bs.optional]
    hrefLang: string,
    [@bs.optional]
    htmlFor: string, /* substitute for "for" */
    [@bs.optional]
    httpEquiv: string, /* has a fixed set of possible values */
    [@bs.optional]
    icon: string, /* uri? */
    [@bs.optional]
    inputMode: string, /* "verbatim", "latin", "numeric", etc. */
    [@bs.optional]
    integrity: string,
    [@bs.optional]
    keyType: string,
    [@bs.optional]
    kind: string, /* has a fixed set of possible values */
    [@bs.optional]
    label: string,
    [@bs.optional]
    list: string,
    [@bs.optional]
    loop: bool,
    [@bs.optional]
    low: int,
    [@bs.optional]
    manifest: string, /* uri */
    [@bs.optional]
    max: string, /* should be int or Js.Date.t */
    [@bs.optional]
    maxLength: int,
    [@bs.optional]
    media: string, /* a valid media query */
    [@bs.optional]
    mediaGroup: string,
    [@bs.optional]
    method: string, /* "post" or "get" */
    [@bs.optional]
    min: int,
    [@bs.optional]
    minLength: int,
    [@bs.optional]
    multiple: bool,
    [@bs.optional]
    muted: bool,
    [@bs.optional]
    name: string,
    [@bs.optional]
    nonce: string,
    [@bs.optional]
    noValidate: bool,
    [@bs.optional] [@bs.as "open"]
    open_: bool, /* use this one. Previous one is deprecated */
    [@bs.optional]
    optimum: int,
    [@bs.optional]
    pattern: string, /* valid Js RegExp */
    [@bs.optional]
    placeholder: string,
    [@bs.optional]
    poster: string, /* uri */
    [@bs.optional]
    preload: string, /* "none", "metadata" or "auto" (and "" as a synonym for "auto") */
    [@bs.optional]
    radioGroup: string,
    [@bs.optional]
    readOnly: bool,
    [@bs.optional]
    rel: string, /* a space- or comma-separated (depending on the element) list of a fixed set of "link types" */
    [@bs.optional]
    required: bool,
    [@bs.optional]
    reversed: bool,
    [@bs.optional]
    rows: int,
    [@bs.optional]
    rowSpan: int,
    [@bs.optional]
    sandbox: string, /* has a fixed set of possible values */
    [@bs.optional]
    scope: string, /* has a fixed set of possible values */
    [@bs.optional]
    scoped: bool,
    [@bs.optional]
    scrolling: string, /* html4 only, "auto", "yes" or "no" */
    /* seamless - supported by React, but removed from the html5 spec */
    [@bs.optional]
    selected: bool,
    [@bs.optional]
    shape: string,
    [@bs.optional]
    size: int,
    [@bs.optional]
    sizes: string,
    [@bs.optional]
    span: int,
    [@bs.optional]
    src: string, /* uri */
    [@bs.optional]
    srcDoc: string,
    [@bs.optional]
    srcLang: string,
    [@bs.optional]
    srcSet: string,
    [@bs.optional]
    start: int,
    [@bs.optional]
    step: float,
    [@bs.optional]
    summary: string, /* deprecated */
    [@bs.optional]
    target: string,
    [@bs.optional] [@bs.as "type"]
    type_: string, /* has a fixed but large-ish set of possible values */ /* use this one. Previous one is deprecated */
    [@bs.optional]
    useMap: string,
    [@bs.optional]
    value: string,
    [@bs.optional]
    width: string, /* in html5 this can only be a number, but in html4 it can ba a percentage as well */
    [@bs.optional]
    wrap: string, /* "hard" or "soft" */
    /* Clipboard events */
    [@bs.optional]
    onCopy: ReactEvent.Clipboard.t => unit,
    [@bs.optional]
    onCut: ReactEvent.Clipboard.t => unit,
    [@bs.optional]
    onPaste: ReactEvent.Clipboard.t => unit,
    /* Composition events */
    [@bs.optional]
    onCompositionEnd: ReactEvent.Composition.t => unit,
    [@bs.optional]
    onCompositionStart: ReactEvent.Composition.t => unit,
    [@bs.optional]
    onCompositionUpdate: ReactEvent.Composition.t => unit,
    /* Keyboard events */
    [@bs.optional]
    onKeyDown: ReactEvent.Keyboard.t => unit,
    [@bs.optional]
    onKeyPress: ReactEvent.Keyboard.t => unit,
    [@bs.optional]
    onKeyUp: ReactEvent.Keyboard.t => unit,
    /* Focus events */
    [@bs.optional]
    onFocus: ReactEvent.Focus.t => unit,
    [@bs.optional]
    onBlur: ReactEvent.Focus.t => unit,
    /* Form events */
    [@bs.optional]
    onChange: ReactEvent.Form.t => unit,
    [@bs.optional]
    onInput: ReactEvent.Form.t => unit,
    [@bs.optional]
    onSubmit: ReactEvent.Form.t => unit,
    /* Mouse events */
    [@bs.optional]
    onClick: ReactEvent.Mouse.t => unit,
    [@bs.optional]
    onContextMenu: ReactEvent.Mouse.t => unit,
    [@bs.optional]
    onDoubleClick: ReactEvent.Mouse.t => unit,
    [@bs.optional]
    onDrag: ReactEvent.Mouse.t => unit,
    [@bs.optional]
    onDragEnd: ReactEvent.Mouse.t => unit,
    [@bs.optional]
    onDragEnter: ReactEvent.Mouse.t => unit,
    [@bs.optional]
    onDragExit: ReactEvent.Mouse.t => unit,
    [@bs.optional]
    onDragLeave: ReactEvent.Mouse.t => unit,
    [@bs.optional]
    onDragOver: ReactEvent.Mouse.t => unit,
    [@bs.optional]
    onDragStart: ReactEvent.Mouse.t => unit,
    [@bs.optional]
    onDrop: ReactEvent.Mouse.t => unit,
    [@bs.optional]
    onMouseDown: ReactEvent.Mouse.t => unit,
    [@bs.optional]
    onMouseEnter: ReactEvent.Mouse.t => unit,
    [@bs.optional]
    onMouseLeave: ReactEvent.Mouse.t => unit,
    [@bs.optional]
    onMouseMove: ReactEvent.Mouse.t => unit,
    [@bs.optional]
    onMouseOut: ReactEvent.Mouse.t => unit,
    [@bs.optional]
    onMouseOver: ReactEvent.Mouse.t => unit,
    [@bs.optional]
    onMouseUp: ReactEvent.Mouse.t => unit,
    /* Selection events */
    [@bs.optional]
    onSelect: ReactEvent.Selection.t => unit,
    /* Touch events */
    [@bs.optional]
    onTouchCancel: ReactEvent.Touch.t => unit,
    [@bs.optional]
    onTouchEnd: ReactEvent.Touch.t => unit,
    [@bs.optional]
    onTouchMove: ReactEvent.Touch.t => unit,
    [@bs.optional]
    onTouchStart: ReactEvent.Touch.t => unit,
    /* UI events */
    [@bs.optional]
    onScroll: ReactEvent.UI.t => unit,
    /* Wheel events */
    [@bs.optional]
    onWheel: ReactEvent.Wheel.t => unit,
    /* Media events */
    [@bs.optional]
    onAbort: ReactEvent.Media.t => unit,
    [@bs.optional]
    onCanPlay: ReactEvent.Media.t => unit,
    [@bs.optional]
    onCanPlayThrough: ReactEvent.Media.t => unit,
    [@bs.optional]
    onDurationChange: ReactEvent.Media.t => unit,
    [@bs.optional]
    onEmptied: ReactEvent.Media.t => unit,
    [@bs.optional]
    onEncrypetd: ReactEvent.Media.t => unit,
    [@bs.optional]
    onEnded: ReactEvent.Media.t => unit,
    [@bs.optional]
    onError: ReactEvent.Media.t => unit,
    [@bs.optional]
    onLoadedData: ReactEvent.Media.t => unit,
    [@bs.optional]
    onLoadedMetadata: ReactEvent.Media.t => unit,
    [@bs.optional]
    onLoadStart: ReactEvent.Media.t => unit,
    [@bs.optional]
    onPause: ReactEvent.Media.t => unit,
    [@bs.optional]
    onPlay: ReactEvent.Media.t => unit,
    [@bs.optional]
    onPlaying: ReactEvent.Media.t => unit,
    [@bs.optional]
    onProgress: ReactEvent.Media.t => unit,
    [@bs.optional]
    onRateChange: ReactEvent.Media.t => unit,
    [@bs.optional]
    onSeeked: ReactEvent.Media.t => unit,
    [@bs.optional]
    onSeeking: ReactEvent.Media.t => unit,
    [@bs.optional]
    onStalled: ReactEvent.Media.t => unit,
    [@bs.optional]
    onSuspend: ReactEvent.Media.t => unit,
    [@bs.optional]
    onTimeUpdate: ReactEvent.Media.t => unit,
    [@bs.optional]
    onVolumeChange: ReactEvent.Media.t => unit,
    [@bs.optional]
    onWaiting: ReactEvent.Media.t => unit,
    /* Image events */
    [@bs.optional]onLoad: ReactEvent.Image.t => unit /* duplicate */, /*~onError: ReactEvent.Image.t => unit=?,*/
    /* Animation events */
    [@bs.optional]
    onAnimationStart: ReactEvent.Animation.t => unit,
    [@bs.optional]
    onAnimationEnd: ReactEvent.Animation.t => unit,
    [@bs.optional]
    onAnimationIteration: ReactEvent.Animation.t => unit,
    /* Transition events */
    [@bs.optional]
    onTransitionEnd: ReactEvent.Transition.t => unit,
    /* RDFa */
    [@bs.optional]
    about: string,
    [@bs.optional]
    datatype: string,
    [@bs.optional]
    inlist: string,
    [@bs.optional]
    prefix: string,
    [@bs.optional]
    property: string,
    [@bs.optional]
    resource: string,
    [@bs.optional]
    typeof: string,
    [@bs.optional]
    vocab: string,
    /* react-specific */
    [@bs.optional]
    dangerouslySetInnerHTML: {. "__html": string},
    [@bs.optional]
    suppressContentEditableWarning: bool,
    // ***** END HTML *****
    // ***** BEGIN ITEM *****
    [@bs.optional]
    className: string,
    [@bs.optional]
    children: element,
    [@bs.optional]
    prefixCls: string,
    [@bs.optional]
    style: ReactDOMRe.Style.t,
    [@bs.optional]
    extra: element,
    [@bs.optional]
    actions: array(element),
    [@bs.optional]
    grid: Grid.t,
    // ***** END ITEM *****
  };

  [@bs.module "antd/lib/list/Item"]
  external make: component(makeProps) = "default";

  module Meta = {
    [@react.component] [@bs.module "antd/lib/list/Item"] [@bs.scope "default"]
    external make:
      (
        ~avatar: element=?,
        ~className: string=?,
        ~children: element=?,
        ~description: element=?,
        ~prefixCls: string=?,
        ~style: ReactDOMRe.Style.t=?,
        ~title: element=?,
        unit
      ) =>
      element =
      "Meta";
  };
};