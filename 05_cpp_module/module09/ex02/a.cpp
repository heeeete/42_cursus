#include <iostream>
#include <vector>

int jacobsthal(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

int main() {
    std::cout << jacobsthal(2) << "asd" << "\n";
    return 0;
}

// {3, 4}, {1, 2}, {5, 1}, {7, 3}, {2, 6}, {4, 5}
// {3, 4}, {1, 2}, {5, 1},					{7, 3}, {2, 6}, {4, 5}
// {3, 4}, {1, 2},           {5, 1},					{7, 3}, {2, 6},              {4, 5}
// {3, 4},           {1, 2},           {5, 1},					{7, 3},           {2, 6},              {4, 5}


