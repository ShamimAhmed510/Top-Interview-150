//// 6.3 Useful Everyday Methods 

// const nums = [10 , 20, 30 , 40];
// console.log(nums.includes(20));
// console.log(nums.indexOf(10));
// console.log(nums.slice(0,3));
// console.log(nums.join(" + "));
// const merged = [...nums , 100];
// console.log(merged);


//map — transform every element
// const prices = [10, 20, 30, 40, 50];
// const withvat = prices.map((u) => u+5);
// console.log(prices);
// console.log(withvat);
// const b = withvat.map((u) => u-10);
// console.log(b);




//filter — keep only elements that pass a test
// const prices = [10, 20, 30, 40, 50];
// const b = prices.filter((u) => u <= 20);
// console.log(b);



//// reduce — boil an array down to one value 
// const bill = [120, 80, 300];
// const sm = bill.reduce((sum , u) => sum+u, 0);
// console.log(sum);



 /////  Searching and Sorting 
//  const students = [
//     { name: "shamim" , cg: 3.7},
//     { name: "Tarek" , cg: 3.2},
//      { name: "Abdullah" , cg: 3.8 },
//     { name: "Sakib" , cg: 4.00 },
//     { name: "Mijan" , cg: 3.9},

//  ];

//  const topper = students.find((s) => s.cg >= 3.8);

//  console.log(topper)

//  const anyFailing = students.some((s) => s.cg < 2.0);
//  console.log(anyFailing);

//  const allPassing = students.every((s) => s.cg >= 2.0);
//  console.log(allPassing);


////// sort: for numbers ALWAYS provide a compare function
//  const nums = [2, 5 , 3 , 4, 1];
//  nums.sort((a,b) => a - b );
//  console.log(nums)
//  nums.sort((a,b) => b - a );
//  console.log(nums)





// /*  Note: Without a compare function, sort() converts values to strings, so [30, 4, 200] becomes [200, 30, 4].
// This bug appears in real interviews */ 

//  const values = [30, 4, 200];

//  values.sort((a,b) => b - a);
//  const st = values.toString();
//  console.log(st)

//     //const stt = String(values);
//     // console.log(stt)

 





// // 6.6 Chaining Methods 

// const cart = [
//     { item: "book" , price: 450, qty: 2},
//     { item: "pen" , price: 15, qty: 10},
//     { item: "laptop" , price: 55000, qty: 1},

// ];

// const afforDableTotal = cart
// .filter((p) => p.price < 1000)
// .map((p) => p.price * p.qty)
// .reduce((sum ,v) => sum+v ,0 );

// console.log(afforDableTotal);


// //// 2. Use map to convert an array of taka amounts into strings like '450 BDT'.

// const arr = [150 , 250, 350, 450,550];
// const str = arr.map((p) => `${p} BDT`);
// console.log(str);



//  // 3. Use filter to keep only names longer than 4 characters from an array of names.
// const name = ["shamim","tal","Abir" , "Sakiib"];
// const names = name.filter((n) => n.length > 4);
// console.log(names);




// 4. Use reduce to count how many numbers in an array are even.

// const v = [ 1,2,3,4,5,6,7,8,9];
// const even = v.reduce((count , item) => {
//     return item%2 == 0 ? count+1 : count;
// },0);

// console.log(even);




/* 5. Combine filter + map: from an array of students with cgpa, produce an array of names of students
with cgpa ≥ 3.5 */

const students = [
    { name: "Shamim", cg: 3.5},
    { name: "tarek", cg: 3.8},
    { name: "sakib", cg: 3.0},
    { name: "mijan", cg: 3.4},

];

const std = students
.filter((p) => p.cg >= 3.5)
.map((p) => `name : ${p.name} cgpa : ${p.cg}`);

console.log(std);


































