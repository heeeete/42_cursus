#include <iostream>
#include <vector>

// 두 부분 배열을 병합하는 함수
void merge(std::vector<std::pair<int, int>>& vec, int left, int mid, int right) {
    int n1 = mid - left + 1; // 첫 번째 부분 배열의 크기
    int n2 = right - mid;    // 두 번째 부분 배열의 크기

    // 임시 배열 생성
    std::vector<std::pair<int, int>> L(n1), R(n2);

    // 데이터를 임시 배열에 복사
    for (int i = 0; i < n1; i++)
        L[i] = vec[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = vec[mid + 1 + j];

    // 임시 배열들을 병합하여 원래 배열에 정렬
    int i = 0;     // 첫 번째 부분 배열의 초기 인덱스
    int j = 0;     // 두 번째 부분 배열의 초기 인덱스
    int k = left;  // 병합된 배열의 초기 인덱스

    while (i < n1 && j < n2) {
        if (L[i].first <= R[j].first) {
            vec[k] = L[i];
            i++;
        } else {
            vec[k] = R[j];
            j++;
        }
        k++;
    }

    // L[]과 R[]에 남아있는 요소들을 복사
    while (i < n1) {
        vec[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        vec[k] = R[j];
        j++;
        k++;
    }

}

// 병합 정렬을 재귀적으로 수행하는 함수
void mergeSort(std::vector<std::pair<int, int>>& vec, int left, int right) {
    if (left < right) {
        // 중간 지점을 찾습니다.
        int mid = (right + left) / 2;
		std::cout << left << " " << mid << " " << right << "\n";

        // 첫 번째와 두 번째 부분 배열을 재귀적으로 정렬합니다.
        mergeSort(vec, left, mid);
        mergeSort(vec, mid + 1, right);

        // 병합합니다.
		std::cout << "병합" << left << " " << mid << " " << right << "\n";
        merge(vec, left, mid, right);
    }
}

int main() {
    std::vector<std::pair<int, int>> vec = {{3, 4}, {1, 2}, {5, 1}, {7, 3}, {2, 6}, {4, 5}};
	std::cout << "asd\n";

    // 벡터를 정렬
    mergeSort(vec, 0, vec.size() - 1);

    // 정렬된 벡터를 출력
    for (const auto& p : vec) {
        std::cout << "(" << p.first << ", " << p.second << ")" << " ";
    }

    return 0;
}

// {3, 4}, {1, 2}, {5, 1}, {7, 3}, {2, 6}, {4, 5}
// {3, 4}, {1, 2}, {5, 1},					{7, 3}, {2, 6}, {4, 5}
// {3, 4}, {1, 2},           {5, 1},					{7, 3}, {2, 6},              {4, 5}
// {3, 4},           {1, 2},           {5, 1},					{7, 3},           {2, 6},              {4, 5}


