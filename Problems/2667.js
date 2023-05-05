var createHelloWorld = function() {
    return function(...args) {
        return "Hello World";
    }
};

var createHelloWorld = function() {
    return () => "Hello World";
};

var createHelloWorld = () => () => "Hello World";
