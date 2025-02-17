#include <iostream>
#include <stack>
#include <string>

using namespace std;

string removeBrackets(string P) {
    stack<int> signStack; // Stack lưu trạng thái dấu
    string result = "";
    int sign = 1; // Dấu hiện tại: 1 là '+', -1 là '-'

    signStack.push(1); // Mặc định trạng thái dấu ngoài cùng là '+'

    for (size_t i = 0; i < P.length(); i++) {
        char ch = P[i];

        if (ch == '(') {
            // Đẩy dấu hiện tại vào stack trước khi vào ngoặc
            signStack.push(sign);
        } 
        else if (ch == ')') {
            // Ra khỏi dấu ngoặc, quay về trạng thái dấu trước đó
            signStack.pop();
        } 
        else if (ch == '+' || ch == '-') {
            // Xác định dấu thực tế
            if (signStack.top() == -1) {
                result += (ch == '+') ? '-' : '+'; // Đổi dấu nếu trong dấu ngoặc bị phủ định
            } else {
                result += ch; // Giữ nguyên dấu
            }
        } 
        else {
            result += ch; // Toán hạng giữ nguyên
        }
    }

    return result;
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Xóa ký tự xuống dòng sau khi nhập T

    while (T--) {
        string P;
        getline(cin, P);
        cout << removeBrackets(P) << endl;
    }

    return 0;
}
