open Antd;
open React;

%bs.raw
{| require("antd/dist/antd.css");  |};

let app = <Example />;

ReactDOMRe.renderToElementWithId(app, "app");

Js.log("OK");
