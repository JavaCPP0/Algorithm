function solution(elements) {
    var answer = 0;
    let newarr = elements.concat(elements); // 배열을 2배로 확장
    let result = [];
    
    for (let i = 1; i <= elements.length; i++) { // 부분 수열의 길이
        for (let j = 0; j < elements.length; j++) { // 시작 위치
            result.push(newarr.slice(j, j + i).reduce((sum, num) => sum + num, 0));
        }
    }
    
    answer = [...new Set(result)].length; // 중복 제거 후 길이 계산
    
    return answer;
}
