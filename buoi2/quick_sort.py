def partition(arr, low, high):
    i = low - 1 #Chi so nho hon pivot
    pivot = arr[high] #Chon pivot la phan tu cuoi cung
    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i] #Hoan doi arr[i] va arr[j]
    arr[i + 1], arr[high] = arr[high], arr[i + 1] #Hoan doi pivot vao vi tri dung
    return i + 1

def quick_sort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high) #Tim vi tri pivot
        quick_sort(arr, low, pi - 1) #Sap xep phan ben trai pivot
        quick_sort(arr, pi + 1, high) #Sap xep phan ben phai pivot

if __name__ == '__main__':
    arr = [10, 7, 8, 9, 1, 5]
    n = len(arr)
    quick_sort(arr, 0, n - 1)
    print("Sorted array is:", arr)