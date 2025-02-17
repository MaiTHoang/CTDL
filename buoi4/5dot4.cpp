#include <iostream>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// Lưu vị trí của các dấu ngoặc
vector<pair<int, int>> brackets;
set<string> results;
string expression;

// Sinh tất cả các cách xóa dấu ngoặc hợp lệ
void generate(int index, vector<bool>& removed) {
    if (index == brackets.size()) {
        string modified = "";
        for (size_t i = 0; i < expression.size(); i++) {
            bool skip = false;
            for (size_t j = 0; j < brackets.size(); j++) {
                if (removed[j] && (i == brackets[j].first || i == brackets[j].second)) {
                    skip = true;
                    break;
                }
            }
            if (!skip) modified += expression[i];
        }
        results.insert(modified);
        return;
    }

    // Không xóa cặp ngoặc này
    generate(index + 1, removed);

    // Xóa cặp ngoặc này
    removed[index] = true;
    generate(index + 1, removed);
    removed[index] = false;
}

int main() {
    cin >> expression;
    
    stack<int> s;
    // Xác định các cặp dấu ngoặc
    for (size_t i = 0; i < expression.size(); i++) {
        if (expression[i] == '(') {
            s.push(i);
        } else if (expression[i] == ')') {
            if (!s.empty()) {
                brackets.push_back({s.top(), i});
                s.pop();
            }
        }
    }

    vector<bool> removed(brackets.size(), false);
    generate(0, removed);

    results.erase(expression); // Loại bỏ biểu thức ban đầu

    for (const string& res : results) {
        cout << res << endl;
    }

    return 0;
}
