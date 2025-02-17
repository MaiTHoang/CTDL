#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;  // Số lượng test cases

    while (T--) {
        int S, T;
        cin >> S >> T;  // Đọc cặp số S và T
        
        int steps = 0;  // Đếm số bước thực hiện
        
        // Dịch chuyển từ T về S
        while (T > S) {
            if (T % 2 == 0) {
                T /= 2;  // Nếu T chẵn, chia T cho 2
            } else {
                T += 1;  // Nếu T lẻ, cộng 1 (nghịch đảo của thao tác trừ 1)
            }
            steps++;  // Tăng số bước thực hiện
        }
        
        // Sau khi T <= S, ta chỉ cần cộng thêm số lần trừ 1 để S trở thành T
        steps += S - T;  // Chuyển từ T về S bằng cách trừ 1 (S-T lần)

        cout << steps << endl;  // In ra kết quả
    }

    return 0;
}
