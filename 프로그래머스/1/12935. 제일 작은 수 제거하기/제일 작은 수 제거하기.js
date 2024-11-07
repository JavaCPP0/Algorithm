function solution(arr) {
    let min = arr[0]; 
    let minIndex = 0;
    
    if (arr.length === 1) return [-1];

    for (let i = 1; i < arr.length; i++) {
        if (arr[i] < min) {
            min = arr[i];
            minIndex = i;
        }
    }

    arr.splice(minIndex, 1);
    return arr;
}