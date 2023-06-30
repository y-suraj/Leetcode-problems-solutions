# Javascript Leetcode problems

## [2619. Array Prototype Last](https://leetcode.com/problems/array-prototype-last/description/)
```js
Array.prototype.last = function() {
    if(this.length === 0) {
        return -1;
    } else {
        return this[this.length - 1];
    }
};

/**
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 */
```

## [2620. Counter](https://leetcode.com/problems/counter/description/)
```js
/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    return function() {
        return n++;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */
```
