

open React;

// type form = {
//             .
//             [@bs.meth] "getFieldDecorator": (string, option(GetFieldDecoratorOptions.t)) => (element => element),
//             [@bs.meth] "getFieldError": string => array(fieldError),
//             [@bs.meth] "getFieldsError": array(string) => fieldError, // TODO input option?
//             [@bs.meth] "getFieldsValue": array(string) => fieldValue,
//             [@bs.meth] "getFieldValue": string => fieldValue,
//             [@bs.meth] "isFieldsTouched": array(string) => bool,
//             [@bs.meth] "isFieldTouched": string => bool,
//             [@bs.meth] "isFieldValidating": string => bool,
//             [@bs.meth] "resetFields": array(string) => unit,
//             [@bs.meth] "setFields": Js.Dict.t({
//                 .
//                 "value": fieldValue,
//                 "errors": array(fieldError)
//             }) => unit,
//             [@bs.meth] "setFieldsValue": Js.Dict.t(fieldValue) => unit,
//             [@bs.meth] "validateFields": (array(string), 
//               option(ValidateOptions.t),
//              option((validateCallbackError,validateCallbackValue) => unit)) => unit,
//             [@bs.meth] "validateFieldsAndScroll": (array(string), 
//               option(ValidateOptions.t),
//              option((validateCallbackError,validateCallbackValue) => unit)) => unit
//         };

type props = {. 
// TODO
"children": option(React.element),
                        "className": option(string), "colon": option(bool),
                        "hideRequiredMark": option(bool),
                        "labelAlign": option(string),
                        "labelCol": option(Antd_Grid.Col.props),
                        "layout": option(string),
                        "onSubmit": option(ReactEvent.Form.t => unit),
                        "prefixCls": option(string),
                        "style": option(ReactDOMRe.Style.t),
                        "wrapperCol": option(Antd_Grid.Col.props)};

// type wrappedProps = {. 
// // TODO
//         // "wrappedComponentRef"
//         "form": form,
// "children": option(React.element),
//                         "className": option(string), "colon": option(bool),
//                         "hideRequiredMark": option(bool),
//                         "labelAlign": option(string),
//                         "labelCol": option(Antd_Grid.Col.props),
//                         "layout": option(string),
//                         "onSubmit": option(ReactEvent.Form.t => unit),
//                         "prefixCls": option(string),
//                         "style": option(ReactDOMRe.Style.t),
//                         "wrapperCol": option(Antd_Grid.Col.props)};

[@bs.obj] external makeProps:
  (
      ~hideRequiredMark: bool=?, ~labelAlign: [@bs.string] [ `left | `right ]=?,
  ~labelCol: Antd_Grid.Col.props=?,
  ~layout: [@bs.string] [ `horizontal | `inline | `vertical ]=?,
  ~onSubmit: ReactEvent.Form.t => unit=?, ~wrapperCol: Antd_Grid.Col.props=?,
  ~colon: bool=?, ~style: ReactDOMRe.Style.t=?, ~className: string=?,
  ~prefixCls: string=?, ~children: React.element=?, ~key: string=?, unit) =>
 props
  = "";
[@bs.module ] external make: component(props) = "antd/lib/form";

// [@react.component] [@bs.module]
// external make: (
//     ~hideRequiredMark: bool=?, ~labelAlign: [@bs.string] [ `left | `right ]=?,
//   ~labelCol: Antd_Grid.Col.props=?,
//   ~layout: [@bs.string] [ `horizontal | `inline | `vertical ]=?,
//   ~onSubmit: ReactEvent.Form.t => unit=?, ~wrapperCol: Antd_Grid.Col.props=?,
//   ~colon: bool=?, ~style: ReactDOMRe.Style.t=?, ~className: string=?,
//   ~prefixCls: string=?, ~children: React.element=?, ~key: string=?,
//     unit
// ) => element = "antd/lib/form";

 // TODO
   module DomScrollIntoViewConfig = {
      type t;

    //   [@bs.obj] external make
   };

    module ValidateOptions = {
    type t;
    [@bs.obj] external make: (
      ~first: bool=?,
       ~firstFields: array(string)=?,
       ~force: bool=?,
       ~scroll: DomScrollIntoViewConfig.t=?,
      unit
    ) => t = "";
       
    };


type formField;



module ValidationRule = {
    type t;

    [@bs.obj]
    external make: (
        ~enum: array(string)=?, // string skipped
        ~len: int=?,
        ~max: float=?,
        ~message: element=?,
        ~min: float=?,
        ~pattern: Js.Re.t=?,
        ~required: bool=?,
        // ~transform // TODO
        // https://github.com/yiminghe/async-validator#type
        ~_type: [@bs.string] [
            | `string
            | `number
            | `boolean
            | `method
            | `regexp
            | `integer
            | `float
            | `array
            | [@bs.as "object"] `object_
            | `enum
            | `date
            | `url
            | `hex
            | `email
        ]=?,
        // ~validator // TODO
        ~whitespace: bool=?,
        unit
    ) => t = ""
};

module GetFieldDecoratorOptions = {
    type t;

    // type getValueFromEvent;
    
    external makeUnsafe: Js.t({..}) => t = "%identity";

// TODO
    [@bs.obj] external make: (
    //    ~getValueFromEvent: getValueFromEvent=?,
        // ~getValueProps  // TODO
        // ~initialValue: // TODO
        // ~normalize // TODO
        ~valuePropName: string=?,
        ~initialValue: 'value=?, // TODO
        ~rules: array(ValidationRule.t)=?,
        unit
    ) => t = "";
};

module Decorated = {
    type fieldError;
    type fieldValue;



    type validateCallbackError = Js.Dict.t({
                .
                "errors": array({
                    .
                    "message": string,
                    "field": string
                })
            });

    type validateCallbackValue = Js.Dict.t(Js.Json.t); // TODO

    type form;

    // [@bs.send] external getFieldDecorator: (form, string, option(GetFieldDecoratorOptions.t)) => (element => element) = "getFieldDecorator";
    let getFieldDecorator: (form, string, GetFieldDecoratorOptions.t, element) => element = [%raw {|
    function(form, string, opts, element) {
        return form.getFieldDecorator(string, opts)(element);
    }
    |}];

    [@bs.send] external validateFields3: (form, array(string), 
              ValidateOptions.t,
             (validateCallbackError, validateCallbackValue) => unit) => unit = "validateFields";

[@bs.send] external validateFields2: (form, array(string), 
              ValidateOptions.t) => unit = "validateFields";

              [@bs.send] external validateFields1: (form, array(string)) => unit = "validateFields";
              [@bs.send] external validateFields1_: (form, ValidateOptions.t) => unit = "validateFields";
              [@bs.send] external validateFields1__: (form, (validateCallbackError, validateCallbackValue) => unit) => unit = "validateFields";




   
    type props = {
        .
        "form": form
        // "form": {
        //     .
        //      "getFieldDecorator": (. string, option(GetFieldDecoratorOptions.t)) => ( element => element),
        //     [@bs.meth] "getFieldError": string => array(fieldError),
        //     [@bs.meth] "getFieldsError": array(string) => fieldError, // TODO input option?
        //     [@bs.meth] "getFieldsValue": array(string) => fieldValue,
        //     [@bs.meth] "getFieldValue": string => fieldValue,
        //     [@bs.meth] "isFieldsTouched": array(string) => bool,
        //     [@bs.meth] "isFieldTouched": string => bool,
        //     [@bs.meth] "isFieldValidating": string => bool,
        //     [@bs.meth] "resetFields": array(string) => unit,
        //     [@bs.meth] "setFields": Js.Dict.t({
        //         .
        //         "value": fieldValue,
        //         "errors": array(fieldError)
        //     }) => unit,
        //     [@bs.meth] "setFieldsValue": Js.Dict.t(fieldValue) => unit,
        //     [@bs.meth] "validateFields": (array(string), 
        //       option(ValidateOptions.t),
        //      option((validateCallbackError,validateCallbackValue) => unit)) => unit,
        //     [@bs.meth] "validateFieldsAndScroll": (array(string), 
        //       option(ValidateOptions.t),
        //      option((validateCallbackError,validateCallbackValue) => unit)) => unit
        // }
    };

//     type props = {
//         . 
        
//         "children": option(React.element),
//         "className": option(string), "colon": option(bool),
//         "hideRequiredMark": option(bool),
//         "labelAlign": option(string),
//         "labelCol": option(Antd_Grid.Col.props),
//         "layout": option(string),
//         "onSubmit": option(ReactEvent.Form.t => unit),
//         "prefixCls": option(string),
//         "style": option(ReactDOMRe.Style.t),
//         "wrapperCol": option(Antd_Grid.Col.props)
//     };

//     [@bs.obj] external makeProps:
//   (~hideRequiredMark: bool=?, ~labelAlign: [@bs.string] [ `left | `right ]=?,
//   ~labelCol: Antd_Grid.Col.props=?,
//   ~layout: [@bs.string] [ `horizontal | `inline | `vertical ]=?,
//   ~onSubmit: ReactEvent.Form.t => unit=?, ~wrapperCol: Antd_Grid.Col.props=?,
//   ~colon: bool=?, ~style: ReactDOMRe.Style.t=?, ~className: string=?,
//   ~prefixCls: string=?, ~children: React.element=?, ~key: string=?, unit) =>
//  props
//   = ""

};

module CreateOptions = {
    type t;

    [@bs.obj]
    external make: (
        ~mapPropsToFields: Js.Json.t => Js.Dict.t(formField)=?,
        ~name: string=?,
        // TODO string | FormCreateOptionMessagesCallback | FormCreateOptionMessages;
        ~validateMessages: Js.Dict.t(string)=?,
        ~onFieldsChange: (Js.Json.t , 'todo_fields, 'todo, string) => unit=?,
        ~onValuesChange: (Js.Json.t , 'todo, 'todo) => unit=?,
        unit
    ) => t = "";
};

// this one does not work, "couldn't tackle the currying"
// [@bs.module "antd/lib/form"] external create: (CreateOptions.t, component(Decorated.props)) => component(props) = "create"

let create: (CreateOptions.t, component(Decorated.props)) => component(props) = [%raw {|
function(opts, c) {
    var f = require("antd/lib/form");
    return f.create(opts)(c)
}
|}];

[@bs.module "antd/lib/form"] external createFormField: 'value => formField = "createFormField"; // TODO test



module Item = {
  

   [@react.component] [@bs.module "antd/lib/form/"] external make: (
      ~colon: bool=?,
      ~extra: element=?,
      ~hasFeedback: bool=?,
      ~help: element=?,
      ~label: element=?,
      ~labelCol: Antd_Grid.Col.props=?,
      ~required: bool=?,
      ~validateStatus: [@bs.string] [
          | `success
          | `warning
          | `error
          | `validating
      ]=?,
      ~wrapperCol: Antd_Grid.Col.props=?,
      ~prefixCls: string=?,
      ~className: string=?,
      ~id: string=?,
      ~labelAlign: [@bs.string] [
          | `left 
          | `right
      ]=?,
      ~style: ReactDOMRe.Style.t=?,
      ~children: element=?,
      unit

   ) => element = "Item"
 };
