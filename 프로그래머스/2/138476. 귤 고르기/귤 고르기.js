function solution(k, tangerine) {
    // 귤 크기별로 개수 카운트
    const countMap = new Map();
    tangerine.forEach(size => {
        countMap.set(size, (countMap.get(size) || 0) + 1);
    });

    // 빈도수를 배열로 변환한 뒤 내림차순으로 정렬
    const sortedCounts = Array.from(countMap.values()).sort((a, b) => b - a);

    let total = 0; // 선택한 귤의 개수
    let typeCount = 0; // 선택한 귤의 종류 수

    // 빈도수가 높은 것부터 선택
    for (const count of sortedCounts) {
        total += count;
        typeCount += 1;
        if (total >= k) break;
    }

    return typeCount;
}
