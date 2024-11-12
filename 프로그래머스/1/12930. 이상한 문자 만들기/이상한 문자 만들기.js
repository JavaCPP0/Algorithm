function solution(s) {
    let arr = s.split(" ");
    let result = [];
    for(let i=0;i<arr.length;i++){
        let trans="";
       for(let j=0;j<arr[i].length;j++){
            if(j%2===0){
            trans+=(arr[i][j].toUpperCase());
        } else if(j%2 === 1){
            trans+=(arr[i][j].toLowerCase());
        }
       }
        result.push(trans);
    }
    
    return result.join(" ");
}