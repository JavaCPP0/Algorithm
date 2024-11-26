function solution(lottos, win_nums) {
    let count = 0;
    let cnt0=0;
    
    for(let i=0;i<lottos.length;i++){
        if(lottos[i]===0) cnt0++;
        for(let j=0;j<win_nums.length;j++){
            if(lottos[i]===win_nums[j]) count++;
        }
    }
    let answer =  [prize(count),prize(count+cnt0)];
    return answer.sort();
}

function prize(count){
    switch(count){
        case 2:return 5;
        case 3:return 4;
        case 4:return 3;
        case 5:return 2;
        case 6:return 1;
        default: return 6;
    }
}