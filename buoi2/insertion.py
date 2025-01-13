def insertion_sort(arr):
    n= len(arr)
    for i in range(1, n):
        key = arr[i]
        j = i-1
        #Di chuyen cac phan tu lon hon key sang phai
        while j >= 0 and key < arr[j]:
            arr[j+1] = arr[j]
            j -= 1
        #Chen key vao dung vi tri dung
        arr[j+1] = key

if __name__ == '__main__':
    arr = [5, 2, 9, 1, 5]
    insertion_sort(arr)
    print ("Sorted array is:", arr)