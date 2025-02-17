#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

// Hàm để quay một ô theo chiều kim đồng hồ (bên trái hoặc bên phải)
vector<int> rotate(vector<int>& state, int i) {
    // Quay ô thứ i (từ 0 đến 5)
    vector<int> newState = state;
    int temp = newState[i];
    newState[i] = newState[(i + 1) % 6];
    newState[(i + 1) % 6] = temp;
    return newState;
}

int bfs(vector<int> start, vector<int> end) {
    // BFS tìm số bước ngắn nhất từ start đến end
    queue<pair<vector<int>, int>> q; // Mỗi phần tử là một cặp
