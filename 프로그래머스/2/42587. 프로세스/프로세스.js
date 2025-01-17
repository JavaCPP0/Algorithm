function solution(priorities, location) {
    let answer = 0;
    let queue = [...priorities]; // 깊은 복사
    let targetIndex = location; // 추적할 작업의 위치

    while (queue.length > 0) {
        // 큐의 첫 번째 작업 꺼내기
        let current = queue.shift();

        // 우선순위 높은 작업이 있다면 현재 작업을 뒤로 보냄
        if (queue.some(num => num > current)) {
            queue.push(current);
            // 추적 대상의 인덱스도 이동
            targetIndex = targetIndex === 0 ? queue.length - 1 : targetIndex - 1;
        } else {
            // 현재 작업 실행
            answer++;
            if (targetIndex === 0) {
                return answer; // 추적 대상 실행 순서 반환
            }
            targetIndex--;
        }
    }

    return answer;
}
