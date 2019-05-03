    
function expectToEqual(a, b) {
    let expect = require("expect");
    expect(a).toEqual(b);
}

function isArray(arr) {
    return arr instanceof Array;
}

function isElement(x) {
    if (typeof(x) == "string") {
        return true;
    }
    if (typeof(x) == "object" && typeof(x.props) == "object") {
        return true;
    }
        return false;
    
}

function isInt(x) {
    return Number.isInteger(x);
}

function isNull(x) {
    return x === null;
}

function isUndefined(x) {
    return x === undefined;
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
module.exports.isUndefined = isUndefined;

