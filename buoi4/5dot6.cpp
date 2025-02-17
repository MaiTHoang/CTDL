#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// Hàm xác định độ ưu tiên của toán tử
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Hàm chuyển đổi trung tố sang hậu tố
string infixToPostfix(string exp) {
    stack<char> operators;
    string postfix = "";

    for (char ch : exp) {
        if (isalnum(ch)) { 
            postfix += ch; // Nếu là toán hạng, thêm vào kết quả
        } 
        else if (ch == '(') {
            operators.push(ch); // Nếu là dấu mở ngoặc, đẩy vào stack
        } 
        else if (ch == ')') {
            // Nếu là dấu đóng ngoặc, lấy toán tử ra đến khi gặp '('
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Loại bỏ '(' khỏi stack
        } 
        else { 
            // Nếu là toán tử, xử lý độ ưu tiên
            while (!operators.empty() && precedence(operators.top()) >= precedence(ch)) {
                if (ch == '^' && operators.top() == '^') break; // Lũy thừa có ưu tiên phải sang trái
                postfix += operators.top();
                operators.pop();
            }
            operators.push(ch);
        }
    }

    // Đưa các toán tử còn lại vào kết quả
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

int main() {
    int T;
    cin >> T;
    cin.ignore();

    while (T--) {
        string expression;
        cin >> expression;
        cout << infixToPostfix(expression) << endl;
    }

    return 0;
}
