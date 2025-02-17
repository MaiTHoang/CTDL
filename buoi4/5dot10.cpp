#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// Hàm chuyển đổi từ hậu tố (Postfix) sang trung tố (Infix)
string postfixToInfix(string exp) {
    stack<string> st;

    // Duyệt từ trái sang phải
    for (char ch : exp) {
        if (isalnum(ch)) {
            // Nếu là toán hạng, đẩy vào stack
            string operand(1, ch);
            st.push(operand);
        } else {
            // Nếu là toán tử, lấy hai toán hạng từ stack
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();

            // Gộp thành biểu thức trung tố với dấu ngoặc bao quanh
            string newExpr = "(" + op1 + ch + op2 + ")";
            st.push(newExpr);
        }
    }

    // Kết quả cuối cùng trong stack
    return st.top();
}

int main() {
    int T;
    cin >> T;
    cin.ignore();  // Loại bỏ ký tự xuống dòng sau khi đọc T

    while (T--) {
        string expression;
        cin >> expression;
        cout << postfixToInfix(expression) << endl;
    }

    return 0;
}
