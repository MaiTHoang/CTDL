#include <iostream>
#include <stack>
#include <string>
using namespace std;

int longestValidParentheses(string s) {
    stack<int> st;
    st.push(-1);  // Đẩy vào chỉ số -1 để xử lý trường hợp đầu tiên.
    int maxLength = 0;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            // Đẩy chỉ số của dấu '(' vào stack
            st.push(i);
        } else {
            // Xử lý dấu ')'
            st.pop(); // Pop dấu '(' ra khỏi stack

            // Nếu stack không rỗng, tính độ dài của dãy ngoặc đúng
            if (!st.empty()) {
                maxLength = max(maxLength, i - st.top());
            } else {
                // Nếu stack rỗng, đẩy chỉ số hiện tại vào stack để đánh dấu vị trí mở đầu của dãy ngoặc đúng sau này
                st.push(i);
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
        string s;
        cin >> s;
        cout << longestValidParentheses(s) << endl;
    }

    return 0;
}