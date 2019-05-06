
open React;
open Antd;
open List;
open Expect_;


type record = {
    title: string,
    key: string
};

let expectRecord = r => {
    expectString(r.title);
    expectString(r.key);
};

[@react.component]
let make = () => {

    let data =  [|
  "Racing car sprays burning fuel into crowd.",
  "Japanese princess to wed commoner.",
  "Australian walks 100km after outback crash.",
  "Man charged over missing wedding girl.",
  "Los Angeles battles huge wildfires.",
|];

let data2 = [|
    {
        key: "a",
        title: "Racing car sprays burning fuel into crowd."
    },
    {
        key: "b",
        title: "Japanese princess to wed commoner."
    },
|];

    let pagination = Pagination.make(
        Pagination.Config.make(
            ~position=Pagination.Position.top, 
            ~size="small",
            ~showSizeChanger=true,
            ~showTotal={(~total, ~range) => {
                expectInt(total);
                expectInt(fst(range))
                expectInt(snd(range))
                string("Total: " ++ total->string_of_int)
            }},
            ()
        )
    );   

    <>
        <h1 id="list-example">{string("List Example")}</h1>
        
        <List
        pagination
        rowKey={data => {
            expectRecord(data);
            data.key
        }}
      header={<div>{string("Header")}</div>}
      footer={<div>{string("Footer")}</div>}
      bordered=true
      dataSource={data2}
      renderItem={(item, i) => {
          expectRecord(item);
          expectInt(i);
       
          <List.Item
          >
            <Typography.Text mark=true>{string("[ITEM]")}</Typography.Text> 
            {string(item.title)}
          </List.Item>
          
    }}
    
    />

    <h2>{string("Meta")}</h2>
    <List
    itemLayout=`horizontal
    dataSource={data}
    renderItem={(item, i) => {
      <List.Item title="DOM title"
        
      >
        <List.Item.Meta key={i->string_of_int   }
          avatar={<Avatar src="https://zos.alipayobjects.com/rmsportal/ODTLcjxAfvqbxHnVXCYX.png" />}
          title={<a href="https://ant.design">{string(item)}</a>}
          description=string(
              "Ant Design, a design language for background applications, is refined by Ant UED Team")
        />
      </List.Item>
    }}
  />
    <h2>{string("Grid")}</h2>

  <List
    grid={
        Grid.make(~gutter=16.0, ~column=4, ()) }
    dataSource={data}
    
    renderItem={(item, i) => {
      <List.Item>
        <Card key={i->string_of_int} title={string(item)}>{string("Card content")}</Card>
      </List.Item>
    }}
  />

    <List 
        locale={"emptyText": <h3>{string("It's lonely here")}</h3>}
    dataSource=[||] renderItem={(_, _) => null}>

    </List>
    </>
};