# bs-antd

Ant Design bindings for BuckleScript

## Install

BuckleScript 5 or newer is required

```
npm i antd@3.16.6
npm i reason-react@^0.7.0
npm i bs-moment@^0.4.4
npm i git+https://git@github.com/zpnester/bs-antd.git
```

### Add dependencies to bsconfig.json
```
"bs-dependencies": [
  "reason-react",
  "bs-moment",
  "@zpnester/bs-antd"
]
```

### [Configure JSX](https://reasonml.github.io/reason-react/docs/en/jsx#migrating-from-version-2-to-version-3)

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

Appropriate CSS/LESS setup is required (see `webpack.config.js` or `next.config.js` for CSS example)


`babel-plugin-import` recommended in [https://ant.design/docs/react/getting-started](https://ant.design/docs/react/getting-started) is not supported


## Usage

### ES6

These bindings should work with both ES6 and CommonJS although have been tested primarily with CommonJS

### Next.js

CommonJS is required for Next.js

[BuckleScript configuration](https://bucklescript.github.io/docs/en/build-configuration.html#package-specs)

To avoid certain Next.js issues it is recommended to to add minimal `.babel.rc` or `babel.config.js` if you don't have one

### Change Antd version

Changing Antd version is possible but not recommended

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

### String enums

Polymorphic variants are used when `[@bs.obj]` or `[@react.component]` is used for makeProps

Local modules with Identity External are used when `[@bs.deriving abstract]` is used for makeProps



