// function solution(n, left, right) {
//     let answer = [];
    
//     // n x n 배열 초기화
//     let arr = Array.from({ length: n }, () => Array(n).fill(null));
    
//    for(let i=0;i<n;i++){
//        for(let j=0;j<n;j++){
//            arr[i][j] = Math.max(i+1,j+1);
//        }
//    }
    
//     answer = arr.flat();
    
//     // left부터 right까지 값을 반환
//     return answer.slice(left, right+1);
// } 메모리를 너무 많이 ㅅ사용

function solution(n, left, right) {
    let answer = [];
    
    // 필요한 인덱스만 계산하여 반환
    for (let i = left; i <= right; i++) {
        let row = Math.floor(i / n);
        let col = i % n;
        answer.push(Math.max(row + 1, col + 1));
    }
    
    return answer;
}

