#include <iostream>
#include <bitset>
#include <cmath> // Thêm thư viện cmath để sử dụng log2
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        
        for (int i = 1; i <= n; ++i) {
            // Tính số bit tối thiểu cần thiết để biểu diễn i
            int bits = floor(log2(i)) + 1; // Số bit cần thiết để biểu diễn i
            cout << bitset<32>(i).to_string().substr(32 - bits) << " "; // In nhị phân của i
        }
        cout << endl;
    }

    return 0;
}
