/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */

var map = function(arr, fn) {
    for(elem in arr) fn(elem);
    return arr;
};
