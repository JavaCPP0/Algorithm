function solution(answers) {
    let correct = [0, 0, 0];
    let num1 = [1, 2, 3, 4, 5];
    let num2 = [2, 1, 2, 3, 2, 4, 2, 5]; 
    let num3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5];
    
    for (let i = 0; i < answers.length; i++) {
        if (answers[i] === num1[i % num1.length]) {
            correct[0]++;
        }
        if (answers[i] === num2[i % num2.length]) {
            correct[1]++;
        }
        if (answers[i] === num3[i % num3.length]) {
            correct[2]++;
        }
    }

    const maxValue = Math.max(...correct);
    const answer = correct
        .map((value, index) => (value === maxValue ? index + 1 : -1))
        .filter(index => index !== -1);
    
    return answer;
}
