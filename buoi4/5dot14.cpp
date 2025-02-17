#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// Hàm giải quyết mỗi biểu thức S
string solve(const string& S) {
    stack<int> st;    // Stack để lưu trữ các số
    string result = "";  // Chuỗi kết quả
    int n = S.length();
    
    // Ta sẽ sử dụng các số từ 1 đến n+1 (vì chúng ta cần thêm một số vào cuối để kết thúc)
    for (int i = 0; i <= n; ++i) {
        // Đẩy số vào stack
        st.push(i + 1);
        
        // Khi gặp 'I' hoặc hết chuỗi, lấy các số ra từ stack
        if (i == n || S[i] == 'I') {
            while (!st.empty()) {
                result += to_string(st.top());
                st.pop();
            }
        }
    }
    
    return result;
}

int main() {
    int T;
    cin >> T;
    cin.ignore();  // Loại bỏ ký tự xuống dòng sau khi đọc T
    
    // Xử lý từng test case
    while (T--) {
        string S;
        cin >> S;  // Đọc chuỗi S
        cout << solve(S) << endl;  // Gọi hàm solve để tính kết quả
    }

    return 0;
}
