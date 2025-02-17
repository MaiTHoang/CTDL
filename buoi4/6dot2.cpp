#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

string findSmallestNumber(int N) {
    // Dùng queue để lưu trữ các chuỗi số nhị phân và lưu số dư mod N
    queue<string> q;
    unordered_set<int> visited; // Lưu các số dư đã gặp

    // Bắt đầu với số "9"
    q.push("9");
    visited.insert(9 % N);

    while (!q.empty()) {
        string current = q.front();
        q.pop();

        // Kiểm tra nếu số hiện tại chia hết cho N
        int mod = 0;
        for (char c : current) {
            mod = (mod * 10 + (c - '0')) % N;
        }

        if (mod == 0) {
            return current;
        }

        // Thêm "0" vào và kiểm tra nếu chưa gặp
        if (visited.find(mod * 10 % N) == visited.end()) {
            q.push(current + "0");
            visited.insert(mod * 10 % N);
        }

        // Thêm "9" vào và kiểm tra nếu chưa gặp
        if (visited.find((mod * 10 + 9) % N) == visited.end()) {
            q.push(current + "9");
            visited.insert((mod * 10 + 9) % N);
        }
    }

    return "-1"; // Nếu không tìm thấy (trong trường hợp lý thuyết)
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        cout << findSmallestNumber(N) << endl;
    }

    return 0;
}
