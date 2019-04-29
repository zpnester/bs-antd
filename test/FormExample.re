
open Antd;
open Form;
open React


 let normalLoginForm = props => {
     open Decorated;
      let form = props##form;
      let getFieldDecorator = form->getFieldDecorator;
    let usernameOpts =  GetFieldDecoratorOptions.make(
       ~rules= [| 
        //    ValidationRule.make(~required=true, ~message=string("Please input your username!"), ())
        |]
    , ());
    let usernameInput = <Input placeholder="Username" />;

    let passwordOpts = GetFieldDecoratorOptions.make(~rules=[|
      ValidationRule.make(~required=true, ~message=string("Please input your Password!"), ())
    |], ());

    // let usernameInput = <Input 
    // prefix={<Icon type=Icon.Type.lock style={ReactDOMRe.Style.make(~color="rgba(0,0,0,.25)", ())}/>}
    //  type="password" placeholder="Password" />;
    let passwordInput = <Input placeholder="Password" />;


    let rememberOpts = GetFieldDecoratorOptions.make(
        ~valuePropName="checked",
        ~initialValue=true,
        ()
    );
    let rememberCheck = <Checkbox>{string("Remember me")}</Checkbox>;

    <Form onSubmit={e => {
        Js.log("submit");
       e->ReactEvent.Form.preventDefault;

       form->validateFields1__((es, vs) => {
          Js.log3("validateFields", es, vs);
       });
    }} 

    >
        <Form.Item>
           {getFieldDecorator("userName", usernameOpts, usernameInput)}
        </Form.Item>

       <Form.Item>
          {getFieldDecorator( "password", passwordOpts, passwordInput)}
       </Form.Item>
         <Form.Item>
           {getFieldDecorator("remember", rememberOpts, rememberCheck)}
        </Form.Item>


      <button type_="submit">{string("Submit")}</button>
    </Form>
  }; 

module WrappedNormalLoginForm   = {
  

  let makeProps = Form.makeProps;
  let make =Form.create(CreateOptions.make(), normalLoginForm);

};


[@react.component]
let make = () => {
  
  <>
    <h1 id="form-example">{string("Form Example")}</h1>
    // <Form />
    <WrappedNormalLoginForm  />
  </>
};
