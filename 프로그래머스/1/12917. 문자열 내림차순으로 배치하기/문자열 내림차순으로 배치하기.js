function solution(s) {
    
    let uppercase = s.split('').filter(char => char === char.toUpperCase()); 
    let lowercase = s.split('').filter(char => char === char.toLowerCase());
    
    
    uppercase.sort((a, b) => b.localeCompare(a)); 
    lowercase.sort((a, b) => b.localeCompare(a)); 
    
    
    return lowercase.join('') + uppercase.join('');
}
