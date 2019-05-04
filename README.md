# bs-antd

Ant Design bindings for BuckleScript

Work In Progress

## Install

```
npm i antd@3.16.6
npm i reason-react
npm i bs-moment
npm i git+https://git@github.com/zpnester/bs-antd.git
```

bsconfig.json
```json
"bs-dependencies": [
  "reason-react",
  "bs-moment",
  "@zpnester/bs-antd"
]
```

Styles must be added manually

```reason
%bs.raw
{| require("antd/dist/antd.css");  |};
```

Or with LESS

```reason
%bs.raw
{| require("antd/dist/antd.less");  |};
```

Appropriate CSS/LESS setup is required (see `webpack.config.js` or `next.config.js` for CSS example)


`babel-plugin-import` recommended in [https://ant.design/docs/react/getting-started](https://ant.design/docs/react/getting-started) is not supported


## Usage

### ES6

These bindings should work with both ES6 and CommonJS although have been tested primarily with CommonJS

### Next.js

These bindings work with Next.js although CommonJS is required

[BuckleScript configuration](https://bucklescript.github.io/docs/en/build-configuration.html#package-specs)

To avoid certain Next.js issues it is recommended to to add minimal `.babel.rc` or `babel.config.js` if you don't have one

### Change Antd version

Changing Antd version is generally not recommended as imports sometimes break

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

## Implementation Details

### HTML props

Some components (Col, Row, Form, Input, etc.) have bloated sources because they extend HTML props (copied from [https://github.com/reasonml/reason-react/blob/master/src/ReactDOMRe.re](https://github.com/reasonml/reason-react/blob/master/src/ReactDOMRe.re))


### String enums

Polymorphic variants are used for string enums when `[@bs.obj]` or `[@react.component]` is used for makeProps

Separate modules are used for string enums when `[@bs.deriving abstract]` is used for makeProps

`[@bs.deriving abstract]` is required to rename properties when DOM properties are copy-pasted


