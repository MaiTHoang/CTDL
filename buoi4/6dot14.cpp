#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Hàm đệ quy để sinh các số lộc phát
void generateLocPhat(int N, string current, vector<string>& result) {
    if (current.length() > N) return;  // Dừng khi số chữ số vượt quá N
    
    if (!current.empty()) {
        result.push_back(current);  // Thêm số lộc phát vào kết quả nếu nó không rỗng
    }
    
    // Tạo số lộc phát tiếp theo bằng cách thêm chữ số 6 hoặc 8 vào
    generateLocPhat(N, current + "6", result);
    generateLocPhat(N, current + "8", result);
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        vector<string> result;
        
        // Tạo tất cả các số lộc phát có độ dài từ 1 đến N
        generateLocPhat(N, "", result);
        
        // Sắp xếp kết quả theo thứ tự giảm dần
        sort(result.rbegin(), result.rend());
        
        // In ra số lượng số lộc phát
        cout << result.size() << endl;
        
        // In ra các số lộc phát theo thứ tự giảm dần
        for (const string& s : result) {
            cout << s << " ";
        }
        cout << endl;
    }
    
    return 0;
}
