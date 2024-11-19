function findMin(honor){
    let min=0;
    for(let i=0;i<honor.length;i++){
        if(honor[min]>honor[i]){
            min = i;
        }
    }
    return min;
}

function solution(k, score) {
    let honor =[];
    let answer = [];
    
    for(let i=0;i<score.length;i++){
        if(honor.length <k){
            honor.push(score[i]);
            
        } else if(honor.length>=k){
            if(honor[findMin(honor)]<score[i]){
                //최솟값 빼고
                honor.splice(findMin(honor),1);
                honor.push(score[i]);
                
            }
        }
        answer.push(honor[findMin(honor)]);
    }
    
    return answer;
}

