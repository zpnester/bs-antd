open React;
open Antd;
open Table;
open Expect_;

type user = {
  .
  "key": string,
  "age": int,
  "address": string,
  "name": string,
};

let expectUser = (u: user) => {
  expectString(u##key);
  expectString(u##address);
  expectString(u##name);
  expectInt(u##age);
};

[@react.component]
let make = () => {
  let dataSource = [|
    {"key": "1", "name": "Mike", "age": 32, "address": "10 Downing Street"},
    {"key": "2", "name": "John", "age": 42, "address": "20 Downing Street"},
  |];

  let columns = [|
    Column.make(
      ~title=_ => string("Name"),
      // ~dataIndex="name",
      ~key="name",
      ~render=
        (text, record, index) => {
          Js.log4("column render", text, record, index);
          // TODO expect text
          // simple test: text == record
          expectUser(record);
          expectInt(index);
          string(record##name ++ "!");
        },
      (),
    ),
    Column.make(~title=_ => string("Age"), ~dataIndex="age", ~key="age", ()),
    Column.make(
      ~title=_ => string("Address"),
      ~dataIndex="address",
      ~key="address",
      (),
    ),
  |];

  <>
    <h1 id="table-example"> {string("Table Example")} </h1>
    <Table dataSource columns />
    <h1> {string("TODO TABLE")} </h1>
  </>;
};
