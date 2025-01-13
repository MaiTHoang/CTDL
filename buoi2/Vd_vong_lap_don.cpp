#include<iostream>
using namespace std;

void printNumbers(int n) {
    for (int i = 1; i <= n; i++) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    printNumbers(5); //Output: 1 2 3 4 5
    return 0;
}