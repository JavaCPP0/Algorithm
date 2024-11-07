function solution(n) {
    let str = String(n).split('');

    for (let i = 0; i < str.length / 2; i++) {
        let temp = str[i];
        str[i] = str[str.length - 1 - i];
        str[str.length - 1 - i] = temp;
    }
    
    return str.map(Number);
}
