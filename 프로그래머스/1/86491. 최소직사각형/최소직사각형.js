function solution(sizes) {
    for(let i=0; i<sizes.length;i++){
        sizes[i].sort((a,b)=>a-b);
    }
    
    let maxFirst = Math.max(...sizes.map(subArray => subArray[0]));
    let maxSecond = Math.max(...sizes.map(subArray => subArray[1]));
    
    return maxFirst*maxSecond;
    
    
}