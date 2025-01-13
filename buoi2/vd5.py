def partition(arr, low, high):
    i = (low-1)         
    pivot = arr[high]     # Chon pivot la phan tu cuoi cung

    for j in range(low, high):

        if arr[j] <= pivot:
            i = i+1
            arr[i], arr[j] = arr[j], arr[i]
    #Dua pivot ve dung vi tri chinh xac
    arr[i+1], arr[high] = arr[high], arr[i+1]
    return (i+1)

def quick_Sort(arr, low, high):
    if len(arr) == 1:
        return arr
    if low < high:
        pi = partition(arr, low, high)
        quick_Sort(arr, low, pi-1)
        quick_Sort(arr, pi+1, high)

arr = [5, 2, 9, 1, 5, 6]
quick_Sort(arr, 0, len(arr)-1)
print("Ket qua Quick Sort: ", arr) #Output: [1, 2, 5, 5, 6, 9]