/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */

var filter = function(arr, fn) {
    var j = 0;
    for(let i = 0; i < arr.length; i++)
      if(fn(arr[i], i)) arr[j++] = arr[i];
    while (arr.length > j) arr.pop();
    return arr;
};
