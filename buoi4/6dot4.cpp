#include <iostream>
#include <string>
using namespace std;

// Hàm kiểm tra xem số P có phải là số BDN hay không
bool isBDN(int P) {
    string s = to_string(P); // Chuyển số P thành chuỗi
    for (char c : s) {
        if (c != '0' && c != '1') {
            return false; // Nếu có chữ số khác ngoài '0' và '1', không phải số BDN
        }
    }
    return true;
}

int main() {
    int T;
    cin >> T; // Đọc số lượng test

    while (T--) {
        int N;
        cin >> N; // Đọc giá trị N

        int M = 1; // Bắt đầu thử với M = 1
        while (true) {
            int P = M * N; // Tính P = M * N
            if (isBDN(P)) {
                cout << P << endl; // Nếu P là số BDN, in kết quả và thoát vòng lặp
                break;
            }
            M++; // Nếu không phải, tăng M lên 1 và thử lại
        }
    }

    return 0;
}
