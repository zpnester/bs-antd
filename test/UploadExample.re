open React;
open Antd;
open Upload;
open Expect_;


[@react.component]
let make = () => {

    <>
        <h1 id="upload-example">{string("Upload Example")}</h1>
        
        <Upload
            name="file"
            action=Action.string("https://www.mocky.io/v2/5cc8019d300000980a055e76")
            onChange={info => {
                expectString(info##file##status);
                expectString(info##file##name);
                Js.log2("onChange", info);
                if (info##file##status != "uploading") {
                    Js.log2(info##file, info##fileList);
                }
                if (info##file##status == "done") {
                    Message.success(string(info##file##name ++ " file uploaded successfully")) |> ignore;
                } else if (info##file##status == "error") {
                    Message.error(
                        string(info##file##name ++ " file upload failed.")) |> ignore;
                }
            }}
            headers={Js.Dict.fromList([
                ("authorization","authorization-text") 
            ])}
            >
            <Button>
                <Icon _type=Icon.Type.upload /> {string("Click to Upload")}
            </Button>
        </Upload>
    </>
};