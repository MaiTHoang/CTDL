#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

struct Node {
    int x, y, steps;
};

int bfs(int M, int N, const vector<vector<int>>& matrix) {
    // Tạo mảng visited để đánh dấu các ô đã thăm
    vector<vector<bool>> visited(M + 1, vector<bool>(N + 1, false));
    queue<Node> q;

    // Bắt đầu BFS từ ô (1,1)
    q.push({1, 1, 0});  // {x, y, steps}
    visited[1][1] = true;

    while (!q.empty()) {
        Node current = q.front();
        q.pop();
        
        int x = current.x, y = current.y, steps = current.steps;

        // Nếu đã đến đích (M, N)
        if (x == M && y == N) {
            return steps;
        }

        // Di chuyển sang ô bên phải (x, y + A[x][y])
        if (y + matrix[x][y] <= N && !visited[x][y + matrix[x][y]]) {
            visited[x][y + matrix[x][y]] = true;
            q.push({x, y + matrix[x][y], steps + 1});
        }

        // Di chuyển sang ô bên dưới (x + A[x][y], y)
        if (x + matrix[x][y] <= M && !visited[x + matrix[x][y]][y]) {
            visited[x + matrix[x][y]][y] = true;
            q.push({x + matrix[x][y], y, steps + 1});
        }
    }

    // Không tìm thấy đường đi
    return -1;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int M, N;
        cin >> M >> N;

        vector<vector<int>> matrix(M + 1, vector<int>(N + 1));

        // Nhập ma trận A
        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                cin >> matrix[i][j];
            }
        }

        // Tính số bước ít nhất từ A[1][1] đến A[M][N]
        cout << bfs(M, N, matrix) << endl;
    }

    return 0;
}
