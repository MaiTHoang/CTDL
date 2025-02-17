#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

const int dx[] = {0, 1, 0, -1};  // Di chuyển theo hàng (trái, phải, lên, xuống)
const int dy[] = {1, 0, -1, 0};

struct State {
    int x, y, steps;
};

bool isValid(int x, int y, int N, const vector<vector<char>>& grid) {
    return x >= 0 && x < N && y >= 0 && y < N && grid[x][y] == '.';
}

int bfs(int N, const vector<vector<char>>& grid, int ax, int ay, int bx, int by) {
    queue<State> q;
    vector<vector<bool>> visited(N, vector<bool>(N, false));

    q.push({ax, ay, 0});
    visited[ax][ay] = true;

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        // Nếu đã đến đích, trả về số bước
        if (current.x == bx && current.y == by) {
            return current.steps;
        }

        // Tìm các ô có thể di chuyển trong cùng hàng hoặc cùng cột
        for (int i = 0; i < 4; ++i) {
            int nx = current.x;
            int ny = current.y;
            // Di chuyển dọc theo hướng (dx[i], dy[i]) cho đến khi gặp vật cản hoặc ra ngoài bảng
            while (isValid(nx + dx[i], ny + dy[i], N, grid)) {
                nx += dx[i];
                ny += dy[i];
                if (!visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({nx, ny, current.steps + 1});
                }
            }
        }
    }

    return -1;  // Không thể tìm đường
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<vector<char>> grid(N, vector<char>(N));

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> grid[i][j];
            }
        }

        int a, b, c, d;
        cin >> a >> b >> c >> d;

        // Gọi BFS để tìm số bước di chuyển ít nhất
        cout << bfs(N, grid, a, b, c, d) << endl;
    }

    return 0;
}
