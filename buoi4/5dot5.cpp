#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Hàm chuẩn hóa biểu thức bằng cách loại bỏ dấu ngoặc dư thừa
string normalize(string expr) {
    stack<int> s;
    string result = "";
    
    for (size_t i = 0; i < expr.size(); i++) {
        char ch = expr[i];

        if (ch == '(') {
            // Kiểm tra nếu có ký tự trước đó và không phải dấu mở ngoặc
            if (i > 0 && expr[i - 1] != '(' && expr[i - 1] != ')') {
                result += ch; // Giữ lại dấu ngoặc nếu cần thiết
            }
            s.push(result.size()); // Lưu vị trí dấu ngoặc
        } 
        else if (ch == ')') {
            // Nếu trước đó là toán hạng, giữ lại ngoặc đóng
            if (!s.empty()) {
                s.pop();
            } else {
                result += ch; // Giữ lại nếu nó là ngoặc đóng hợp lệ
            }
        } 
        else {
            result += ch; // Nếu là toán hạng, giữ nguyên
        }
    }
    
    return result;
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Xóa ký tự xuống dòng

    while (T--) {
        string P1, P2;
        getline(cin, P1);
        getline(cin, P2);

        if (normalize(P1) == normalize(P2)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
