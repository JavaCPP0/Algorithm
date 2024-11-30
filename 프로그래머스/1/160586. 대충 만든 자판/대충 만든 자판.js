function solution(keymap, targets) {
    let answer = [];
    

    targets.forEach((str) => {
        let count =0;
        for (let i = 0; i < str.length; i++) {
        let index = new Array(keymap.length).fill(-1);
            
            for(let k=0;k<keymap.length;k++){
                index[k]=keymap[k].indexOf(str[i]);
            }
            let notNegative = index.filter(num => num >= 0)
            
            if(notNegative.length>0){
                count +=Math.min(...notNegative)+1;
            }else{
                count =-1;
                break;
            }
                
        }
        answer.push(count);
    });
    return answer;
}