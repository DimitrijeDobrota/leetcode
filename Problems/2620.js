/**
 * @param {number} n
 * @return {Function} counter
 */

var createCounter = function(n) {
    return function() {
        return n++;
    };
};

var createCounter = function(n) {
    return () => n++;
};

var createCounter = (n) => () => n++;
