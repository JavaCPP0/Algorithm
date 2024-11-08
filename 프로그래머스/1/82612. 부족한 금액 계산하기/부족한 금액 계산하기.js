function solution(price, money, count) {
    let result= 0;
    
    for(let i=1;i<=count;i++){
        result += i*price;
    }
    if(result<money) return 0;
    result -= money;

    
    
    return Math.abs(result);
}