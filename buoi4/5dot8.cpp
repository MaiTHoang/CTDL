#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// Hàm chuyển đổi từ tiền tố (Prefix) sang hậu tố (Postfix)
string prefixToPostfix(string exp) {
    stack<string> st;

    // Duyệt ngược từ phải sang trái
    for (int i = exp.length() - 1; i >= 0; i--) {
        char ch = exp[i];

        if (isalnum(ch)) { 
            // Nếu là toán hạng, đẩy vào stack
            string operand(1, ch);
            st.push(operand);
        } 
        else { 
            // Nếu là toán tử, lấy hai toán hạng từ stack
            if (st.size() < 2) return "INVALID"; // Tránh lỗi nếu thiếu toán hạng
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();

            // Gộp thành biểu thức hậu tố
            string newExpr = op1 + op2 + ch;
            st.push(newExpr);
        }
    }

    // Kết quả cuối cùng trong stack
    return st.top();
}

int main() {
    int T;
    cin >> T;
    cin.ignore();

    while (T--) {
        string expression;
        cin >> expression;
        cout << prefixToPostfix(expression) << endl;
    }

    return 0;
}
