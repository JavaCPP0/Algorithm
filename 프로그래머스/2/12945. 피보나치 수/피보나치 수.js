// function pivo(n){
//     if(n === 0)return 0;
//     if(n === 1)return 1;
        
//     return pivo(n-1)+pivo(n-2);
// }


// function solution(n) {
//     var answer = 0;
    
//     answer = pivo(n)%1234567;
    
//     return answer;
// } 너무 오래걸림

function solution(n) {
    if (n === 0) return 0;
    if (n === 1) return 1;

    let a = 0, b = 1, result = 0;
    for (let i = 2; i <= n; i++) {
        result = (a + b) % 1234567;
        a = b;
        b = result;
    }

    return result;
}