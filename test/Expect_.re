[@bs.val] [@bs.module "./expect"] external expectToEqual: ('a, 'a) => unit = "expectToEqual";
[@bs.val] [@bs.module "./expect"] external expectToEqualAny: ('a, 'b) => unit = "expectToEqual"; 
[@bs.val] [@bs.module "./expect"] external isArray: 'a => bool = "isArray"; 
[@bs.val] [@bs.module "./expect"] external isElement: 'a => bool = "isElement"; 
[@bs.val] [@bs.module "./expect"] external isInt: 'a => bool = "isInt"; 
[@bs.val] [@bs.module "./expect"] external isNull: 'a => bool = "isNull"; 
[@bs.val] [@bs.module "./expect"] external isUndefined: 'a => bool = "isUndefined"; 
[@bs.val] [@bs.module "./expect"] external hasLen: ('a, int) => bool = "hasLen"; 

[@bs.module "moment"] external isMoment: 'a => bool = "isMoment";

let isNumber = (x: 'a) => {
  x->Js.typeof == "number";
};

let isString = (x: 'a) => {
  x->Js.typeof == "string";
};

let expectMoment = (m: MomentRe.Moment.t) => {
  expectToEqual(m->isMoment, true);
};

let expectNumber = (f: float) => {
  expectToEqual(f->Js.typeof, "number");
};


let expectBool = (b: bool) => {
  expectToEqual(b->Js.typeof, "boolean");
};

let expectMomentOption = (m: option(MomentRe.Moment.t)) => {
  switch (m) {
    | None => ()
    | Some(m) => expectMoment(m);
  }
};

let expectFloat = (f: float) => {
  expectToEqual(f->Js.typeof, "number");
};

let expectMaybeFloat = (f: option(float)) => {
  switch (f) {
    | None => ()
    | Some(f) => expectFloat(f)
  }
};

let expectInt = (i: int) => {
  expectToEqual(i->isInt, true);
};

let expectNull = (x: 'a) => {
  expectToEqual(x->isNull, true);
}

let expectNullInt = (i: Js.null(int)) => {
  switch (i->Js.Null.toOption) {
    | None => expectNull(i)
    | Some(i) => expectInt(i)
  }
};

let expectNullMoment = (m: Js.null(MomentRe.Moment.t)) => {
  expectToEqual(m->Js.typeof, "object");
  switch (m->Js.Null.toOption) {
    | None => ()
    | Some(m) => m->expectMoment
  }
};

let expectMaybeMoment = (m: option(MomentRe.Moment.t)) => {
  switch (m) {
    | None => ()
    | Some(m) => m->expectMoment
  }
};

let expectArray = (arr: array('a)) => {
  expectToEqual(arr->isArray, true);
};

let expectArrayAny = (arr: 'a) => {
  expectToEqual(arr->isArray, true);
};


let expectMomentArray = (m: array(MomentRe.Moment.t)) => {
  expectArray(m);
  m->Array.forEach(expectMoment);
};

let expectNullMomentArray = (m: array(Js.null(MomentRe.Moment.t))) => {
  expectArray(m);
  m->Array.forEach(expectNullMoment);
};

let expectNullMomentArrayOption = (m: option(array(Js.null(MomentRe.Moment.t)))) => {
  switch (m) {
    | None => ()
    | Some(a) => expectNullMomentArray(a);
  }
};

let expectNullMomentTuple = (t: (Js.null(MomentRe.Moment.t), Js.null(MomentRe.Moment.t))) => {
  expectArrayAny(t);
  expectToEqual(t->hasLen(2), true);
  expectNullMoment(fst(t));
  expectNullMoment(snd(t));
};




let expectString  = (s: string) => {
    expectToEqual(s->Js.typeof, "string");
};

let expectStringAny  = (s: 'a) => {
    expectToEqual(s->Js.typeof, "string");
};

let expectStringArray = (s: array(string)) => {
  expectToEqual(s->isArray, true);
  s->Array.forEach(expectString);
};

let expectStringTuple2 = (t: (string, string)) => {
  expectArrayAny(t);
  expectToEqual(t->hasLen(2), true)
  expectString(fst(t));
  expectString(snd(t));
};

let expectNumberTuple2 = (t: (float, float)) => {
  expectArrayAny(t);
  expectToEqual(t->hasLen(2), true)
  expectNumber(fst(t));
  expectNumber(snd(t));
};


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

let expectObject = (x: 'a) => {
  expectToEqual(x->Js.typeof, "object");
};

let expectLocale = (x: Antd_Locale.t) => {
  Js.log("EXPECT LOCALE NOT IMPLEMENTED YET");
};