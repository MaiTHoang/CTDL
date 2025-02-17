#include <iostream>
#include <stack>
#include <string>
using namespace std;

int longestValidParentheses(const string& s) {
    stack<int> st;
    st.push(-1);  // Đẩy vào một giá trị -1 để hỗ trợ tính toán các trường hợp không có ngoặc mở ban đầu
    int maxLength = 0;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            st.push(i);  // Push chỉ số của dấu ngoặc mở vào stack
        } else {  // Khi gặp dấu ngoặc đóng
            st.pop();  // Pop dấu ngoặc mở gần nhất
            if (st.empty()) {
                st.push(i);  // Nếu stack trống, push chỉ số hiện tại vào stack để tính lại
            } else {
                maxLength = max(maxLength, i - st.top());  // Cập nhật độ dài lớn nhất
            }
        }
    }
    
    return maxLength;
}

int main() {
    int T;
    cin >> T;
    cin.ignore();  // Loại bỏ ký tự xuống dòng sau khi đọc T

    while (T--) {
        string expression;
        cin >> expression;
        cout << longestValidParentheses(expression) << endl;
    }

    return 0;
}
