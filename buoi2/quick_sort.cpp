#include<iostream>
#include<vector>
using namespace std;    

//Ham Partition: Dua pivot ve vi tri dung va sap xep cac phan tu
int partition(vector<int>& arr, int low, int high){
    int pivot = arr[high]; //Chon phan tu cuoi lam pivot
    int i = low - 1; //Index cua phan tu nho hon pivot

    for(int j = low; j < high; j++){
        //Neu phan tu hien tai nho hon pivot
        if(arr[j] < pivot){
            i++; //Tang index cua phan tu nho hon pivot
            swap(arr[i], arr[j]); //Doi cho phan tu arr[i] va arr[j]
        }
    }

    swap(arr[i + 1], arr[high]); //Doi cho pivot va phan tu arr[i + 1]
    return i + 1; //Tra ve vi tri cua pivot
}

//Ham Quick Sort
void quickSort(vector<int>& arr, int low, int high){
    if(low < high){
        //Phan chia mang va lay pivot
        int pi = partition(arr, low, high);

        //Sap xep hai phan tu con lai
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main()
{
    vector<int> arr = {5, 2, 9, 1, 5, 6};
    quickSort(arr, 0, arr.size() - 1);
    cout << "Ket qua sau Quick Sort: ";
    for(int x: arr) cout << x << " ";
    cout << endl;
    return 0;
}