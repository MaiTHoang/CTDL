#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

void findNextGreaterFrequency(int n, const vector<int>& arr) {
    // Map lưu trữ số lần xuất hiện của mỗi phần tử trong mảng
    unordered_map<int, int> freq;
    
    // Đếm số lần xuất hiện của từng phần tử
    for (int i = 0; i < n; ++i) {
        freq[arr[i]]++;
    }
    
    // Stack lưu trữ các phần tử chưa tìm thấy phần tử phù hợp
    stack<int> st;
    
    // Mảng kết quả
    vector<int> ans(n, -1);
    
    // Duyệt từ phải sang trái
    for (int i = n - 1; i >= 0; --i) {
        // Nếu stack rỗng, hoặc số lần xuất hiện của phần tử hiện tại
        // lớn hơn hoặc bằng số lần xuất hiện của phần tử trên đỉnh stack,
        // thì ta đẩy phần tử vào stack.
        while (!st.empty() && freq[arr[i]] >= freq[st.top()]) {
            st.pop();
        }
        
        // Nếu stack không rỗng, phần tử trên đỉnh stack là phần tử có
        // số lần xuất hiện lớn hơn phần tử hiện tại.
        if (!st.empty()) {
            ans[i] = st.top();
        }
        
        // Đẩy phần tử hiện tại vào stack
        st.push(arr[i]);
    }
    
    // In kết quả
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        
        findNextGreaterFrequency(n, arr);
    }
    
    return 0;
}
