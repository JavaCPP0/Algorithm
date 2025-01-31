// function isPrime(num) {

//   for(let i = 2; num > i; i++) {
//   if(num % i === 0) {
//     return false;
//    }
//   }
//  return num > 1;
// }
function isPrime (num) {
    if(!num || num === 1) return false;
    for (let i = 2; i <= Math.sqrt(num); i++) {
        if (num % i === 0) return false;
    }

    return num>1;
}

function solution(n, k) {
    let answer = 0;
    
    n=n.toString(k);
    
    const arr = n.split("0");
    
    arr.forEach((num)=>{
       if(isPrime(num)) answer++;
    });
    
    return answer;
}

