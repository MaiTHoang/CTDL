def type_text(self, new_text):
    self.undo_stack.append(self.text)
    self.text += new_text
    self.reedo_stack.clear()
    print(f"Da go: {new_text}")
    self.display()

def undo(self):
    if self.undo_stack:
        self.reedo_stack.append(self.text)
        self.text = self.undo_stack.pop()
        print("Da undo")
        self.display()
    else:
        print("Khong co hanh dong nao de hoan tac.")

def redo(self):
    if self.reedo_stack:
        self.undo_stack.append(self.text)
        self.text = self.reedo_stack.pop()
        print("Da lam lai hanh dong")
        self.display()
    else:
        print("Khong co hanh dong nao de thuc hien lai.")

def display(self):
    print(f"Van ban hien tai: {self.text}")