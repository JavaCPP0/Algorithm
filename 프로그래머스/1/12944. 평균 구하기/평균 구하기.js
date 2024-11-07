function solution(arr) {
    let avg=0;
    
    for(let i=0;i<arr.length;i++){
        avg+=arr[i];
    }
    return avg/arr.length;
}