open React;
open Antd;
open Upload;
open Expect_;
open Js.Promise;


// let expectUploadFile = (f: uploadFile) => {
//   expectString(f##uid);
//   expectString(f##name);
//   expectMaybeString(f##fileName);
//   expectMaybeNumber(f##lastModified);
//   expectMaybeDate(f##lastModifiedDate);
//   expectMaybeString(f##url);
//   expectString(f##status);
//   expectMaybeNumber(f##percent);
//   expectMaybeString(f##thumbUrl);
//   // abstract skipped
//   expectString(f##_type);
// };

let expectUploadFile = (f: File.make) => {
  open File;
  expectString(f->uidGet);
  expectString(f->nameGet);
  expectMaybeString(f->fileNameGet);
  expectMaybeNumber(f->lastModifiedGet);
  expectMaybeDate(f->lastModifiedDateGet);
  expectMaybeString(f->urlGet);
  expectMaybeString(f->statusGet);
  expectMaybeNumber(f->percentGet);
  expectMaybeString(f->thumbUrlGet);
  // abstract skipped
  expectString(f->type_Get);
};


let expectUploadFileArray = expectArrayOf(expectUploadFile);


let expectRcFile = (f: RcFile.t) => {
 expectToEqual(f->isFile, true);
};

let expectRcFileArray = expectArrayOf(expectRcFile);

[@react.component]
let make = () => {
  <>
    <h1 id="upload-example"> {string("Upload Example")} </h1>
    <Upload
      name="file"
      data={f => {
        expectUploadFile(f);
        [%raw "{}"]
      }}
      beforeUpload={(f, fs) => {
        expectRcFile(f);
        expectRcFileArray(fs);
        BeforeUpload.bool(true);
        // let p = Js.Promise.make((~resolve, ~reject) => {
        //   Js.Global.setTimeout(() => {
        //       resolve(. false);
        //   }, 3000) |> ignore;
        // }) ;
        // BeforeUpload.promise(p);
      }}
      // _type=`select
      // action={Action.string(
      //   "https://www.mocky.io/v2/5cc8019d300000980a055e76",
      // )}
      action=Action.make(f => {
        expectUploadFile(f);
        resolve("https://www.mocky.io/v2/5cc8019d300000980a055e76")
      })
      defaultFileList=[|
        File.make(
          ~name="file1",
          ~type_="sometype",
          ~uid="fileuid",
          ~size=322.0,
          ~status=Status.done_,
          ()
        )
      |]
      onPreview={f => {
        expectUploadFile(f);
      }}
      onRemove={f => {
        expectUploadFile(f);
        true
      }}
      showUploadList={ShowUploadList.make(
        ~showRemoveIcon=true,
        ()
      )}
      listType=`pictureCard
      multiple=true
      onChange={info => {
        open File
        expectUploadFile(info##file);
        expectUploadFileArray(info##fileList);

        switch (info##event) {
          | None => ()
          | Some(e) =>
            expectNumber(e##percent);
        }

        // Js.log2("onChange", info);
        if (info##file->statusGet != Some(Status.uploading)) {
          Js.log2(info##file, info##fileList);
        };
        if (info##file->statusGet == Some(Status.done_)) {
          Message.success(
            string(info##file->nameGet ++ " file uploaded successfully"),
          )
          |> ignore;
        } else if (info##file->statusGet == Some(Status.error)) {
          Message.error(string(info##file->nameGet ++ " file upload failed."))
          |> ignore;
        };
      }}
      headers={Js.Dict.fromList([("authorization", "authorization-text")])}>
      <Button>
        <Icon _type=Icon.Type.upload />
        {string("Click to Upload")}
      </Button>
    </Upload>
  </>;
};