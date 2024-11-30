function solution(s) {
    let answer = []; 
    let x = s[0];
    let cntX=0;
    let cntNotX=0;

        
        for(let i=0;i<s.length;i++){ 
            if(s[i]===x){
                cntX++;
            }else if(s[i]!==x){
                cntNotX++;
            }
        
            if(cntX===cntNotX){
                answer.push(s.substring(0,i+1));
                x=s[i+1];
                cntX=0;
                cntNotX=0;
            }      
        
         }
    if(answer[answer.length-1] !== s) return answer.length+1;
        
    return answer.length;
}