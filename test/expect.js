    
function expectToEqual(a, b) {
    let expect = require("expect");
    expect(a).toEqual(b);
}

function isArray(arr) {
    return arr instanceof Array;
}

function isElement(x) {
    return typeof(x) == "string" || typeof(x) == "object";
}

module.exports.expectToEqual = expectToEqual;
module.exports.isArray = isArray;
module.exports.isElement = isElement;