function solution(citations) {
    let h = Math.max(...citations);
    let hIndex = 0;
    
    for(let i=1;i<=h;i++){
        let cntcit =0;
        for(let j=0;j<citations.length;j++){
            if(citations[j]>=i) cntcit++;
        }
        if(cntcit>=i){
            hIndex = i;
        }else break;
    }
    return hIndex;
}