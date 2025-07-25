#include <iostream>
#include <deque>

using namespace std;

typedef pair<int, int> Node;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, l;
    cin >> n >> l;

    // 인덱스와 숫자로 이루어진 페어노드 큐를 생성
    deque<Node> deque;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        // 새 노드를 받을때마다 인덱스와 숫자를 비교
        // 큐의 뒷 노드부터 비교하여 만약 숫자가 방금 들어온 노드의 숫자보다 크면 모두 삭제
        while (deque.size() > 0 && deque.back().second > num) {
            deque.pop_back();
        }
        //방금 들어온 노드의 숫자를 결과 리스트에 저장 
        deque.push_back(Node(i, num));

        // 만약 인덱스가 윈도우를 벗어나면 노드 삭제
        if (deque.front().first <= i - l) {
            deque.pop_front();
        }

        cout << deque.front().second<< " ";

    }
    return 0;
}


