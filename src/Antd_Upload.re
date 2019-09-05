open React;

type file;
type response;
type error;
type linkProps;

module Status = {
  type t = string;
  [@bs.inline]
  let error = "error";
  [@bs.inline]
  let success = "success";
  [@bs.inline]
  let done_ = "done";
  [@bs.inline]
  let uploading = "uploading";
  [@bs.inline]
  let removed = "removed";
};

module File = {
  [@bs.deriving abstract]
  type make = {
    uid: string,
    size: float,
    name: string,
    [@bs.optional]
    fileName: string,
    [@bs.optional]
    lastModified: float,
    [@bs.optional]
    lastModifiedDate: Js.Date.t,
    [@bs.optional]
    url: string,
    [@bs.optional]
    status: Status.t,
    [@bs.optional]
    percent: float,
    [@bs.optional]
    thumbUrl: string,
    [@bs.optional]
    originFileObj: file,
    [@bs.optional]
    response,
    [@bs.optional]
    error,
    [@bs.optional]
    linkProps,
    // required
    [@bs.as "type"]
    type_: string,
  };
};

module Action = {
  type t;

  external string: string => t = "%identity";
  external make: (File.make => Js.Promise.t(string)) => t = "%identity";
};

module RcFile = {
  type t = file; // RcFile extends file

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
  external make: (~showRemoveIcon: bool=?, ~showPreviewIcon: bool=?, unit) => t =
    "";
};

module BeforeUpload = {
  type t;

  external bool: bool => t = "%identity";
  external promise: Js.Promise.t(unit) => t = "%identity"; // unit, not bool
};

[@react.component] [@bs.module "antd/es/upload"]
external make:
  (
    ~_type: [@bs.string] [ | `drag | `select]=?,
    ~name: string=?,
    ~defaultFileList: array(File.make)=?,
    ~fileList: array(File.make)=?,
    ~action: Action.t=?,
    ~directory: bool=?,
    ~data: File.make => Js.t({..})=?,
    ~headers: Js.Dict.t(string)=?,
    ~showUploadList: ShowUploadList.t=?,
    ~multiple: bool=?,
    ~accept: string=?,
    ~beforeUpload: (RcFile.t, array(RcFile.t)) => BeforeUpload.t=?,
    ~onChange: {
                 .
                 "file": File.make,
                 "fileList": array(File.make),
                 "event": option({. "percent": float}),
               } =>
               unit
                 =?,
    ~listType: [@bs.string] [
                 | `text
                 | `picture
                 | [@bs.as "picture-card"] `pictureCard
               ]
                 =?,
    ~className: string=?,
    ~onPreview: File.make => unit=?,
    ~onRemove: File.make => bool=?,
    ~supportServerRender: bool=?,
    ~style: ReactDOMRe.Style.t=?,
    ~disabled: bool=?,
    ~prefixCls: string=?,
    ~customRequest: customRequest=?,
    ~withCredentials: bool=?,
    ~openFileDialogOnClick: bool=?,
    ~locale: Js.t({..})=?, // TODO
    ~id: string=?,
    ~children: element=?,
    unit
  ) =>
  element =
  "default";