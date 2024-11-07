function solution(n) {
    let sqrt_n = Math.sqrt(n)
    if(sqrt_n%1 === 0){
        return (sqrt_n+1)*(sqrt_n+1);
    } else return -1;
}