function solution(n)
{
    let num = String(n);
    let result =0;
    
    for(let i=0;i<num.length;i++){
        result += Number(num[i]);
    }
        
    return result;
}