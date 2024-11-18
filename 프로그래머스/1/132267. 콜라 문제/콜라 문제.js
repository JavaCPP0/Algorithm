function solution(a, b, n) {
    let answer = 0;
    let left = n;
    
    while(left>=a){
        answer += Math.floor(left/a)*b;
        left = (left%a+Math.floor(left/a)*b);
    }

    return answer;
}