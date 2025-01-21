class Robot:
    def __init__(self):
        self.position = [0, 0] #[x, y]
        self.direction = "N" #N, S, E, W
        self.history = [] #Ngan xep luu tru cac lenh

    def move_forward(self):
        if self.direction == 'N':
            self.position[1] += 1
        elif self.direction == 'E':
            self.position[0] += 1
        elif self.direction == 'S':
            self.position[1] -= 1
        elif self.direction == 'W':
            self.position[0] -= 1
        self.history.append("forward")
        print(f"Dang tien len. Vi tri hien tai: {self.position}, Huong: {self.direction}")

    def move_backward(self):
        if self.direction == 'N':
            self.position[1] -= 1
        elif self.direction == 'E':
            self.position[0] -= 1
        elif self.direction == 'S':
            self.position[1] += 1
        elif self.direction == 'W':
            self.position[0] += 1
        self.history.append("backward")
        print(f"Dang lui lai. Vi tri hien tai: {self.position}, Huong: {self.direction}")
        
    def turn_left(self):
        dirs = ['N', 'W', 'S', 'E']
        idx = dirs.index(self.direction)
        self.direction = dirs[(idx+1) % 4]
        self.history.append("left")
        print(f"Dang quay trai. Vi tri hien tai: {self.position}, Huong: {self.direction}, Huong: {self.direction}")

    def turn_right(self):
        dirs = ['N', 'E', 'S', 'W']
        idx = dirs.index(self.direction)
        self.direction = dirs[(idx+1) % 4]
        self.history.append("right")
        print(f"Dang quay phai. Vi tri hien tai: {self.position}, Huong: {self.direction}")

    def undo(self):
        if not self.history:
            print("Khong co lenh nao de hoan tac")
            return
        last_command = self.history.pop()
        print(f"Hoan tac lenh: {last_command}")
        if last_command == "forward":
            self.move_backward()
        elif last_command == "backward":
            self.move_forward()
        elif last_command == "left":
            self.turn_right()
        elif last_command == "right":
            self.turn_left()
            
    def display_status(self):
        print(f"Vi tri: {self.position}, Huong: {self.direction}")

#Minh hoa
if __name__ == "__main__":
    robot = Robot()
    robot.move_forward()
    robot.turn_left()
    robot.move_forward()
    robot.turn_right()
    robot.move_forward()
    robot.display_status()

    print("\n Thuc hien Undo: ")
    robot.undo()
    robot.undo()
    robot.display_status()