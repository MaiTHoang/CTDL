#include <iostream>
#include <string>

using namespace std;

int minReversalsToBalance(string s) {
    int balance = 0, close_needed = 0;

    for (char ch : s) {
        if (ch == '(') {
            balance++; // Mở ngoặc làm tăng balance
        } else { // ch == ')'
            if (balance > 0) {
                balance--; // Có dấu ( trước đó để đóng
            } else {
                close_needed++; // Dấu ) không có ( trước đó, cần đổi nó thành (
            }
        }
    }

    // Số lần đổi dấu tổng cộng
    return close_needed + (balance / 2);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        string S;
        cin >> S;
        cout << minReversalsToBalance(S) << endl;
    }

    return 0;
}
