open React;
open Antd;
open Mentions;
open Expect_;



type window;
let window: option(window) = [%external window];

type data = {
  a: string,
  b: int
};

let expectData = d => {
  expectString(d.a);
  expectInt(d.b);
};


[@react.component]
let make = () => {
  

  let (value, setValue) = useState(() => "hello");





  <>
    <h1 id="mentions-example"> {string("Mentions Example")} </h1>

    <Mentions prefix=[|"@", "$"|]
                style={ReactDOMRe.Style.make(~width="100%", ())}
                 value
                          onChange={value => {
                            expectString(value);
                            setValue(_ => value)
                          }}
//                           loading=true
                           rows=5
                          onSearch={(value, ~prefix) => {
                            Js.log3("onSearch", value, prefix);
                            expectString(value);
                            expectString(prefix);
                          }}
                          notFoundContent={<h1>{string("NOT FOUND")}</h1>}
                          validateSearch={(s, opts) => {
                            Js.log3("validateSearch", s, opts);
                            expectString(s);
                            expectObject(opts); // todo
                            s != "123"
                          }}
                          onSelect={(x, ~prefix) => {
                            Js.log3("onSelect", x, prefix);
                            expectObject(x); // TODO
                            expectString(prefix)
                          }}
                         filterOption=FilterOption.make((s, opts) => {
                            Js.log3("filterOption", s, opts);
                            if (s == "hello" && opts##value == "hello2") {
                                false
                            } else {
                                true
                            }
                         })
            >
                <Option value="hello">
                    {string("hello")}
                </Option>
                <Option value="world">
                     <h2>{string("World")}</h2>
                </Option>
                 <Option value="hello2">
                     <h2>{string("Other Hello")}</h2>
                </Option>
            </Mentions>
    
  </>;
};