open React;
open Antd;

[@react.component]
let make = () => {
  <>
    <h1>{string("Anchor Example")}</h1>
    <Anchor>
      <Anchor.Link href="#alert-example" title={string("Alert Example")} />
      // <Anchor.Link href="#avatar-example" title={string("Avatar Example")} />
      // <Anchor.Link href="#breadcrumb-example" title={string("Breadcrumb Example")} />
      // <Anchor.Link href="#affix-example" title={string("Affix Example")} />
      <Anchor.Link href="#calendar-example" title={string("Calendar Example")} />
      // <Anchor.Link href="#carousel-example" title={string("Carousel Example")} />
      // <Anchor.Link href="#cascader-example" title={string("Cascader Example")} />
      // <Anchor.Link href="#checkbox-example" title={string("Checkbox Example")} />
      <Anchor.Link href="#collapse-example" title={string("Collapse Example")} />
      // <Anchor.Link href="#comment-example" title={string("Comment Example")} />
      // <Anchor.Link href="#datepicker-example" title={string("DatePicker Example")} />
      // <Anchor.Link href="#timepicker-example" title={string("TimePicker Example")} />
        
    </Anchor>
  </>;
};
