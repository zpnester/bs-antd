open React;

type file;

type uploadFile = {
  .
  "uid": string,
  "size": float,
  "name": string,
  "fileName": option(string),
  "lastModified": option(float),
  "lastModifiedDate": option(Js.Date.t),
  "url": option(string),
  "status": string, // TODO enum
  "percent": option(float), // TODO int?
  "thumbUrl": option(string),
  "originFileObj": option(file),
  // tODO
  // "response": 'todo,
  // "error": 'todo2,
  // "linkProps": 'todo3,
  "type": string,
};

module Action = {
  type t;

  external string: string => t = "%identity";
  external make: (uploadFile => Js.Promise.t(unit)) => t = "%identity";
};

module RcFile = {
  type t = file;

  [@bs.get] external uid: t => string = "uid";
  [@bs.get] external lastModifiedDate: t => Js.Date.t = "lastModifiedDate";
};

// https://github.com/react-component/upload#customrequest
// TODO
type customRequest;

module ShowUploadList = {
  type t;

  external bool: bool => t = "%identity";

  [@bs.obj]
  external make: (~showRemoveIcon: bool, ~showPreviewIcon: bool, unit) => t =
    "";
};

// TODO TS

[@react.component] [@bs.module]
external make:
  (
    ~accept: string=?,
    ~action: Action.t=?,
    ~directory: bool=?,
    ~beforeUpload: (RcFile.t, array(RcFile.t)) => Js.Promise.t(bool)=?, // TODO test
    ~customRequest: customRequest=?,
    ~data: uploadFile => 'todo=?,
    ~defaultFileList: array(uploadFile)=?,
    ~disabled: bool=?,
    ~fileList: array(uploadFile)=?, // tODO test
    ~headers: Js.Dict.t(string)=?,
    ~listType: [@bs.string] [
                 | `text
                 | `picture
                 | [@bs.as "picture-card"] `pictureCard
               ]
                 =?,
    ~multiple: bool=?,
    ~name: string=?,
    ~showUploadList: ShowUploadList.t=?,
    ~supportServerRender: bool=?,
    ~withCredentials: bool=?,
    ~openFileDialogOnClick: bool=?,
    ~onChange: {
                 .
                 "file": uploadFile,
                 "fileList": array(uploadFile),
                 "event": option({. "percent": float}),
               } =>
               unit
                 =?,
    ~onPreview: uploadFile => unit=?,
    ~onRemove: uploadFile => bool=?,
    ~children: element=?,
    unit
  ) =>
  element =
  "antd/lib/upload";