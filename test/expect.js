    
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

function isInt(x) {
    return Number.isInteger(x);
}

function isNull(x) {
    return x === null;
}

function hasLen(x, len) {
    return x.length === len;
}


module.exports.expectToEqual = expectToEqual;
module.exports.isArray = isArray;
module.exports.isElement = isElement;
module.exports.isInt = isInt;
module.exports.isNull = isNull;
module.exports.hasLen = hasLen;
