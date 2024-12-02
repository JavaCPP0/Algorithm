function solution(ingredient) {
    let answer = 0;

    for (let i = 0; i <= ingredient.length - 4; ) {
        if (ingredient[i] === 1 && ingredient[i + 1] === 2 && ingredient[i + 2] === 3 && ingredient[i + 3] === 1) {
            answer++;
            ingredient.splice(i, 4);
            i = Math.max(0, i - 3); 
        } else {
            i++;
        }
    }

    return answer;
}
