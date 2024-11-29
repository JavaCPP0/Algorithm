function solution(n, lost, reserve) {
    let howmany = Array(n).fill(1);
    
    lost.forEach(index => {
        howmany[index - 1] -= 1;
    });
    
    reserve.forEach(index => {
        howmany[index - 1] += 1;
    });
    
    
    
    for (let i = 0; i < n; i++) {
        if (howmany[i] === 0) {
            if (i > 0 && howmany[i - 1] === 2) {
                howmany[i] += 1;
                howmany[i - 1] -= 1;
            } else if (i < n - 1 && howmany[i + 1] === 2) {
                howmany[i] += 1;
                howmany[i + 1] -= 1;
            }
        }
    }

    return howmany.filter(num => num > 0).length;
}
