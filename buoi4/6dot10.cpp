#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int dx[] = {0, 1, 0, -1};  // Di chuyển: trái, phải, xuống, lên
const int dy[] = {1, 0, -1, 0};  // Di chuyển: phải, xuống, lên, trái

struct Point {
    int x, y, day;
};

int bfs(int R, int C, vector<vector<int>>& grid) {
    queue<Point> q;
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    int day = 0;
    bool has_mandatory_seed = false;

    // Thêm tất cả các cây non vào hàng đợi và đánh dấu chúng là đã thăm
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (grid[i][j] == 2) {  // Cây non
                q.push({i, j, 0});
                visited[i][j] = true;
            }
        }
    }

    // Bắt đầu BFS từ tất cả các cây non
    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        // Cập nhật ngày tối đa
        day = max(day, current.day);

        // Duyệt 4 hướng (trái, phải, lên, xuống)
        for (int i = 0; i < 4; ++i) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            // Kiểm tra xem ô có hợp lệ và chưa được thăm
            if (nx >= 0 && nx < R && ny >= 0 && ny < C && !visited[nx][ny]) {
                if (grid[nx][ny] == 1) {  // Hạt mầm
                    visited[nx][ny] = true;
                    q.push({nx, ny, current.day + 1});
                }
            }
        }
    }

    // Kiểm tra nếu vẫn còn hạt mầm chưa nảy mầm
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                return -1;  // Có hạt mầm không thể nảy mầm
            }
        }
    }

    return day;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int R, C;
        cin >> R >> C;

        vector<vector<int>> grid(R, vector<int>(C));

        // Đọc bảng
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                cin >> grid[i][j];
            }
        }

        // Gọi hàm BFS để tìm số ngày cần thiết
        cout << bfs(R, C, grid) << endl;
    }

    return 0;
}
