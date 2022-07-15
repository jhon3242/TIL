
// 1
// let user = {};
// user.name = "Jhon";
// user.surname = "Smith";
// user.name = "Pete";
// delete user.name;


// 2
// function  isEmpty(Obj){
//     for (let key in Obj){
//         return false;
//     }
//     return true;
// }

// let schedule = {};

// alert( isEmpty(schedule) ); // true

// schedule["8:30"] = "get up";

// alert( isEmpty(schedule) ); // false



// 3
// let salaries = {
//     John: 100,
//     Ann: 160,
//     Pete: 130
// }

// let sum = 0;
// for (let key in salaries){
//     sum += salaries[key]
// }
// alert(sum); // 390




// 4
function multiplyNumeric(menu){
    for (let key in menu){
        if (typeof menu[key] == "number")
            menu[key] *= 2;
    }
}

// 함수 호출 전
let menu = {
    width: 200,
    height: 300,
    title: "My menu"
  };
  
  multiplyNumeric(menu);
  
//   // 함수 호출 후
//   menu = {
//     width: 400,
//     height: 600,
//     title: "My menu"
//   };