#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// Hàm tính toán giá trị của biểu thức tiền tố
int evaluatePrefix(const string& exp) {
    stack<int> st;

    // Duyệt từ phải sang trái
    for (int i = exp.length() - 1; i >= 0; i--) {
        char ch = exp[i];
        
        if (isdigit(ch)) {
            // Nếu là toán hạng (số đơn), đẩy vào stack
            st.push(ch - '0');
        } else {
            // Nếu là toán tử, lấy hai toán hạng từ stack
            int op1 = st.top(); st.pop();
            int op2 = st.top(); st.pop();

            // Thực hiện phép toán và đẩy kết quả vào stack
            if (ch == '+') {
                st.push(op1 + op2);
            } else if (ch == '-') {
                st.push(op1 - op2);
            } else if (ch == '*') {
                st.push(op1 * op2);
            } else if (ch == '/') {
                st.push(op1 / op2);  // Chia lấy phần nguyên
            }
        }
    }

    // Kết quả cuối cùng trong stack
    return st.top();
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        string expression;
        cin >> expression;

        // In ra kết quả tính toán của biểu thức tiền tố
        cout << evaluatePrefix(expression) << endl;
    }

    return 0;
}
