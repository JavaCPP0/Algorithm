function solution(survey, choices) {
    let result = { R: 0, T: 0, C: 0, F: 0, J: 0, M: 0, A: 0, N: 0 };
    let score = [3, 2, 1, 0, 1, 2, 3];

    for (let i = 0; i < survey.length; i++) {
        let [first, second] = survey[i];
        if (choices[i] < 4) {
            result[first] += score[choices[i] - 1];
        } else if (choices[i] > 4) {
            result[second] += score[choices[i] - 1];
        }
    }

    let answer = '';
    answer += result.R >= result.T ? 'R' : 'T';
    answer += result.C >= result.F ? 'C' : 'F';
    answer += result.J >= result.M ? 'J' : 'M';
    answer += result.A >= result.N ? 'A' : 'N';

    return answer;
}
