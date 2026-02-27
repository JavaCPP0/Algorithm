#include <iostream>
#include <vector>

using namespace std;

static vector<vector<int>> tree;

void preorder(int root);
void inorder(int root);
void postorder(int root);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	tree.resize(N+1);

	for (int i = 0; i < N; i++) {
		char root, first, second;
		cin >> root >> first >> second;

		int root_idx = root - 'A';

		// 자식이 '.'인 경우 -1로 저장
		int left_node = (first == '.') ? -1 : first - 'A';
		int right_node = (second == '.') ? -1 : second - 'A';

		tree[root_idx].push_back(left_node);
		tree[root_idx].push_back(right_node);
	}

	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);
	cout << '\n';

	return 0;
}

void preorder(int root) {
	if (root == -1) return; // 자식이 없는 노드면 종료

	cout << (char)(root + 'A');       // 1. 루트 방문 (출력)
	preorder(tree[root][0]);          // 2. 왼쪽 자식
	preorder(tree[root][1]);          // 3. 오른쪽 자식
}

void inorder(int root) {
	if (root == -1) return;

	inorder(tree[root][0]);           // 1. 왼쪽 자식
	cout << (char)(root + 'A');       // 2. 루트 방문 (출력)
	inorder(tree[root][1]);           // 3. 오른쪽 자식
}

void postorder(int root) {
	if (root == -1) return;

	postorder(tree[root][0]);         // 1. 왼쪽 자식
	postorder(tree[root][1]);         // 2. 오른쪽 자식
	cout << (char)(root + 'A');       // 3. 루트 방문 (출력)
}