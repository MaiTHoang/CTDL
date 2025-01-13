int median_of_three(vector<int>& arr, int low, int high){
    int mid = low + (high - low) / 2;
    if(arr[mid] < arr[low]) swap(arr[mid], arr[low]);
    if(arr[high] < arr[low]) swap(arr[high], arr[low]);
    if(arr[mid] < arr[high]) swap(arr[mid], arr[high]);
    return mid;
}

int partition_median(vector<int>& arr, int low, int high){
    int pivot = median_of_three(arr, low, high);
    swap(arr[median], arr[high]);
    return partition(arr, low, high);
}

void quickSort_median(vector<int>& arr, int low, int high){
    if(low < high){
        int p = partition_median(arr, low, high);
        quickSort_median(arr, low, p - 1);
        quickSort_median(arr, p + 1, high);
    }
}