#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    queue<string> queue;

    //Enqueue cac phan tu vao hang doi
    queue.push("Tai lieu 1");
    cout << "Da them 'Tai lieu 1' vao hang doi." << endl;
    queue.push("Tai lieu 2");
    cout << "Da them 'Tai lieu 2' vao hang doi." << endl;
    queue.push("Tai lieu 3");
    cout << "Da them 'Tai lieu 3' vao hang doi." << endl;

    //Hien thi phan tu o dau hang doi
    cout << "Phan tu o dau hang doi: " << queue.front() << endl;

    //Dequeue phan tu khoi hang doi
    queue.pop();
    cout << "Da lay phan tu ra khoi hang doi." << endl;

    //Hien thi phan tu o dau hang doi sau khi dequeue
    cout << "Phan tu o dau hang doi sau khi dequeue: " << queue.front() << endl; //Output: Tai lieu 2

    //Kiem tra hang doi co trong hay khong
    if(queue.empty()) {
        cout << "Hang doi trong." << endl;
    } else {
        cout << "Hang doi khong trong." << endl;
    }

    return 0;
}