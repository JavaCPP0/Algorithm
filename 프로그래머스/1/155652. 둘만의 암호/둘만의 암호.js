function solution(str, skip, index) {
    var answer = '';
    let alphabet=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'];
    
    [...skip].forEach((element) =>{
        let idx = alphabet.indexOf(element);
        alphabet.splice(idx,1);
    });
    
    [...str].forEach((element)=>{
        let idx = alphabet.indexOf(element);
        let n=idx+index;
        while(n>=alphabet.length){
            n-=alphabet.length;
        }

        answer += alphabet[n];
    });
    
    
    return answer;
}