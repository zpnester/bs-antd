
open React;
open Antd;
open Carousel;

let getCarExn = r => {
    r->React.Ref.current->Js.Nullable.toOption->Option.getExn
};

[@react.component]
let make = () => {

    let car = useRef(Js.Nullable.undefined);

    <>
        <h1 id="carousel-example">{string("Carousel Example")}</h1>
        <button onClick={_ => {
            car->getCarExn->next
        }}>{string("Next")}</button>

        <button onClick={_ => {
            car->getCarExn->prev
        }}>{string("Prev")}</button>

        <button onClick={_ => {
            car->getCarExn->goTo(2, false)
        }}>{string("Go to 2")}</button>

        <Carousel ref=car autoplay=false>
            <h3>{string("One")}</h3>
            <h3>{string("Two")}</h3>
            <h3>{string("Three")}</h3>
            <h3>{string("Four")}</h3>
        </Carousel>
    </>
};