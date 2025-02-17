#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
#include <string>
#include <cmath>
using namespace std;

// Kiểm tra xem hai xâu có khác nhau đúng 1 ký tự hay không
bool isOneCharDifference(const string &a, const string &b) {
    int diff = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            diff++;
            if (diff > 1) return false;
        }
    }
    return diff == 1;
}

// Hàm tìm khoảng cách ngắn nhất từ s đến t
int findShortestPath(const string &s, const string &t, const vector<string> &S) {
    if (s == t) return 0;
    
    unordered_set<string> visited;
    queue<pair<string, int>> q;
    
    q.push({s, 0});
    visited.insert(s);
    
    while (!q.empty()) {
        string current = q.front().first;
        int steps = q.front().second;
        q.pop();
        
        for (const string &word : S) {
            if (visited.find(word) == visited.end() && isOneCharDifference(current, word)) {
                if (word == t) {
                    return steps + 1;
                }
                visited.insert(word);
                q.push({word, steps + 1});
            }
        }
    }
    
    return -1;  // Nếu không có đường đi từ s đến t
}

int main() {
    int T;
    cin >> T;  // Đọc số lượng test case
    
    while (T--) {
        int n;
        string s, t;
        cin >> n >> s >> t;  // Đọc số lượng từ và xâu s, t
        
        vector<string> S(n);
        for (int i = 0; i < n; ++i) {
            cin >> S[i];  // Đọc các xâu từ
        }
        
        // Tính khoảng cách ngắn nhất từ s đến t
        int result = findShortestPath(s, t, S);
        cout << result << endl;
    }

    return 0;
}
