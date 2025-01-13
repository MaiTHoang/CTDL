#include<iostream>
#include<vector>
using namespace std;

//Ham tron hai mang con da duoc sap xep
void merge(vector<int>& arr, int left, int mid, int right){
    int n1 = mid - left + 1; //Kich thuoc mang con trai
    int n2 = right - mid; //Kich thuong mang con phai

    //Tao hai mang tam thoi
    vector<int> L(n1), R(n2);

    //Sao chep du lieu vao mang tam L va R
    for(int i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }
    for(int j = 0; j < n2; j++){
        R[j] = arr[mid + 1 + j];
    }

    //Tron hai mang L va R vao arr[left..right]
    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k++] = L[i++];
        }else{
            arr[k++] = R[j++];
        }
    }

    //Copy cac phan tu con lai cua L[] vao arr neu co
    while(i < n1){
        arr[k++] = L[i++];
    }

    //Copy cac phan tu con lai cua R[] vao arr neu co
    while(j < n2){
        arr[k++] = R[j++];
    }
}

//Ham Merge Sort
void mergeSort(vector<int>& arr, int left, int right){
    if(left < right){
        //Tim diem chia de chia mang thanh 2 nua
        int mid = left + (right - left) / 2;

        //Sap xep nua dau va nua sau
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        //Tron hai nua lai
        merge(arr, left, mid, right);
    }
}

int main(){
    vector<int> arr = {5, 2, 9, 1, 5};
    mergeSort(arr, 0, arr.size() - 1);
    cout << "Ket qua sau Merge Sort: ";
    
    for(int x: arr) cout << x << " ";
    cout << endl;
    return 0;
}