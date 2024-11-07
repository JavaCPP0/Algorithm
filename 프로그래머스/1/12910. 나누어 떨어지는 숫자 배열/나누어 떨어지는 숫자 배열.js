function solution(arr, divisor) {
    let result = [];
    
    for(let i=0;i<arr.length;i++){
        if(arr[i]%divisor ===0){
            result.push(arr[i]);
        }
    }
    
    if(result.length === 0){
        result.push(-1);
        return result;
    } else return result.sort((a, b) => a - b);
}