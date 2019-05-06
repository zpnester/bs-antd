open React;

type t;

[@bs.send] external blur: t => unit = "blur";
[@bs.send] external focus: t => unit = "focus";

module Suggestion = {
  type t;

  external string: string => t = "%identity";
  external nav: element => t = "%identity";
};

module ContentState = {
  type t;

  [@bs.module "antd/lib/mention"]
  external fromString: string => t = "toContentState";

  [@bs.module "antd/lib/mention"] external toString: t => string = "toString";
};

[@react.component] [@bs.module]
// ***** BEGIN MENTION ****
external make:
  (
    ~prefixCls: string=?,
    ~suggestionStyle: ReactDOMRe.Style.t=?,
    ~defaultSuggestions: array(Suggestion.t)=?,
    ~suggestions: array(Suggestion.t)=?,
    ~onSearchChange: (~value: string, ~trigger: string) => unit=?, // ret any skipped
    ~onChange: ContentState.t => unit=?, // ret any skipped
    ~notFoundContent: element=?, // todo test non string
    ~loading: bool=?,
    ~style: ReactDOMRe.Style.t=?,
    ~defaultValue: ContentState.t=?,
    ~value: ContentState.t=?,
    ~className: string=?,
    ~multiLines: bool=?,
    ~prefix: array(string)=?, // single string skipped
    ~placeholder: string=?,
    ~getSuggestionContainer: Dom.element => Dom.htmlElement=?,
    ~onFocus: ReactEvent.Synthetic.t => unit=?,
    ~onBlur: ReactEvent.Synthetic.t => unit=?,
    ~onSelect: (~suggestion: string, ~data: Js.Json.t) => unit=?, // ret any skipped // TODO data
    ~readOnly: bool=?,
    ~disabled: bool=?,
    ~placement: [@bs.string] [ | `top | `bottom]=?,
    // ***** END MENTION *****
    ~ref: Ref.t(Js.nullable(t))=?,
    unit
  ) =>
  element =
  "antd/lib/mention";

// no types in TS
module Nav = {
  [@react.component] [@bs.module "antd/lib/mention"]
  // ***** BEGIN NAV FROM WEBSITE ****
  external make:
    (
      ~value: string=?,
      ~children: element=?,
      ~data: Js.Json.t=?, // TODO
      // ***** END NAV FROM WEBSITE *****
      ~ref: Ref.t(Js.nullable(t))=?, // TODO ensure OK
      unit
    ) =>
    element =
    "Nav";
};