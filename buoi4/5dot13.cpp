#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

// Hàm trả về độ ưu tiên của toán tử
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0; // Không phải toán tử
}

// Hàm tính toán kết quả của 2 toán hạng với một toán tử
int applyOperator(int op1, int op2, char op) {
    switch(op) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / op2;  // Giả sử không có chia cho 0 trong bài toán
        default: return 0;
    }
}

// Hàm tính toán giá trị biểu thức trung tố
int evaluateExpression(const string& exp) {
    stack<int> values;  // Stack để lưu trữ các toán hạng
    stack<char> ops;    // Stack để lưu trữ các toán tử

    for (int i = 0; i < exp.size(); i++) {
        char ch = exp[i];

        // Nếu là một số, chuyển thành int và đẩy vào stack values
        if (isdigit(ch)) {
            int num = 0;
            while (i < exp.size() && isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            values.push(num);
            i--; // Để quay lại dấu ngoặc hoặc toán tử
        }
        // Nếu là dấu ngoặc mở, đẩy vào stack ops
        else if (ch == '(') {
            ops.push(ch);
        }
        // Nếu là dấu ngoặc đóng, thực hiện phép toán cho đến khi gặp dấu ngoặc mở
        else if (ch == ')') {
            while (!ops.empty() && ops.top() != '(') {
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOperator(val1, val2, op));
            }
            ops.pop();  // Loại bỏ dấu ngoặc mở
        }
        // Nếu là toán tử, thực hiện phép toán nếu cần thiết
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (!ops.empty() && precedence(ops.top()) >= precedence(ch)) {
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOperator(val1, val2, op));
            }
            ops.push(ch);
        }
    }

    // Thực hiện các phép toán còn lại trong stack
    while (!ops.empty()) {
        int val2 = values.top(); values.pop();
        int val1 = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOperator(val1, val2, op));
    }

    return values.top();
}

int main() {
    int T;
    cin >> T;
    cin.ignore();  // Loại bỏ ký tự xuống dòng sau khi nhập T

    while (T--) {
        string expression;
        getline(cin, expression);

        // In ra kết quả tính toán của biểu thức
        cout << evaluateExpression(expression) << endl;
    }

    return 0;
}
