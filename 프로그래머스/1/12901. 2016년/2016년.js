function solution(a, b) {

    let date = new Date(`${a} ${b} 2016`);

    let days = ['SUN', 'MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT'];

    return days[date.getDay()];

}