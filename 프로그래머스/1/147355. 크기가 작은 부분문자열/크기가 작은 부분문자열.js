function solution(t, p) {
    let result =0;
    for(let i=0;i<=t.length-p.length;i++){
        let num  = t.substr(i,p.length);
        if(parseInt(p)>=parseInt(num)) result++;
    }
    return result;
}