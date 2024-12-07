function solution(park, routes) {
    let answer = [0, 0];

    // 시작점(S) 찾기
    for (let i = 0; i < park.length; i++) {
        let index = park[i].indexOf("S");
        if (index !== -1) {
            answer = [i, index]; // 행과 열의 위치를 정확히 설정
            break;
        }
    }

    // 명령 처리
    routes.forEach((route) => {
        const [dir, , steps] = route.split("");
        const stepCount = Number(steps);
        let [x, y] = answer;

        let rollback = false; // 이동 불가능 시 되돌리기 플래그

        for (let i = 1; i <= stepCount; i++) {
            let nx = x, ny = y;

            // 방향별 이동 계산
            if (dir === "E") ny += 1;
            if (dir === "W") ny -= 1;
            if (dir === "S") nx += 1;
            if (dir === "N") nx -= 1;

            // 경계 및 장애물 확인
            if (nx < 0 || ny < 0 || nx >= park.length || ny >= park[0].length || park[nx][ny] === "X") {
                rollback = true;
                break;
            }

            // 이동 가능하면 위치 갱신
            x = nx;
            y = ny;
        }

        // 이동 불가능 시 원래 위치 유지
        if (!rollback) {
            answer = [x, y];
        }
    });

    return answer;
}
