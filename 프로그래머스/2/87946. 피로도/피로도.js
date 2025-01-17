function getPermutations(arr) {
    if (arr.length === 1) return [arr];
    
    const permutations = [];
    arr.forEach((fixed, index, origin) => {
        const rest = origin.filter((_, i) => i !== index); // 현재 요소 제외
        const subPermutations = getPermutations(rest); // 나머지 배열의 순열
        const attached = subPermutations.map(permutation => [fixed, ...permutation]);
        permutations.push(...attached);
    });
    return permutations;
}

function solution(k, dungeons) {
    let maxCount = 0;
    const cases = getPermutations(dungeons); // 던전의 모든 순열 생성

    cases.forEach(dungeonOrder => {
        let count = 0;
        let fatigue = k;

        dungeonOrder.forEach(dungeon => {
            if (fatigue >= dungeon[0]) { // 최소 필요 피로도 확인
                count++;
                fatigue -= dungeon[1]; // 피로도 소모
            }
        });

        maxCount = Math.max(maxCount, count); // 최대 던전 수 갱신
    });

    return maxCount; // 최대 던전 수 반환
}
