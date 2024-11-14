function solution(s) {
    var answer = "";
    let num = ['zero','one','two','three','four','five','six','seven','eight','nine'];
    
    for (let j = 0; j < s.length; j++) {
        if (s[j] >= '0' && s[j] <= '9') {
            answer += s[j];
        } else {
            for (let i = 0; i < 10; i++) {
                if (s.substr(j, num[i].length) === num[i]) {
                    answer += i;
                    j += num[i].length - 1;
                    break;
                }
            }
        }
    }
    
    return Number(answer);
}
