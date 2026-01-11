#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct GenreInfo {
    vector<pair<int,int>> songs;
    int totalPlays = 0;
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    unordered_map<string, GenreInfo> dict;

    for (int i = 0; i < (int)plays.size(); i++) {
        auto& info = dict[genres[i]];
        info.songs.push_back({i, plays[i]});
        info.totalPlays += plays[i];
    }

    vector<pair<string, GenreInfo>> v;
    v.reserve(dict.size());
    for (const auto& kv : dict) {
        v.push_back({kv.first, kv.second});
    }

    for (auto& genrePair : v) {
        auto& songs = genrePair.second.songs;

        sort(songs.begin(), songs.end(), [](const auto& a, const auto& b) {
            if (a.second != b.second) return a.second > b.second;
            return a.first < b.first;
        });
    }

    sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
        return a.second.totalPlays > b.second.totalPlays;
    });

    for(const auto& genre:v){
        const auto& songs = genre.second.songs;
        
        for(int i=0;i<songs.size() && i<2;i++){
            answer.push_back(songs[i].first);
        }
        
    }
    
    return answer;
}
