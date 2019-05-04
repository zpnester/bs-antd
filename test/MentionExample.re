open React;
open Antd;
open Mention;
open Expect_;

[@react.component]
let make = () => {

    // Js.log2("ContentState.fromString", ContentState.fromString("@afc163"));
    let defaultSuggestions = 
    [|"afc163", "benjycui", "yiminghe", "RaoHai", {js|中文|js}, {js|にほんご|js} |];

    let defaultSuggestions = defaultSuggestions->Array.map(Suggestion.string);

    <>  
        <h1 id="mention-example">{string("Mention Example")}</h1>
        <h1>{string("TODO SSR crash")}</h1>

        <Mention
            style={ReactDOMRe.Style.make(~width="100%", ())}
            onChange={contentState => {
                // Js.log3("onChange", contentState, contentState->ContentState.toString);
                // TODO
                ()
            }}
            defaultValue={ContentState.fromString("@afc163")}
            defaultSuggestions
            loading=true 
            multiLines=true
            key="asd"
            onSearchChange={(~value, ~trigger) => {
                expectString(value);
                expectString(trigger);
                // Js.log3("onSearchChange", value, trigger);
            }}
            onSelect={(~suggestion, ~data) => {
                expectString(suggestion);
                // expectString(data);
                // Js.log3("onSelect", suggestion, data);
            }}
        />

    </>
};