/**
 * @param {Function[]} functions
 * @return {Function}
 */
 
var compose = function(functions) {
  return (x) => {
    if (functions.length === 0) return x;

    for (const func of functions.reverse())
      x = func(x);

    return x;
  }
}
