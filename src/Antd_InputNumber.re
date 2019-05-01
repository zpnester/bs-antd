

open React;

type t;

[@bs.send] external blur: t => unit = "blur";
[@bs.send] external focus: t => unit = "focus";


type value = option([`String(string) | `Number(float)]);

let valueToJson = value => {
    switch (value) {
        | None => Js.Json.null
        | Some(`String(s)) => Js.Json.string(s)
        | Some(`Number(f)) => Js.Json.number(f)
    }
};

let valueFromJson = json => {
    switch (json->Js.Json.decodeString) {
        | Some(s) => Some(`String(s))
        | None =>
            switch (json->Js.Json.decodeNumber) {
                | Some(f) => Some(`Number(f))
                | None => None
            }
    }
};

type props;

[@bs.obj] external 
makeProps_: (
    ~ref: Ref.t(Js.nullable(t))=?,
    ~autoFocus: bool=?,
    ~defaultValue: Js.Json.t=?,
    ~disabled: bool=?,
    ~formatter: Js.Json.t => string=?,
    ~max: float=?,
    ~min: float=?,
    ~parser: string => Js.Json.t=?, 
    ~precision: float=?,
    ~decimalSeparator: string=?,
    ~size: [@bs.string] [
        | `large
        | `small
        | `default
    ]=?,
    ~step: float=?,
    ~value: Js.Json.t=?,
    ~onChange: Js.Json.t => unit=?,
    ~prefixCls: string=?,
    ~placeholder: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~className: string=?,
    ~name: string=?,
    ~id: string=?,
    unit
) => props = "";


let makeProps = (
    ~ref: option(Ref.t(Js.nullable(t)))=?,
    ~autoFocus: option(bool)=?,
    ~defaultValue: option(value)=?,
    ~disabled: option(bool)=?,
    ~formatter: option(value => string)=?,
    ~max: option(float)=?,
    ~min: option(float)=?,
    ~parser: option(string => value)=?, 
    ~precision: option(float)=?,
    ~decimalSeparator: option(string)=?,
    ~size: option([
        | `large
        | `small
        | `default
    ])=?,
    ~step: option(float)=?,
    ~value: option(value)=?,
    ~onChange: option(value => unit)=?,
    ~prefixCls: option(string)=?,
    ~placeholder: option(string)=?,
    ~style: option(ReactDOMRe.Style.t)=?,
    ~className: option(string)=?,
    ~name: option(string)=?,
    ~id: option(string)=?,
    ()) => {
        makeProps_(
            ~ref?,
            ~autoFocus?,
            ~defaultValue=?defaultValue->Option.map(valueToJson),
            ~disabled?,
            ~formatter=?formatter->Option.map(f => {
                json => f(valueFromJson(json))
            }),
            ~max?,
            ~min?,
            ~parser=?parser->Option.map(f => {
                s => f(s)->valueToJson
            }),
            ~precision?,
            ~decimalSeparator?,
            ~size?,
            ~step?,
            ~value=?value->Option.map(valueToJson),
            ~onChange=?onChange->Option.map(f => {
                json => f(json->valueFromJson)
            }),
            ~prefixCls?,
            ~placeholder?,
            ~style?,
            ~className?,
            ~name?,
            ~id?,
            ()
        );
    };


[@bs.module]
external make: component(props) = "antd/lib/input-number";
 
