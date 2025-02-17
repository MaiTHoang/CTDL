#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Hàm tính diện tích hình chữ nhật lớn nhất
long long maxRectangleArea(const vector<int>& heights) {
    stack<int> st;
    long long maxArea = 0;
    int n = heights.size();

    for (int i = 0; i < n; ++i) {
        // Duyệt qua từng cột, nếu chiều cao giảm, tính diện tích hình chữ nhật
        while (!st.empty() && heights[st.top()] > heights[i]) {
            int h = heights[st.top()];
            st.pop();
            int w = (st.empty()) ? i : i - st.top() - 1;  // Tính chiều rộng
            maxArea = max(maxArea, (long long)h * w); // Cập nhật diện tích lớn nhất
        }
        st.push(i);
    }

    // Xử lý phần còn lại trong stack
    while (!st.empty()) {
        int h = heights[st.top()];
        st.pop();
        int w = (st.empty()) ? n : n - st.top() - 1;
        maxArea = max(maxArea, (long long)h * w);
    }

    return maxArea;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<int> heights(N);

        for (int i = 0; i < N; ++i) {
            cin >> heights[i];
        }

        cout << maxRectangleArea(heights) << endl;
    }

    return 0;
}
