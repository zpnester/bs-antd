let getDocumentBody: unit => Dom.htmlElement = [%raw
  {|
function(unit) {
  return document.body
}
|}
];