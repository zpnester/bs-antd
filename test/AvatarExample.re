
open Antd;
open Avatar;
open React;



[@react.component]
let make = () => {
    <>
    <h1 id="avatar-example">{string("Avatar example")}</h1>
        <Avatar size={Size.large} 
        src="https://zos.alipayobjects.com/rmsportal/ODTLcjxAfvqbxHnVXCYX.png" />
         <Avatar size={Size.large} icon=Icon.Type.user shape=`square />
    </>
}


