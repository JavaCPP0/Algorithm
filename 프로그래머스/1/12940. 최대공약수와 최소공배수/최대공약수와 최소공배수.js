function solution(n, m) {
    var answer = [0,0];
    let max=0;
    let min=0;
    
    for(let i=1;i<=n;i++){
        if(n%i===0 && m%i===0){
            if(i>max) max=i;
        }
    }
    answer[0] =max;
    
    for(let j=1;1;j++){
        if((max*j)%n===0 &&(max*j)%m ===0){
            min = max*j;
            break;
        }
    }
    answer[1]=min;
    return answer;
}