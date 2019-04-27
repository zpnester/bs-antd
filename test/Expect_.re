[@bs.val] [@bs.module "./expect"] external expectToEqual: ('a, 'a) => unit = "expectToEqual";
[@bs.val] [@bs.module "./expect"] external expectToEqualAny: ('a, 'b) => unit = "expectToEqual"; 
[@bs.val] [@bs.module "./expect"] external isArray: 'a => bool = "isArray"; 
[@bs.val] [@bs.module "./expect"] external isElement: 'a => bool = "isElement"; 

let expectString  = (s: string) => {
    expectToEqual(s->Js.typeof, "string");
}

let expectMaybeString = (s: option(string)) => {
    switch (s) {
        | None => ()
        | Some(s) => expectString(s)
    }
};

let expectElement = (el: React.element) => {
  expectToEqual(el->isElement, true);
};

let expectMaybeElement = (el: option(React.element)) => {
  switch (el) {
  | None => () // ok
  | Some(el) => expectToEqual(el->isElement, true)
  };
};