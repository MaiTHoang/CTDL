#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void calculateStockMomentum(int N, const vector<int>& prices) {
    stack<int> st;  // Stack để lưu chỉ số các ngày
    vector<int> result(N);

    for (int i = 0; i < N; ++i) {
        // Tính nhịp chứng khoán cho ngày i
        while (!st.empty() && prices[st.top()] <= prices[i]) {
            st.pop();  // Xóa các ngày có giá nhỏ hơn hoặc bằng giá ngày i
        }

        // Nếu stack rỗng, nghĩa là không có ngày nào có giá nhỏ hơn hoặc bằng giá ngày i
        // Nhịp chứng khoán của ngày i là i + 1
        result[i] = (st.empty()) ? i + 1 : i - st.top();
        
        // Thêm ngày i vào stack
        st.push(i);
    }

    // In ra kết quả
    for (int i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<int> prices(N);

        for (int i = 0; i < N; ++i) {
            cin >> prices[i];
        }

        calculateStockMomentum(N, prices);
    }

    return 0;
}
