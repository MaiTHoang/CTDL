from collections import deque

def max_sliding_window(nums, k):
    if not nums or k == 0:
        return []
    
    result = []
    dq = deque()
    
    for i in range(len(nums)):
        # Loại bỏ phần tử ngoài phạm vi cửa sổ k
        if dq and dq[0] < i - k + 1:
            dq.popleft()
        
        # Loại bỏ phần tử nhỏ hơn nums[i] từ cuối hàng đợi
        while dq and nums[dq[-1]] < nums[i]:
            dq.pop()
        
        # Thêm chỉ số hiện tại vào hàng đợi
        dq.append(i)
        
        # Lấy giá trị lớn nhất từ cửa sổ hiện tại
        if i >= k - 1:
            max_value = nums[dq[0]]
            print("Giá trị lớn nhất mỗi cửa sổ:", max_value)  # In ra từng giá trị lớn nhất mỗi cửa sổ
            result.append(max_value)
    
    return result

num_list = [3, 4, 5, 1, -44, 5, 10, 12, 33, 1]
k = 3
max_values = max_sliding_window(num_list, k)
print("Chuỗi giá trị lớn nhất:", max_values)
