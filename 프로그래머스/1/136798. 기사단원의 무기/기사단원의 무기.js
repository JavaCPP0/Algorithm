function solution(number, limit, power) {
    let answer = 0;

    for (let i = 1; i <= number; i++) {
        let div = 0;
        for (let j = 1; j * j <= i; j++) {
            if (i % j === 0) {
                div++;
                if (j !== i / j) div++;
            }
        }
        answer += div > limit ? power : div;
    }

    return answer;
}
