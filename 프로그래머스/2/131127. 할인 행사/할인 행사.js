function solution(want, number, discount) {
    let answer = 0;

    // 원하는 물품과 수량을 객체로 매핑
    const result = want.reduce((acc, key, index) => {
        acc[key] = number[index];
        return acc;
    }, {});

    // 연속된 10일 동안의 물품 검사
    for (let i = 0; i <= discount.length - 10; i++) {
        // 현재 10일간의 할인 품목
        let newArray = discount.slice(i, i + 10);

        // 10일간의 품목 수량 계산
        let fruitCount = newArray.reduce((acc, word) => {
            acc[word] = (acc[word] || 0) + 1; // 단어가 이미 있으면 +1, 없으면 1로 초기화
            return acc;
        }, {});

        // 두 객체의 내용을 비교
        const isMatch = Object.keys(result).every(key => result[key] === fruitCount[key]);

        if (isMatch) answer++;
    }

    return answer;
}
