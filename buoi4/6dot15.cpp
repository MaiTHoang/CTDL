#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <string>

using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

// Hàm tiền xử lý các số nguyên tố 4 chữ số
unordered_set<int> getAllPrimes() {
    unordered_set<int> primes;
    for (int i = 1000; i <= 9999; ++i) {
        if (isPrime(i)) {
            primes.insert(i);
        }
    }
    return primes;
}

// Hàm BFS để tìm số bước ít nhất
int bfs(int S, int T, const unordered_set<int>& primes) {
    if (S == T) return 0; // Nếu đã ở đích, không cần di chuyển
    
    queue<pair<int, int>> q;  // (số hiện tại, số bước)
    unordered_set<int> visited;
    
    q.push({S, 0});
    visited.insert(S);
    
    while (!q.empty()) {
        int current = q.front().first;
        int steps = q.front().second;
        q.pop();
        
        // Kiểm tra các phép dịch chuyển có thể từ current
        string currentStr = to_string(current);
        for (int i = 0; i < 4; ++i) {
            char originalChar = currentStr[i];
            for (char digit = '0'; digit <= '9'; ++digit) {
                if (digit == originalChar) continue;  // Không thay đổi chữ số hiện tại
                
                currentStr[i] = digit;
                int next = stoi(currentStr);
                
                // Nếu next là một số nguyên tố và chưa thăm
                if (primes.count(next) && visited.count(next) == 0) {
                    if (next == T) {
                        return steps + 1;  // Nếu đã tới đích, trả về số bước
                    }
                    q.push({next, steps + 1});
                    visited.insert(next);
                }
            }
            currentStr[i] = originalChar;  // Khôi phục lại chữ số ban đầu
        }
    }
    
    return -1;  // Không tìm thấy đường đi
}

int main() {
    int T;
    cin >> T;
    
    // Tiền xử lý các số nguyên tố có 4 chữ số
    unordered_set<int> primes = getAllPrimes();
    
    while (T--) {
        int S, T;
        cin >> S >> T;
        
        // Tìm số bước ít nhất từ S đến T
        cout << bfs(S, T, primes) << endl;
    }
    
    return 0;
}
