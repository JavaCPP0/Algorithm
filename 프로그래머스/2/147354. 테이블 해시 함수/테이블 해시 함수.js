function solution(data, col, row_begin, row_end) {
    let answer =0;
    let sortdata = data.sort((a, b) => {
    if (a[col - 1] === b[col - 1]) {
        return b[0]-a[0] ;
    } else {
        return a[col - 1] - b[col - 1];
    }
    });
    
    for(let i=row_begin-1;i<=row_end-1;i++){
        let sum=0;
        for(let j=0;j<sortdata[0].length;j++){
            sum += sortdata[i][j]%(i+1);
        }
        answer ^=sum;
    }
    
    return answer;
}