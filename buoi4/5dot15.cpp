#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Hàm tìm phần tử lớn hơn tiếp theo cho mỗi phần tử trong mảng
vector<int> findNextGreaterElement(const vector<int>& A, int n) {
    stack<int> st;
    vector<int> nge(n, -1);  // Kết quả phần tử lớn hơn tiếp theo, mặc định là -1
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && st.top() <= A[i]) {
            st.pop();
        }
        if (!st.empty()) {
            nge[i] = st.top();
        }
        st.push(A[i]);
    }
    return nge;
}

// Hàm tìm phần tử nhỏ hơn tiếp theo cho mỗi phần tử trong mảng
vector<int> findRightSmallerElement(const vector<int>& A, const vector<int>& nge, int n) {
    stack<int> st;
    vector<int> rse(n, -1);  // Kết quả phần tử nhỏ hơn tiếp theo, mặc định là -1
    for (int i = 0; i < n; ++i) {
        // Chỉ tìm phần tử nhỏ hơn tiếp theo nếu có phần tử lớn hơn tiếp theo
        if (nge[i] != -1) {
            while (!st.empty() && st.top() >= A[i]) {
                st.pop();
            }
            if (!st.empty()) {
                rse[i] = st.top();
            }
        }
        st.push(A[i]);
    }
    return rse;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        vector<int> A(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        
        // Tìm Next Greater Element cho mỗi phần tử
        vector<int> nge = findNextGreaterElement(A, n);
        
        // Tìm Right Smaller Element cho mỗi phần tử
        vector<int> rse = findRightSmallerElement(A, nge, n);
        
        // In kết quả cho mỗi test case
        for (int i = 0; i < n; ++i) {
            cout << rse[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
