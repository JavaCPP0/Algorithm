function solution(s) {
    if(s.length%2 === 1) return s[Math.ceil(s.length/2)-1];
    else if(s.length%2===0) return s[s.length/2-1]+s[s.length/2];
}