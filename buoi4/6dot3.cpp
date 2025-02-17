#include <iostream>
using namespace std;

// Hàm đệ quy để đếm số BDN nhỏ hơn N
void countBDN(int N, int current, int& count) {
    if (current >= N) {
        return;  // Dừng lại nếu số đã vượt qua N
    }
    count++;  // Đếm số BDN này

    // Tạo số tiếp theo bằng cách thêm '0' và '1'
    countBDN(N, current * 10, count);     // Thêm '0'
    countBDN(N, current * 10 + 1, count); // Thêm '1'
}

int main() {
    int T;
    cin >> T;  // Đọc số lượng test

    while (T--) {
        int N;
        cin >> N;  // Đọc giá trị N

        int count = 0;
        countBDN(N, 1, count);  // Bắt đầu đếm từ số 1

        cout << count << endl;  // In ra kết quả
    }

    return 0;
}
