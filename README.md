# bs-antd

Ant Design bindings for BuckleScript

## Install

```
npm i reason-react@^0.7.0
npm i bs-moment@^0.4.4
npm i @zpnester/bs-antd
```

### Add dependencies in bsconfig.json
```
"bs-dependencies": [
  "reason-react",
  "bs-moment",
  "@zpnester/bs-antd"
]
```

### Add Antd styles

With CSS

```reason
%bs.raw
{| require("antd/dist/antd.css"); |};
```

Or with LESS

```reason
%bs.raw
{| require("antd/dist/antd.less"); |};
```


## Limitations

### Form

`Form.create` (built-in validation) is not implemented


### Select

`mode` property is required

`labelInValue` property is required to be `LabelInValue.true_`

### AutoComplete

`labelInValue` property is required to be `LabelInValue.true_`

### Collapse

`accordion` property is required

### Slider
`range` property is required

### Tree

`checkStrictly` property is required

### TreeSelect

`multiple` property is required

`labelInValue` property is required to be `LabelInValue.true_`

### Transfer

`render`, `dataSource` properties are required

### Breadcrumb

`itemRender`, `routes` properties are available only in submodule `Breadcrumb.Routes`

`itemRender`, `routes`, `params` property are required in `Breadcrumb.Routes`

### Checkbox, Radio, Radio.Button

`value` property is required to ensure types in a Group

### Statistic

`value` property can only be a string

### Statistic.Countdown

`value` property can only be a MomentRe.Moment.t

### Mention

Suggestions cannot be created with plain strings, only with a dedicated function

`data` property available in Make functor


## Implementation Details

### HTML props

Some components (Col, Row, Form, Input, etc.) have bloated sources because they extend HTML props (copied from [https://github.com/reasonml/reason-react/blob/master/src/ReactDOMRe.re](https://github.com/reasonml/reason-react/blob/master/src/ReactDOMRe.re))

It does not have impact on generated JavaScript or runtime performance

Note that you should never alias or curry any ReasonReact `makeProps`, if you do - it affects runtime performance and generates lots of JavaScript

HTML props require `[@bs.deriving abstract]` instead of `[@react.component]` or `[@bs.obj]`

