function solution(id_list, report, k) {
    var answer = [];
    
    // reportinfo 초기화
    let reportinfo = id_list.reduce((acc, name, index) => {        
        acc[name] = { reportedBy: [], reportedCount: 0, index: index }; // 속성명 일관되게 수정
        answer.push(0); // 초기화된 answer 배열에 0 추가
        return acc;
    }, {});
    
    // report 순회하며 신고 처리
    report.forEach(entry => {
        let [reporter, reported] = entry.split(" ");
        
        if (!reportinfo[reported].reportedBy.includes(reporter)) {
            reportinfo[reported].reportedBy.push(reporter);
            reportinfo[reported].reportedCount += 1;
        }
    });
    
    // k번 이상 신고당한 사용자 확인
    Object.keys(reportinfo).forEach(name => {
        if (reportinfo[name].reportedCount >= k) {
            reportinfo[name].reportedBy.forEach(reporter => {
                answer[reportinfo[reporter].index] += 1; // 신고자의 index에 해당하는 answer 값 증가
            });
        }
    });
     
    return answer;
}
