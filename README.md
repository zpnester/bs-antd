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

## Usage

Changing Antd version should be done with care, sometimes imports break

## Notes
Input, Input.TextArea, InputSearch, Input.Password includes `ReactDOMRe.props` properties excluding SVG

Polymorphic variants are used for string enums when `[@bs.obj]` or `[@react.component]` is used for makeProps

Separate modules are used for string enums when `[@bs.deriving abstract]` is used for makeProps

`[@bs.deriving abstract]` is required to rename properties when DOM properties are copy-pasted


