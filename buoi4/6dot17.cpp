#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

struct Position {
    int x, y;
};

int bfs(Position start, Position end) {
    // Các hướng di chuyển của quân mã
    int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
    
    // Mảng visited để kiểm tra ô đã thăm
    bool visited[9][9] = {false};
    queue<pair<Position, int>> q;  // Pair (Position, steps)
    
    q.push({start, 0});
    visited[start.x][start.y] = true;
    
    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        
        Position curPos = current.first;
        int steps = current.second;
        
        // Nếu đã đến đích
        if (curPos.x == end.x && curPos.y == end.y) {
            return steps;
        }
        
        // Kiểm tra các bước di chuyển tiếp theo
        for (int i = 0; i < 8; i++) {
            int nx = curPos.x + dx[i];
            int ny = curPos.y + dy[i];
            
            // Nếu vị trí mới hợp lệ và chưa được thăm
            if (nx >= 1 && nx <= 8 && ny >= 1 && ny <= 8 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({{nx, ny}, steps + 1});
            }
        }
    }
    
    return -1;  // Không thể đến đích
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        string startStr, endStr;
        cin >> startStr >> endStr;
        
        // Chuyển đổi vị trí xuất phát
        Position start = {startStr[1] - '0', startStr[0] - 'a' + 1};
        // Chuyển đổi vị trí đích
        Position end = {endStr[1] - '0', endStr[0] - 'a' + 1};
        
        // Tính số bước ít nhất
        cout << bfs(start, end) << endl;
    }

    return 0;
}
