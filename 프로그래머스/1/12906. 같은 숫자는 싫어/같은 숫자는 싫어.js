function solution(arr)
{
    let answer = [];
    let cur = null;
    
    for(let i=0; i<arr.length;i++){
        if(arr[i]!==cur){
            answer.push(arr[i]);
        }
        cur=arr[i];
    }
    
    return answer;
}