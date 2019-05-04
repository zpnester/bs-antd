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

These bindings work with both ES6 and CommonJS although have been tested primarily with CommonJS

## Next.js

These bindings work with Next.js although CommonJS is required

[BuckleScript configuration](https://bucklescript.github.io/docs/en/build-configuration.html#package-specs)

To avoid certain Next.js issues it is recommended to to add minimal `.babel.rc` or `babel.config.js` if you don't have one

### Change Antd version

Changing Antd version is generally not recommended as imports sometimes break

## Implementation Details

### Input

Input, Input.TextArea, InputSearch, Input.Password includes `ReactDOMRe.props` properties (except SVG)

### String enums

Polymorphic variants are used for string enums when `[@bs.obj]` or `[@react.component]` is used for makeProps

Separate modules are used for string enums when `[@bs.deriving abstract]` is used for makeProps

`[@bs.deriving abstract]` is required to rename properties when DOM properties are copy-pasted


