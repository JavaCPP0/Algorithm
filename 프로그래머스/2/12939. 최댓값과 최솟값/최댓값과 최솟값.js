function solution(s) {
    let answer = [];
    s = s.split(" ");
    const newarr = s.map((x)=>Number(x));
    
    answer.push(String(Math.min(...newarr)));
    answer.push(String(Math.max(...newarr)));

    return answer.join(" ");
}