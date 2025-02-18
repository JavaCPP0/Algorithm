function getMinutesDiff(time1, time2) {
    const [h1, m1] = time1.split(":").map(Number);
    const [h2, m2] = time2.split(":").map(Number);
    
    const minutes1 = h1 * 60 + m1;
    const minutes2 = h2 * 60 + m2;
    
    return minutes2 - minutes1;
}



function solution(fees, records) {
    let answer = [];
    
    const [basicTime,basicRate,unitTime,unitRate] = fees
    
    const parkingRecord = records.reduce((acc,record)=>{
        const [time,number,inNOut] = record.split(" ");
        if(!acc[number]){
            acc[number] =[];
        }
        acc[number].push(time);
        return acc;
    },{});
    
    const keys = Object.keys(parkingRecord);
    
    keys.forEach((key)=>{
        let fee =basicRate;
        let totalTime =0;
        for(let i=0; i<parkingRecord[key].length;i+=2){
            totalTime += getMinutesDiff(parkingRecord[key][i],parkingRecord[key][i+1] ? parkingRecord[key][i+1]:"23:59");

        }
        
        if(totalTime>basicTime){
            fee +=Math.ceil((totalTime-basicTime)/unitTime)*unitRate;
        }
        parkingRecord[key] = fee;
    })
    
    answer = Object.entries(parkingRecord).sort((a, b) => a[0] - b[0]);
    
    return answer.map((entry) => entry[1]);
    
}