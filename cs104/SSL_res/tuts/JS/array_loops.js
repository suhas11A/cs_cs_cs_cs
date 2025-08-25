// Arrow Functions
const sum = (a, b) => {
    return a + b;
}
console.log(sum(2, 3));

// Array Methods

// forEach
// syntax:: array.forEach(function(currentValue, index, arr), thisValue)

// Example
let arr = [1, 2, 3, 4, 5];
arr.forEach((element, index) => {
    console.log(`Element at index ${index} is ${element}`);
}
);
// Output
// Element at index 0 is 1
// Element at index 1 is 2
// Element at index 2 is 3
// Element at index 3 is 4
// Element at index 4 is 5

// map
// syntax:: array.map(function(currentValue, index, arr), thisValue)

// Example
let squareArr = arr.map((element) => {
    return element * element;
}
);
console.log(squareArr);

// Output
// [1, 4, 9, 16, 25]

// filter
// syntax:: array.filter(function(currentValue, index, arr), thisValue)

// Example
let evenArr = arr.filter((element) => {
    return element % 2 === 0;
}
);
console.log(evenArr);

// Output
// [2, 4]


//reduce
// syntax:: array.reduce(function(total, currentValue, currentIndex, arr), initialValue)

// Example
let sumArr = arr.reduce((total, element) => {
    return total + element;
}
);
console.log(sumArr);

// Output
// 15