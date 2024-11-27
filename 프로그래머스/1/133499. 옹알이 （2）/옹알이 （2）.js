function solution(babbling) {
    const validParts = ["aya", "ye", "woo", "ma"];
    const pattern = new RegExp(`^(?:${validParts.join("|")})+$`);
    let count = 0;

    for (const word of babbling) {
        // 유효한 발음 조합인지 확인
        if (pattern.test(word)) {
            // 연속된 발음이 있는지 확인
            let isValid = true;
            let lastPart = ""; // 마지막 발음 기록

            for (let i = 0; i < word.length; i++) {
                // 발음이 끝나는 부분을 찾기 위해 길이를 기준으로 분리
                for (const part of validParts) {
                    if (word.startsWith(part, i)) {
                        // 만약 연속된 발음이 나오면 유효하지 않음
                        if (part === lastPart) {
                            isValid = false;
                            break;
                        }
                        lastPart = part; // 마지막 발음을 갱신
                        i += part.length - 1; // 해당 발음 길이만큼 건너뜀
                        break;
                    }
                }
                if (!isValid) break; // 연속 발음이 발견되면 바로 종료
            }

            if (isValid) count++; // 유효한 발음이면 count 증가
        }
    }

    return count;
}
