# bs-antd

Ant Design bindings for BuckleScript

Work In Progress

## Install

```
npm i reason-react
npm i bs-moment
npm i git+https://git@github.com/zpnester/bs-antd.git
```

## Notes
Input, Input.TextArea, InputSearch includes `ReactDOMRe.props` properties excluding SVG

Polymorphic variants are used for string enums when `[@bs.obj]` or `[@react.component` is used for makeProps

Separate modules are used for string enums when `[@bs.deriving abstract]` is used fro makeProps

`[@bs.deriving abstract]` is required to rename properties when DOM properties are copy pasted

bsconfig.json
```json
"bs-dev-dependencies": [
  "reason-react",
  "bs-moment",
  "@zpnester/bs-antd"
]
```

