function solution(n) {
    let num  = n.toString(3);

  return parseInt(num.split("").reverse().join(""), 3);
}