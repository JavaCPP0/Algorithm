function solution(numbers) {
    let answer =[];
    for(let i=0; i<numbers.length;i++){
        for(let j=i+1;j<numbers.length;j++){
            answer.push(numbers[i]+numbers[j]);
        }
    }
    answer.sort(function(a,b){return a-b;});
    
    for(let i=0; i<answer.length-1;i++){
        if(answer[i]===answer[i+1]){
            answer.splice(i+1,1);
            i--;
        }
    }
    
    
    return answer
}