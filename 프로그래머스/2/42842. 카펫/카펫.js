function solution(brown, yellow) {
    let extent = brown + yellow;
    
    for (let height = 3; height <= Math.sqrt(extent); height++) {
        if (extent % height === 0) {
            let width = extent / height;
            if ((width - 2) * (height - 2) === yellow) {
                return [width, height];
            }
        }
    }
    return [];
}
