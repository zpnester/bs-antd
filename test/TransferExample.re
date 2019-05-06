open React;
open Antd;
open Transfer;
open Expect_;

let expectLeftRight = expectEnum([|Direction.left, Direction.right|]);



type user = {
  .
  "key": string,
  "name": string,
  "title": string,
  "description": option(string),
  "disabled": bool,
  "age": int
};

let expectUser = (u: user) => {
  expectString(u##name);
  expectString(u##key);
  expectString(u##title);
  expectBool(u##disabled);
  expectMaybeString(u##description);
  expectInt(u##age);
};

let expectUserArray = expectArrayOf(expectUser);

let expectUserArrayOption = expectOptionOf(expectUserArray);

[@react.component]
let make = () => {


  let dataSource = [||];
  let (dataSource, _) = useState(() => [||]);
  

  let (targetKeys, setTargetKeys) = useState(() => {
    let targetKeysInit = [||];

    for (i in 0 to 3) {
    let name =  "User " ++ i->string_of_int;
    dataSource |> Js.Array.push({
      "name": name,
      "key": "u" ++ i->string_of_int,
      "title":  name ++ "!",
      "age": 20 + i,
      "description": None,
      "disabled": i mod 5 == 0
    }) |> ignore;

    if (i mod 3 == 0) {
        targetKeysInit |> Js.Array.push(name) |> ignore;
      }
    };
    targetKeysInit
  });


  <>
    <h1 id="transfer-example"> {string("Transfer Example")} </h1>
    <Transfer 
      onScroll={(dir, e) => {
        expectLeftRight(dir);
        expectSynEvent(e);
      }}
        render={x => {
          expectUser(x);
          string(x##title);
        }}
        locale = {
          "searchPlaceholder": "...",
        "itemUnit": "thing",
        "itemsUnit": "things",
        }
      targetKeys
      onChange={(~targetKeys, ~direction, ~moveKeys) => {
        Js.log4("onChange", targetKeys, direction, moveKeys);
        expectStringArray(targetKeys);
        expectStringArray(moveKeys);
        expectLeftRight(direction);

        if (direction == "right") {
          setTargetKeys(keys => {
            let result = keys->Array.copy;
            moveKeys->Array.forEach(moveKey => {
              result |> Js.Array.push(moveKey) |> ignore;
            })
            result
          });
        } else {
          setTargetKeys(keys => {
            keys->Array.keep(key => {
              moveKeys |> Js.Array.indexOf(key) == -1
            })
          })
        }
      }}
      // operations=[|">", "<", "@"|]
      showSearch=true
      onSearch={(dir, s) => {
        expectString(s);
        expectLeftRight(dir)
      }}
      rowKey={x => {
        expectUser(x);
        x##key
      }}
      filterOption={(s, x) => {
        expectString(s);
        expectUser(x);
        x##key |> Js.String.indexOf(s) >= 0 
      }}
      onSelectChange={(~sourceSelectedKeys, ~targetSelectedKeys) => {
          expectStringArray(sourceSelectedKeys);
          expectStringArray(targetSelectedKeys);
      }}
      footer={p => {
        expectObject(p);
        string("FOOTER")
      }}
      titles=[|"Title1", "Title2", "Title3"|]
      // selectedKeys=[|
      //   "u2", "u3"
      // |]
      dataSource  />
  </>;
};