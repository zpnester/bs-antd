open Antd;
open Comment;
open React;

[@react.component]
let make = () => {
  <>
    <h1 id="comment-example"> {string("Comment  Example")} </h1>
    <Comment
      author={string("user1")}
      content={string("hello")}
      avatar={<Antd.Avatar icon=Antd.Icon.Type.user />}>
      <Comment
        author={string("user2")}
        content={string("hi")}
        avatar={<Antd.Avatar icon=Antd.Icon.Type.user />}>
        <Comment
          author={string("user3")}
          content={string("hey there")}
          avatar={<Antd.Avatar icon=Antd.Icon.Type.user />}
        />
      </Comment>
    </Comment>
  </>;
};