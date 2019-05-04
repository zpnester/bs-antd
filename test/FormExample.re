open Antd;
open Form;
open React;

[@react.component]
let make = () => {
  let (username, setUsername) = useState(() => "");
  let (password, setPassword) = useState(() => "");
  let (sub, setSub) = useState(() => false);

  let (usernameHelp, usernameFeedback, usernameStatus) =
    if (sub && username->Js.String.length <= 3) {
      (Some(string("Username is too short")), true, `error);
    } else {
      (None, false, `success);
    };

  <>
    <h1 id="form-example"> {string("Form Example")} </h1>
    <Form
      onSubmit={e => {
        e->ReactEvent.Form.preventDefault;
        setSub(_ => true);
        // Js.log("submit");
      }}>
      <Form.Item
        hasFeedback=usernameFeedback
        help=?usernameHelp
        validateStatus=usernameStatus>
        <Input
          value=username
          onChange={e => {
            let value = e->ReactEvent.Form.target##value;

            setUsername(_ => value);
          }}
        />
      </Form.Item>
      <Form.Item>
        <Input
          value=password
          type_="password"
          onChange={e => {
            let value = e->ReactEvent.Form.target##value;
            setPassword(_ => value);
          }}
        />
      </Form.Item>
      <Button htmlType="submit"> {string("Submit")} </Button>
    </Form>
  </>;
};
