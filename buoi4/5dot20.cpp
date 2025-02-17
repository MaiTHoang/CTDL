#include <iostream>
#include <stack>
#include <string>
using namespace std;

string decodeString(const string& s) {
    stack<int> countStack;
    stack<string> stringStack;
    string currentString = "";
    int currentCount = 0;

    for (char ch : s) {
        if (isdigit(ch)) {
            // Nếu là chữ số, ta xác định số lần lặp (có thể là nhiều chữ số)
            currentCount = currentCount * 10 + (ch - '0');
        } else if (ch == '[') {
            // Khi gặp '[', ta lưu lại xâu hiện tại và số lần lặp vào stack
            countStack.push(currentCount);
            stringStack.push(currentString);
            currentString = "";
            currentCount = 0;
        } else if (ch == ']') {
            // Khi gặp ']', ta giải mã xâu con
            string prevString = stringStack.top();
            stringStack.pop();
            int repeatCount = countStack.top();
            countStack.pop();

            // Nhân xâu con với số lần lặp
            for (int i = 0; i < repeatCount; ++i) {
                prevString += currentString;
            }

            currentString = prevString;
        } else {
            // Nếu là ký tự thường, ta thêm vào xâu hiện tại
            currentString += ch;
        }
    }

    return currentString;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        string encodedString;
        cin >> encodedString;
        cout << decodeString(encodedString) << endl;
    }

    return 0;
}
