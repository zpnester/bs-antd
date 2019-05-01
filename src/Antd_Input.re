
open React;

[@react.component] [@bs.module]
external make: (
  ~addonAfter: element=?,
  ~addonBefore: element=?,
  ~defaultValue: string=?,
  ~disabled: bool=?,
  ~id: string=?,
  ~prefix: element=?,
  ~size: [@bs.string] [
      | `large 
       | `default 
       | `small
  ]=?,
  ~suffix: element=?,
  ~_type: string=?,
  ~value: string=?,
  ~onPressEnter: ReactEvent.Keyboard.t=?,
  ~allowClear: bool=?,
  ~onChange: ReactEvent.Form.t => unit=?, // TODO
  // react
  ~placeholder: string=?,
  ~accept: string=?,
  ~alt: string=?,
  ~autoComplete: string=?,
  ~autoFocus: bool=?,
  // ~capture
  // checked not needed
  ~crossOrigin: bool=?,
  ~form: string=?,
  ~formAction: string=?,
  // formEncType
  ~formMethod: string=?,
  // formNoValidate
  ~formTarget: string=?,
  ~list: string=?,
  ~max: string=?, // TODO
  ~maxLength: int=?,
  ~min: int=?, // TODO
  ~minLength: int=?,
  // multiple not needed
  ~name: string=?,
  ~pattern: string=?,
  ~readOnly: bool=?,
  ~required: bool=?,
  ~src: string=?,
  ~step: float=?,
  ~width: string=?,
  unit
) => element = "antd/lib/input";

module TextArea = {

 module AutoSize = {
    type t;
    external bool: bool => t = "%identity";
    external object_: {. "minRows": option(int), "maxRows": option(int)} => t = "%identity";
 };
 
  [@react.component] [@bs.module]
  external make: (
    ~autosize: AutoSize.t=?,
    ~defaultValue: string=?,
    ~value: string=?,
    ~onPressEnter: ReactEvent.Keyboard.t => unit=?,
    // from react
    ~autofocus: bool=?,
    ~cols: int=?,
    ~disabled: bool=?,
    ~form: string=?,
    ~maxlength: int=?,
    ~minlength: int=?,
    ~name: string=?,
    ~placeholder: string=?,
    ~readonly: bool=?,
    ~required: bool=?,
    ~rows: int=?,
    ~spellcheck: bool=?,
    ~wrap: string=?,
    unit
  ) => element = "antd/lib/input/TextArea";
  
};


module Search = {


  module EnterButton = {
    type t;
    external bool: bool => t = "%identity";
    external element: element => t = "%identity";

  };

  [@react.component] [@bs.module]
  external make: (
    ~enterButton: EnterButton.t=?,
     ~onSearch: (string, ReactEvent.Synthetic.t) => unit=?, //  mouse/keyboard
     // Input copy paste
      ~addonAfter: element=?,
  ~addonBefore: element=?,
  ~defaultValue: string=?,
  ~disabled: bool=?,
  ~id: string=?,
  ~prefix: element=?,
  ~size: [@bs.string] [
      | `large 
       | `default 
       | `small
  ]=?,
  ~suffix: element=?,
  ~_type: string=?,
  ~value: string=?,
  ~onPressEnter: ReactEvent.Keyboard.t=?,
  ~allowClear: bool=?,
  ~onChange: ReactEvent.Form.t => unit=?, // TODO
  // react
  ~placeholder: string=?,
  ~accept: string=?,
  ~alt: string=?,
  ~autoComplete: string=?,
  ~autoFocus: bool=?,
  // ~capture
  // checked not needed
  ~crossOrigin: bool=?,
  ~form: string=?,
  ~formAction: string=?,
  // formEncType
  ~formMethod: string=?,
  // formNoValidate
  ~formTarget: string=?,
  ~list: string=?,
  ~max: string=?, // TODO
  ~maxLength: int=?,
  ~min: int=?, // TODO
  ~minLength: int=?,
  // multiple not needed
  ~name: string=?,
  ~pattern: string=?,
  ~readOnly: bool=?,
  ~required: bool=?,
  ~src: string=?,
  ~step: float=?,
  ~width: string=?,
    unit
  ) => element = "antd/lib/input/Search";
  
};


module Group = {


  [@react.component] [@bs.module]
  external make: (
    ~compact: bool=?,
    ~size: [@bs.string] [
      | `large 
      | `default 
      | `small
    ]=?,
    ~children: element=?,
    unit
  ) => element = "antd/lib/input/Group";
  
};



module Password  = {


  [@react.component] [@bs.module]
  external make: (
   ~visibilityToggle: bool=?,
     // Input copy paste
      ~addonAfter: element=?,
  ~addonBefore: element=?,
  ~defaultValue: string=?,
  ~disabled: bool=?,
  ~id: string=?,
  ~prefix: element=?,
  ~size: [@bs.string] [
      | `large 
       | `default 
       | `small
  ]=?,
  ~suffix: element=?,
  ~_type: string=?,
  ~value: string=?,
  ~onPressEnter: ReactEvent.Keyboard.t=?,
  ~allowClear: bool=?,
  ~onChange: ReactEvent.Form.t => unit=?, // TODO
  // react
  ~placeholder: string=?,
  ~accept: string=?,
  ~alt: string=?,
  ~autoComplete: string=?,
  ~autoFocus: bool=?,
  // ~capture
  // checked not needed
  ~crossOrigin: bool=?,
  ~form: string=?,
  ~formAction: string=?,
  // formEncType
  ~formMethod: string=?,
  // formNoValidate
  ~formTarget: string=?,
  ~list: string=?,
  ~max: string=?, // TODO
  ~maxLength: int=?,
  ~min: int=?, // TODO
  ~minLength: int=?,
  // multiple not needed
  ~name: string=?,
  ~pattern: string=?,
  ~readOnly: bool=?,
  ~required: bool=?,
  ~src: string=?,
  ~step: float=?,
  ~width: string=?,
    unit
  ) => element = "antd/lib/input/Password";
  
};
