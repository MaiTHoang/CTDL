from collections import deque
import time
import threading
import random

class Sensor:
    def __init__(self, id, print_queue):
        self.id = id
        self.print_queue = print_queue

    def send_data(self):
        while True:
            data == f"Du lieu tu cam bien {self.id}: {random.randint(1,100)}"
            self.print_queue.enqueue(data)
            time.sleep(random.uniform(0.5, 2)) #Gui du lieu ngau nhien

class PrintQueue:
    def __init__(self):
        self.queue = deque()
        self.lock = threading.Lock()

        def enqueue(self, data):
            with self.lock:
                self.queue.append(data)
                print(f"Da them vao hang doi: {data}")
        
        def process_queue(self):
            while True:
                with self.lock:
                    if self.queue:
                        data = self.queue.popleft()
                        print(f"Dang xu ly: {data}")
                    time.sleep(1) #Gia lkap thoi gian xu ly

#Minh hoa
def main():
    print_queue = PrintQueue()

    #Khoi dong thread xu ly hang doi
    processor = threading.Thread(target=print_queue.process_queue, daemon=True)
    processor.start()

    #Tao va khoi dong cac cam bien
    sensors = [Sensor(i, print_queue) for i in range(1,4)]
    for sensor in sensors:
        t = threading.Thread(target=sensor.send_data, daemon=True)
        t.start()

    #Giu chuong trinh chay
    while True:
        time.sleep(10)

if __name__ == "__main__":
    main()