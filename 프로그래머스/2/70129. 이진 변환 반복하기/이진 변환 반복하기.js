function solution(s) {
    let answer = [];
    let howManyTimes = 0;
    let howManyZeros = 0;
    
    while(s !== "1"){
        let newS ="";
        for(let i=0; i<s.length;i++){
            if(s[i]==="1") newS+="1";
            else howManyZeros +=1;
        }
        howManyTimes ++;
        s = newS.length.toString(2);
    }
    
    answer = [howManyTimes,howManyZeros];
    
    return answer;
}