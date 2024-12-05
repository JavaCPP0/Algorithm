function solution(today, terms, privacies) {
    let answer = [];
    let todayDate = new Date(today);
    
    let termMap = new Map();
    for (let i = 0; i < terms.length; i++) {
        let [type, period] = terms[i].split(' ');
        termMap.set(type, parseInt(period));
    }
    
    for (let j = 0; j < privacies.length; j++) {
        let [startDate, type] = privacies[j].split(' ');
        let expirationDate = new Date(startDate);
        let period = termMap.get(type);
        
        expirationDate.setMonth(expirationDate.getMonth() + period);
        
        if (expirationDate <= todayDate) {
            answer.push(j + 1);
        }
    }
    
    return answer;
}
