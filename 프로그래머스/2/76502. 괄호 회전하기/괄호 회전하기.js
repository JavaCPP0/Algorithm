// function solution(s) {
//     let answer = 0;

//     // 괄호 검증 함수
//     function isValid(str) {
//         let round = 0;  // 소괄호 ()
//         let curly = 0;  // 중괄호 {}
//         let square = 0; // 대괄호 []

//         for (let char of str) {
//             // 여는 괄호일 때 카운터 증가
//             if (char === '(') round++;
//             else if (char === '{') curly++;
//             else if (char === '[') square++;

//             // 닫는 괄호일 때 카운터 감소
//             else if (char === ')') {
//                 if (round === 0) return false; // 여는 괄호가 없으면 잘못된 순서
//                 round--;
//             }
//             else if (char === '}') {
//                 if (curly === 0) return false; // 여는 괄호가 없으면 잘못된 순서
//                 curly--;
//             }
//             else if (char === ']') {
//                 if (square === 0) return false; // 여는 괄호가 없으면 잘못된 순서
//                 square--;
//             }
//         }

//         // 모든 카운터가 0이어야 올바른 괄호
//         return round === 0 && curly === 0 && square === 0;
//     }

//     // 문자열 회전하며 검증
//     for (let i = 0; i < s.length; i++) {
//         if (isValid(s)) answer++; // 올바른 경우 카운트
//         s = s.slice(1) + s[0]; // 문자열 회전
//     }

//     return answer;
// }

function solution(s) {
    let answer = 0;

    // 괄호 검증 함수 (스택 방식)
    function isValid(str) {
        let stack = [];

        for (let char of str) {
            if (char === '(' || char === '{' || char === '[') {
                stack.push(char); // 여는 괄호는 스택에 넣기
            } else {
                // 닫는 괄호가 나오면 스택에서 꺼내서 짝을 맞춰본다
                if (stack.length === 0) return false; // 스택이 비어있으면 올바르지 않음

                let top = stack.pop(); // 스택에서 가장 최근의 여는 괄호 꺼내기
                if (char === ')' && top !== '(') return false;
                if (char === '}' && top !== '{') return false;
                if (char === ']' && top !== '[') return false;
            }
        }

        return stack.length === 0; // 스택이 비어있어야 올바른 괄호 문자열
    }

    // 문자열 회전하며 검증
    for (let i = 0; i < s.length; i++) {
        if (isValid(s)) answer++; // 올바른 경우 카운트
        s = s.slice(1) + s[0]; // 문자열 회전
    }

    return answer;
}

