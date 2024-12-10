function solution(s) {
    s = s.split(" ");
    
    const newarr = s.map((word)=>{
        word = word.toLowerCase();
        if(typeof word[0] === "string"){
            word = word[0].toUpperCase() + word.slice(1);
        }
        return word;
    })
    return newarr.join(" ");
}