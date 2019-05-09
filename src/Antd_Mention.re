open React;

type t;

[@bs.send] external blur: t => unit = "blur";
[@bs.send] external focus: t => unit = "focus";

module ContentState = {
  type t;

  [@bs.module "antd/lib/mention"]
  external fromString: string => t = "toContentState";

  [@bs.module "antd/lib/mention"]
  external getMentions: t => array(string) = "getMentions";

  [@bs.module "antd/lib/mention"] external toString: t => string = "toString";
};

// private
module Nav = {
  [@react.component] [@bs.module "antd/lib/mention"]
  // ***** BEGIN NAV FROM WEBSITE ****
  external make:
    (
      ~value: string,
      ~children: element,
      ~data: 'data=?,
      // ***** END NAV FROM WEBSITE *****
      unit
    ) =>
    element =
    "Nav";
};

module Suggestion = {
  type t;

  external elemToTUnsafe: element => t = "%identity";

  // data available with Make functor
  let make = (~value: string, ~children: element) => {
    elemToTUnsafe(<Nav value> children </Nav>);
  };
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
    ~notFoundContent: element=?,
    ~loading: bool=?,
    ~style: ReactDOMRe.Style.t=?,
    ~defaultValue: ContentState.t=?,
    ~value: ContentState.t=?,
    ~className: string=?,
    ~multiLines: bool=?,
    ~prefix: array(string)=?, // single string skipped
    ~placeholder: string=?,
    ~getSuggestionContainer: Dom.element => Dom.htmlElement=?,
    ~onFocus: ReactEvent.Focus.t => unit=?,
    ~onBlur: ReactEvent.Focus.t => unit=?,
    ~onSelect: string => unit=?, // ret any skipped // second param available with Make functor
    ~readOnly: bool=?,
    ~disabled: bool=?,
    ~placement: [@bs.string] [ | `top | `bottom]=?,
    // ***** END MENTION *****
    ~ref: Ref.t(Js.nullable(t))=?,
    unit
  ) =>
  element =
  "antd/lib/mention";

///// with data
module Make = (M: {type data;}) => {
  module Suggestion = {
    type t;

    external elemToTUnsafe: element => t = "%identity";

    let make = (~data: M.data, ~value: string, ~children: element) => {
      elemToTUnsafe(<Nav data value> children </Nav>);
    };
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
      ~notFoundContent: element=?,
      ~loading: bool=?,
      ~style: ReactDOMRe.Style.t=?,
      ~defaultValue: ContentState.t=?,
      ~value: ContentState.t=?,
      ~className: string=?,
      ~multiLines: bool=?,
      ~prefix: array(string)=?, // single string skipped
      ~placeholder: string=?,
      ~getSuggestionContainer: Dom.element => Dom.htmlElement=?,
      ~onFocus: ReactEvent.Focus.t => unit=?,
      ~onBlur: ReactEvent.Focus.t => unit=?,
      ~onSelect: (string, M.data) => unit=?, // ret any skipped
      ~readOnly: bool=?,
      ~disabled: bool=?,
      ~placement: [@bs.string] [ | `top | `bottom]=?,
      // ***** END MENTION *****
      ~ref: Ref.t(Js.nullable(t))=?,
      unit
    ) =>
    element =
    "antd/lib/mention";
};