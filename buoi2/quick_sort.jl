function partition!(arr, low::Int, high::Int)
    pivot = arr[high] #Chon pivot la phan tu cuoi
    i = low - 1 #Chi so nho hon pivot
    for j in low:high-1
        if arr[j] < pivot
            i += 1
            arr[i], arr[j] = arr[j], arr[i] #Hoan doi arr[i] va arr[j]
        end
    end
    arr[i+1], arr[high] = arr[high], arr[i+1] #Hoan doi pivot vao vi tri dung
    return i+1 #Vi tri cua pivot
end

function quick_sort!(arr, low::Int, high::Int)
    if low < high
        pi = partition!(arr, low, high) #tim vi tri pivot
        quick_sort!(arr, low, pi-1) #Sap xep phan ben trai pivot
        quick_sort!(arr, pi+1, high) #Sap xep phan ben phai pivot
    end
end

#Test
arr=[5, 2, 9, 1, 5, 6]
quick_sort!(arr, 1, length(arr)) #Julia danh chi so tu 1
println("Ket qua Quick Sort: ", arr)