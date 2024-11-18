function solution(food) {
    let answer = '';
    
    for(let i=1;i<food.length;i++){
        let n =Math.floor(food[i]/2);
        for(let j=0;j<n;j++){
            answer += i;
        }
    }
    
    let arr1 = answer.split('');
    answer +=0;
    arr1 = arr1.reverse().join('');
    answer += arr1;
    return answer;
}