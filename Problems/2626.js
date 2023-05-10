/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */

var reduce = function(nums, fn, init) {
    let acc = init
    for(i in nums) acc = fn(acc, nums[i]);
    return acc;
};
