import random

def randomized_partition(arr, low, high):
    pivot_index = random.randint(low, high)
    arr[pivot_index], arr[high] = arr[high], arr[pivot_index]
    return partition(arr, low, high)

def quick_sort_randomized(arr, low, high):
    if low < high:
        pivot = randomized_partition(arr, low, high)
        quick_sort_randomized(arr, low, pivot - 1)
        quick_sort_randomized(arr, pivot + 1, high)
