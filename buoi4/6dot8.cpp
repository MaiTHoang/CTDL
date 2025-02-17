#include <iostream>
#include <set>
#include <string>
using namespace std;

// Hàm kiểm tra số K có thỏa mãn điều kiện hay không
bool isValid(int K) {
    string str = to_string(K);
    set<char> digits;  // Sử dụng set để đảm bảo các chữ số không bị lặp lại

    // Kiểm tra tất cả các chữ số trong số K
    for (char c : str) {
        if (c > '5')  // Kiểm tra chữ số có lớn hơn 5 không
            return false;
        if (digits.count(c))  // Kiểm tra chữ số có lặp lại không
            return false;
        digits.insert(c);
    }
    return true;
}

int main() {
    int T;
    cin >> T;  // Đọc số lượng test case
    
    while (T--) {
        int L, R;
        cin >> L >> R;  // Đọc L và R
        
        int count = 0;
        for (int K = L; K <= R; ++K) {
            if (isValid(K)) {
                count++;
            }
        }
        
        cout << count << endl;  // In kết quả cho mỗi test case
    }

    return 0;
}
