#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

const int dx[] = {0, 0, -1, 1, 0, 0}; // Di chuyển: lên, xuống, trái, phải, trước, sau
const int dy[] = {-1, 1, 0, 0, 0, 0};
const int dz[] = {0, 0, 0, 0, -1, 1};

struct Point {
    int x, y, z, dist;
};

int bfs(int A, int B, int C, vector<vector<vector<char>>>& grid, Point start, Point end) {
    queue<Point> q;
    vector<vector<vector<bool>>> visited(A, vector<vector<bool>>(B, vector<bool>(C, false)));
    
    q.push(start);
    visited[start.x][start.y][start.z] = true;
    
    while (!q.empty()) {
        Point current = q.front();
        q.pop();
        
        // Kiểm tra nếu đã đến đích
        if (current.x == end.x && current.y == end.y && current.z == end.z) {
            return current.dist;
        }
        
        // Duyệt 6 hướng xung quanh
        for (int i = 0; i < 6; ++i) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];
            int nz = current.z + dz[i];
            
            // Kiểm tra nếu ô tiếp theo hợp lệ
            if (nx >= 0 && nx < A && ny >= 0 && ny < B && nz >= 0 && nz < C && 
                !visited[nx][ny][nz] && grid[nx][ny][nz] != '#') {
                visited[nx][ny][nz] = true;
                q.push({nx, ny, nz, current.dist + 1});
            }
        }
    }
    
    // Nếu không thể đến đích
    return -1;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int A, B, C;
        cin >> A >> B >> C;
        
        vector<vector<vector<char>>> grid(A, vector<vector<char>>(B, vector<char>(C)));
        Point start, end;
        
        // Đọc bảng và tìm điểm xuất phát (S) và điểm kết thúc (E)
        for (int i = 0; i < A; ++i) {
            for (int j = 0; j < B; ++j) {
                for (int k = 0; k < C; ++k) {
                    cin >> grid[i][j][k];
                    if (grid[i][j][k] == 'S') {
                        start = {i, j, k, 0};
                    } else if (grid[i][j][k] == 'E') {
                        end = {i, j, k, 0};
                    }
                }
            }
        }
        
        // Tìm đường đi ngắn nhất từ S đến E
        int result = bfs(A, B, C, grid, start, end);
        cout << result << endl;
    }

    return 0;
}
