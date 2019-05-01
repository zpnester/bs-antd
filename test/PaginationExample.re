

open React;
open Antd;
open Pagination;
open Expect_;

[@react.component]
let make = () => {


    <>  
        <h1 id="pagination-example">{string("Pagination Example")}</h1>

        <Pagination defaultCurrent=1 total=50
        onChange={(~page, ~pageSize) => {
            Js.log3("onChange", page, pageSize);
            expectInt(page);
            expectInt(pageSize);
        }}
        itemRender={(page, t, el) => {
            Js.log4("itemRender", page, t, el);
            expectString(t);
            expectInt(page);
            expectElement(el);
            
            switch (t) {
                | p when p == ItemRenderType.page =>  string(page->string_of_int)
                | prev when prev |> Js.String.indexOf("prev") != -1 => string("<<")
                | next when next |> Js.String.indexOf("next") != -1 => string(">>")
                | _ => failwith("unreachable")
            }
        }}
        />

    </>
};