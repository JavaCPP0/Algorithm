function solution(k, m, score) {
    var answer = 0;
    
    score.sort(function (a, b) {
      return b-a;
    });
    
    for(let i=0;i<Math.floor(score.length/m);i++){
        if(m+i*m<=score.length){
            answer += score[m+i*m-1]*m;
        }
    }
    
    return answer;
}