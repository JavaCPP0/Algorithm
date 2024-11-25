function painting(index, m, status) {
    for (let i = index; i < index + m && i < status.length; i++) {
        status[i] = 1;
    }
}

function isItDone(status,n){
    for(let j=0;j<n;j++){
            if(status[j]===-1) return false;
    }
    return true;
}

function solution(n, m, section) {
    let status = Array(n).fill(1);
    let count = 0;

    section.forEach((num) => {
        status[num - 1] = -1;
    });

    let i = 0;
    while (i < n) {
        if (status[i] === -1) {
            painting(i, m, status);
            count++;
            i += m;
        } else {
            i++;
        }
        
        if(isItDone(status,n)) return count;
    }

    return count;
}