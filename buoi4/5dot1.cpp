#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Hàm kiểm tra biểu thức có chứa dấu ngoặc dư thừa hay không
bool hasRedundantParentheses(const string& expr) {
    stack<char> st;

    for (char ch : expr) {
        if (ch == ')') {
            // Kiểm tra nếu stack rỗng (tránh lỗi)
            if (st.empty()) return false;

            char top = st.top();
            st.pop();
            
            bool isRedundant = true; // Giả định là dư thừa
            
            // Kiểm tra xem giữa cặp dấu ngoặc có toán tử hay không
            while (!st.empty() && top != '(') {
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    isRedundant = false; // Có toán tử => không dư thừa
                }
                top = st.top();
                st.pop();
            }

            // Nếu stack rỗng sau khi pop '(' thì biểu thức không hợp lệ
            if (st.empty() && top != '(') return false;

            // Nếu gặp một cặp () mà không chứa toán tử => dư thừa
            if (isRedundant) return true;
        } 
        else {
            st.push(ch); // Đẩy ký tự vào stack
        }
    }

    return false; // Không có dấu ngoặc dư thừa
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Loại bỏ ký tự xuống dòng sau khi nhập T

    while (T--) {
        string expr;
        getline(cin, expr); // Đọc cả dòng để đảm bảo lấy hết biểu thức

        if (hasRedundantParentheses(expr)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
