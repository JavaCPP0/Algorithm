function solution(x) {
    let num = String(x);
    let result =0;
    
    for(let i=0;i<num.length;i++){
        result += Number(num[i]);
    }
        if(x%result === 0)
            return true;
        else
            return false;
}