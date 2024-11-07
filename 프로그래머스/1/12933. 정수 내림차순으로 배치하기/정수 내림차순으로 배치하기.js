function solution(n) {
    let str = String(n).split('');
    str.sort((a, b) => b - a);
    
    let result = Number(str.join(''));
    return result;
}
