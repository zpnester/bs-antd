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
  expectInt(u##age);
  expectString(u##address);
  expectString(u##name);
};

let expectUserArray = (arr: array(user)) => {
  expectArray(arr);
  arr->Array.forEach(expectUser);
};

let expectExpandIconPropsOfUser = (x: expandIconProps(user)) => {
  expectString(x##prefixCls);
  expectBool(x##expanded);
  expectUser(x##record);
  expectBool(x##needIndentSpaced);
  expectBool(x##expandable);
};


let expectSortOder = expectEnum([|SortOrder.ascend, SortOrder.descend|]);

let expectSorterResult = sr => {
  expectObject(sr##column);
  expectSortOder(sr##order);
  expectString(sr##field);
  expectString(sr##columnKey);
};


let expectNullSortOrder = x => {
  switch (x->Js.Null.toOption) {
  | None => ()
  | Some(x) => expectSortOder(x)
  };
};

let expectPaginationConfig = (c: Pagination.Config.make) => {
  expectMaybeInt(c->Pagination.Config.currentGet);
  expectMaybeInt(c->Pagination.Config.pageSizeGet);
};

[@react.component]
let make = () => {
  let dataSource = [||];
  for (i in 0 to 25) {
    dataSource
    |> Js.Array.push({
         "key": i->string_of_int,
         "name": "Name " ++ i->string_of_int,
         "age": 30 + i,
         "address": (10 + i)->string_of_int ++ " Downing Street",
       });
  };
  // let dataSource = [|
  //   {"key": "1", "name": "Mike", "age": 32, "address": "10 Downing Street"},
  //   {"key": "2", "name": "John", "age": 42, "address": "20 Downing Street"},
  // |];

  let columns = [|
    Column.make(
      ~filterDropdown=props => string("filter"),
      ~onCell=
        (u, i) => {
          expectUser(u);
          expectInt(i);
          {
            "onMouseEnter": _ => {
              Js.log("cell enter");
            },
          };
        },
      ~onFilterDropdownVisibleChange=x => expectBool(x),
      ~onHeaderCell=
        x =>
          {
            "onMouseEnter": _ => {
              Js.log("header cell enter");
            },
          },
      ~title=
        x => {
          expectNullSortOrder(x##sortOrder);
          expectObject(x##filters);
          // TODO better filters test
          string("Name");
        },
      // ~dataIndex="name",
      ~key="name",
      ~render=
        (x, record, index) => {
          expectUser(x);
          expectUser(record);
          expectInt(index);
          <>
            <p> {string(record##name ++ "!")}</p>
          </>
        },
      (),
    ),
    Column.make(
      ~title=_ => string("Age"),
      ~dataIndex="age",
      ~key="age",
      ~filterDropdown=
        props => {
          Js.log2("filterDropdown", props);
          string("filter");
        },
      ~filterIcon=
        b => {
          expectBool(b);
          <Icon _type=Icon.Type.filter />;
        },
      ~sorter=
        Sorter.make((a, b, order) => {
          expectUser(a);
          expectUser(b);
          expectSortOder(order);
          let res =
            if (order == SortOrder.ascend) {
              a##age - b##age;
            } else {
              b##age - a##age;
            };
          res->float_of_int;
        }),
      (),
    ),
    Column.make(
      ~title=_ => string("Address"),
      ~dataIndex="address",
      ~key="address",
      ~filters=[|
        {"text": string("Filter 1"), "value": "f1", "children": [||]},
        {"text": string("Filter 2"), "value": "f2", "children": [||]},
      |],
      ~onFilter=
        (x, u) => {
          expectString(x);
          expectUser(u);
          false;
        },
      // ~fixed=`right,
      (),
    ),
  |];

  let rowSelection =
    RowSelection.make(
      ~selectWay=`onSelectMultiple,
      ~onChange={(keys, xs) => {
          expectStringArray(keys);
          expectUserArray(xs);
      }},
      ~_type=`checkbox,
        ~onSelect=
          (record, selected, selectedRows, e) => {
            [%debugger];

            expectUser(record);
            expectBool(selected);
            expectUserArray(selectedRows);
            expectDomEvent(e);
            {
              "onMouseEnter": _ => {
                Js.log("select enter");
              },
            };
            ()
          },
          ~onSelectInvert={keys => {
            [%debugger];
             failwith("NOT TESTED")
            expectStringArray(keys);
          }},
        ~onSelectAll={(selected, ~selectedRows, ~changeRows) => {
          expectBool(selected);
          expectUserArray(selectedRows);
          expectUserArray(changeRows);
        }},
      ~onSelectMultiple=
        (selected, ~selectedRows, ~changeRows) => {
          [%debugger];
          failwith("NOT TESTED");
          expectBool(selected);
          expectUserArray(selectedRows);
          expectUserArray(changeRows);
        },
      ~getCheckboxProps=
        record => {
          expectUser(record);
          {"onMouseEnter": () => {
            Js.log("checkbox enter")
          }};
        },
      (),
    );

  let expandIcon = props => {
    expectExpandIconPropsOfUser(props);
    <Icon _type=Icon.Type.up />;
  };

  let footer = props => {
    expectUserArray(props);

    string("TABLE FOOTER");
  };

  let rowClassName = (record, i) => {
    expectUser(record);
    expectInt(i);
    "custom-row-classname";
  };

  let rowKey = (record, i) => {
    expectUser(record);
    expectInt(i);
    (i + 30)->string_of_int;
  };

  let expandedRowRender = (record, index, indent, expanded) => {
    expectUser(record);
    expectInt(index);
    expectInt(indent);
    expectBool(expanded);
    string("Address: " ++ record##address);
  };

  let defaultExpandedRowKeys = [|"1"|];

  let title = arr => {
    expectUserArray(arr);
    let first =
      switch (arr->Array.get(0)) {
      | None => "none"
      | Some(u) => u##name
      };
    string("A TITLE: first is " ++ first);
  };

  let onRow = (u, i) => {
    expectUser(u);
    expectInt(i);

    {
      "onDoubleClick": () => {
        %raw
        {| alert("onDoubleClick") |};
      },
    };
  };

  let pConfig = Pagination.Config.make(
      ~onChange=
        (~page, ~pageSize) => {
          expectInt(page);
          expectMaybeInt(pageSize);
        },
      ~itemRender=
        (i, t, el) => {
          expectInt(i);
          // TODO enum
          expectString(t);
          expectElement(el);

          string(i->string_of_int);
        },
      ~showTotal=
        (~total, ~range) => {
          expectInt(total);
          let (a, b) = range;
          expectInt(a);
          expectInt(b);
          string(
            "Total: "
            ++ total->string_of_int
            ++ ", Current: "
            ++ a->string_of_int
            ++ "-"
            ++ b->string_of_int,
          );
        },
      (),
    );
  let pagination = Pagination.make(pConfig);
    

  let onHeaderRow = (c, i) => {
    expectArray(c);
    expectInt(i);
    {
      "onMouseEnter": _ => {
        Js.log("row header enter");
      },
    };
  };

  <>
    <h1 id="table-example"> {string("Table Example")} </h1>
    <Table
    onExpandedRowsChange={x => {
      expectStringArray(x);
    }}
    expandRowByClick=true
    defaultExpandAllRows=false
      onChange={(cfg,b,c,d) => {

        expectPaginationConfig(cfg);
        // TODO better b
        expectObject(b);
        expectSorterResult(c);
        expectUserArray(d##currentDataSource);
      }}
      dataSource
      columns
      defaultExpandedRowKeys
      onHeaderRow
      // pagination
      onRow
      footer
      title
      rowClassName
      // rowKey
      //  expandIcon
      childrenColumnName="name2"
      rowSelection
      expandedRowRender
    />
  </>;
};