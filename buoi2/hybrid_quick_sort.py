def insertion_sort(arr, low, high):
    for i in range(low + 1, high + 1):
        key = arr[i]
        j = i - 1
        while j >= low and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def quick_sort_hybrid(arr, low, high):
    while low < high:
        if high - low < 10:
            insertion_sort(arr, low, high)
            break
        else:
            p = partition(arr, low, high)
            if p - low < high - p:
                quick_sort_hybrid(arr, low, p - 1)
                low = p + 1
            else:
                quick_sort_hybrid(arr, p + 1, high)
                high = p - 1