#queue_python.py
from collections import deque

class Queue:
    def __init__(self):
        self.elements = deque() #Su dung deque de luu tru cac phan tu

    def enqueue(self, item):
            self.elements.append(item) #Them phan tu vao cuoi deque
            print(f"Da them {item} vao hang doi.")

    def dequeue(self):
        if not self.is_empty():
            item = self.elements.popleft() #Loai bo phan tu o dau deque
            print(f"Da lay {item} ra khoi hang doi.")

            return item
        else:
             print("Hang doi trong!")
    
    def front(self):
         if not self.is_empty():
            return self.elements[0] #Truy cap phan tu dau tien
         else:
             print("Hang doi trong!")
             return None

    def is_empty(self):
        return len(self.elements) == 0 #Kiem tra xem deque co trong khong
    
    def size(self):
        return len(self.elements) #Tra ve kich thuoc hang doi
    
    def display(self):
        print(f"Hang doi (dau den cuoi): {list(self.elements)}") #In hang doi tu dau den cuoi

#Minh hoa su dung hang doi
if __name__ == '__main__':
    queue = Queue()
    queue.enqueue("Tai lieu 1")
    queue.enqueue("Tai lieu 2")
    queue.enqueue("Tai lieu 3")
    queue.display() #Output: Hang doi (dau den cuoi): ['Tai lieu 1', 'Tai lieu 2', 'Tai lieu 3']

    front_item = queue.front()
    print("Phan tu o dau hang doi: ", front_item) #Output: Phan tu o dau hang doi:  Tai lieu 1

    queue.dequeue()
    queue.display() #Output: Hang doi (dau den cuoi): ['Tai lieu 2', 'Tai lieu 3']

    print("Hang doi co trong khong?", queue.is_empty()) #Output: False