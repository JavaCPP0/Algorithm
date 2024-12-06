function solution(players, callings) {
    let indexMap = players.reduce((map, player, idx) => {
        map[player] = idx;
        return map;
    }, {});

    for (let i = 0; i < callings.length; i++) {
        let player = callings[i];
        let rank = indexMap[player];
        if (rank > 0) {
            let prevPlayer = players[rank - 1];

            [players[rank - 1], players[rank]] = [players[rank], players[rank - 1]];

            indexMap[player]--;
            indexMap[prevPlayer]++;
        }
    }

    return players;
}
