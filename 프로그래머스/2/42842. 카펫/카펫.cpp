#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int extent = brown + yellow;

    for (int height = 3; height <= (int)sqrt(extent); ++height) {
        if (extent % height == 0) {
            int width = extent / height;

            if ((width - 2) * (height - 2) == yellow) {
                return {width, height};
            }
        }
    }
    return {};
}
