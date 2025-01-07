function solution(clothes) {
    let answer = 0;
    
    const list = clothes.reduce((list,product)=>{
        list[product[1]] = (list[product[1]] || 0) +1;
        return list
    },{});
    
    let values = Object.values(list)
    answer = values.reduce((total, options) => total * (options + 1), 1) - 1;
    
    
    
    return answer;
}