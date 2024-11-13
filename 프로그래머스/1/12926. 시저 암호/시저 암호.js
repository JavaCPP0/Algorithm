function solution(s, n) {
    let arr = [...s];
    
    for (let i = 0; i < arr.length; i++) {
        let charCode = arr[i].charCodeAt(0);
        
        if (arr[i] === ' ') continue;

        if (charCode >= 65 && charCode <= 90) {
            charCode +=n;
            if(charCode>90) charCode -=26;
            arr[i] = String.fromCharCode(charCode);
        }
       
        else if (charCode >= 97 && charCode <= 122) {
            charCode +=n;
            if(charCode>122) charCode -=26;
            arr[i] = String.fromCharCode(charCode);
        }
    }
    
    return arr.join('');
}
