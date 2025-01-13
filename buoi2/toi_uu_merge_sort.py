def merge_sort_hybrid(arr, left, right):
    if right - left +1 < 10
        insertion_sort(arr, left, right)
    elif left < right:
        mid = (left + right) // 2
        merge_sort_hybrid(arr, left, mid)
        merge_sort_hybrid(arr, mid + 1, right)
        merge(arr, left, mid, right)