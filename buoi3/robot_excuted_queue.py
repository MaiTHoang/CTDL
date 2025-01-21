from collections import deque
import threading
import time

class CommandQueue:
    def __init__(self):
        self.queue = deque()
        self.lock = threading.Lock()
    
    def enqueue(self, command):
        with self.lock:
            self.queue.append(command)
            print(f"Da them lenh vao hang doi: {command}")

    def dequeue(self):
        with self.lock:
            if self.queue:
                command = self.queue.popleft()
                print(f"Dang thuc thi lenh: {command}")
                return command
            else:
                return None
            
    def is_empty(self):
        with self.lock:
            return len(self.queue) == 0
    
class RobotController:
    def __init__(self, command_queue):
        self.command_queue = command_queue
        self.thread = threading.Thread(target = self.process_commands, daemon = True)
        self.thread.start()
    
    def process_commands(self):
        while True:
            command = self.command_queue.dequeue()
            if command == "forward":
                print("Robot dang tien len.")
            elif command == "backward":
                print("Robot dang lui lai.")
            elif command == "left":
                print("Robot dang quay trai.")
            elif command == "right":
                print("Robot dang quay phai.")
            elif command == "stop":
                print("Robot da dung lai.")
            else:
                print(f"Lenh khong hop le: {command}")
            #Gia lap thoi gian thuc thi lenh
            time.sleep(2)

#Minh hoa
def main():
    command_queue = CommandQueue()
    controller = RobotController(command_queue)

    #Theem cac lenh vao hang doi
    commands = ["forward", "left", "right", "forward", "backward", "stop"]
    for cmd in commands:
        command_queue.enqueue(cmd)
        time.sleep(0.5) #Gia lap thoi gian nhan lenh

    #Giu chuong trinh chay de xem  qua trinh thuc thi lenh
    time.sleep(15)

if __name__ == "__main__":
    main()