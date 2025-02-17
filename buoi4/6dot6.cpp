#include <iostream>
#include <cmath>
using namespace std;

int min_operations(int N) {
    int steps = 0;
    
    while (N > 1) {
        // Kiểm tra xem N có thể chia cho bất kỳ số nào không
        bool found = false;
        
        // Thử từ 2 đến sqrt(N) để tìm một cặp u, v sao cho u * v = N
        for (int i = 2; i <= sqrt(N); ++i) {
            if (N % i == 0) {
                // Nếu tìm được cặp u, v, ta chọn max(u, v)
                N = max(i, N / i);
                steps++;
                found = true;
                break;
            }
        }
        
        if (!found) {
            // Nếu không thể tìm thấy u, v, ta dùng thao tác (a)
            N--;
            steps++;
        }
    }
    
    return steps;
}

int main() {
    int T;
    cin >> T;  // Số lượng test cases

    while (T--) {
        int N;
        cin >> N;  // Đọc số N
        
        // Tính số thao tác ít nhất để biến N thành 1
        cout << min_operations(N) << endl;
    }

    return 0;
}
