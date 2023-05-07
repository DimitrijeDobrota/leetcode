/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */

var createCounter = function(init) {
  var crnt = init;
  return {
    increment: () => ++crnt,
    decrement: () => --crnt,
    reset: () => crnt = init,
  }
};

var createCounter = function(init) {
  let currentCount = init;
  return new Proxy({}, {
    get: (target, key) => {
      switch(key) {
        case "increment":
          return () => ++currentCount;
        case "decrement":
          return () => --currentCount;
        case "reset":
          return () => (currentCount = init);
        default:
          throw Error("Unexpected Method")
      }
    },
  });
};

