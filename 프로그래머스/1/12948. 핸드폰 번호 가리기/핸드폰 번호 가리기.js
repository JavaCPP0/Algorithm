function solution(phone_number) {
    let backNumber = phone_number.slice(-4);
    let stars ="";
    
    for(let i=0;i<(phone_number.length - 4);i++){
        stars += "*";
    }
    
    return stars+backNumber;
}