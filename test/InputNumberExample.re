

open Antd;
open React;
open Expect_;

[%%debugger.chrome]

[@react.component]
let make = () => {

    let (n, setN) = useState(() => Some(1.0));

    <>
    <h1 id="inputnumber-example">{string("InputNumber Example")}</h1>
    {string(n->Option.map(Js.Float.toString)->Option.getWithDefault(""))}
    <br />
    <InputNumber min={1.0} max={10.0}  
    size=`large
    formatter={x => {
        Js.log2("formatter", x);
        let result = switch (x) {
            | Some(`String(s)) => s
            | Some(`Number(f)) => f->Js.Float.toString
            | None => ""
        }
        Js.log2("formatter return", result);
        result
    }}
    defaultValue={n->Option.map(n => `Number(n))}
    parser={s => {
        Js.log2("parser", s);
        expectString(s);
        let result = try (Some(`Number(float_of_string(s)))) {
            | Failure("float_of_string") => Some(`String(s))
        }
        Js.log2("parser result", result);
        result
    }}
    placeholder="..."
    onChange={v => {
        Js.log2("onChange", v);
        let n = switch (v) {
            | Some(`Number(n)) => Some(n)
            | _ => None
        };
        setN(_ => n);
    }} 
    />
    </>
};