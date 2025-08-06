#include <iostream>
#include <vector>
using namespace std;

// 병합하는 함수
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;   // 왼쪽 배열 크기
    int n2 = right - mid;      // 오른쪽 배열 크기

    // 왼쪽과 오른쪽 배열을 임시 벡터에 복사
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];  // arr의 왼쪽 부분 복사
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j]; // arr의 오른쪽 부분 복사

    int i = 0, j = 0, k = left; // i: L 인덱스, j: R 인덱스, k: arr 인덱스

    // L과 R을 비교하여 더 작은 값을 arr에 채워 넣음
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];  // L[i]가 더 작거나 같으면 arr에 삽입
        else
            arr[k++] = R[j++];  // R[j]가 더 작으면 arr에 삽입
    }

    // L에 남은 요소들 복사
    while (i < n1)
        arr[k++] = L[i++];

    // R에 남은 요소들 복사
    while (j < n2)
        arr[k++] = R[j++];
}

// 재귀적으로 배열을 반으로 쪼개고 merge로 병합하는 함수
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {   // left와 right가 교차하지 않을 때만 수행
        int mid = left + (right - left) / 2;
        // 중앙값 (overflow 방지를 위해 left + (right - left)/2 사용)

        // 왼쪽 절반 정렬
        mergeSort(arr, left, mid);

        // 오른쪽 절반 정렬
        mergeSort(arr, mid + 1, right);

        // 정렬된 두 절반 병합
        merge(arr, left, mid, right);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n ;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    mergeSort(arr, 0, arr.size() - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\n";
    }
}
