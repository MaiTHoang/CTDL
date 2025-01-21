#stack_python.py
import sys
class Stack:
    def __init__(self):
        self.elements = [] #Su dung danh sach de luu tru cac phan tu

    def isEmpty(self):
        return self.elements == [] #Kiem tra xem ngan xep co rong hay khong

    def push(self, item):
        self.elements.append(item) #Them phan tu vao cuoi danh sach
        print(f"Da them {item} vao ngan xep")
    
    def pop(self):
        if not self.isEmpty():
            item = self.elements.pop() #Loai bo phan tu cuoi cung
            print(f"Da lay {item} ra khoi ngan xep")
            return item
        else:
            print("Ngan xep trong!")
            return None
    
    def peek(self):
        if not self.isEmpty():
            return self.elements[-1] #Lay phan tu cuoi cung
        else:
            print("Ngan xep trong!")
            return None

    def size(self):
        return len(self.elements) #Tra ve kich thuoc ngan xep 
    
    def display(self):
        print("Ngan xep (dinh den day): ", self.elements[::-1])

if __name__ == '__main__':
    stack = Stack()
    stack.push("Sach A")
    stack.push("Sach B")
    stack.push("Sach C")
    stack.display()

    top_item = stack.peek()
    print("Phan tu dinh cua ngan xep: ", top_item) #Output: Sach C

    stack.pop()
    stack.display() #Output: Ngan xep (dinh den day): ['Sach B', 'Sach A']

    print("Ngan xep co trong khong? ", stack.isEmpty()) #Output: False
