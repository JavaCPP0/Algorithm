function solution(num) {
    let result=0;
    
    if(num===1) return 0;
    
    while(1){
        if(num%2===0) num = num/2;
        else num =num*3+1;
        result++;
        if(num === 1) return result;
        if(result ===500) return -1;
    }
}