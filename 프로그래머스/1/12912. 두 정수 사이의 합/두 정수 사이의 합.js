function solution(a, b) {
    let result=0;
    
    if(a>b){
        for(let i=b;i<=a;i++)
        result +=i;
    } else if(b>a){
        for(let i=a;i<=b;i++)
        result +=i;
    }else return a;
    
    return result;
}