# Stack- Data Structure

# List hota h jo FILO ko follow krta h
# FIRST IN LAST OUT
# ________________
# | 5, 6, 7, 2, 10  aisa design hota h stack ka
# ----------------

# One way movement hota h, jo pehle jayega vo last me bahar ayega


class Stack:
    def __init__(self):
        self.stack = []

    # To add element(data) to stack
    def push(self, data):
        # if not present in stack
        if data not in self.stack:
            self.stack.append(data)
            return True
        return False
    

    # To peek Top element
    def peek(self):
        # Agar stack khali na ho
        if len(self.stack) > 0:
            return self.stack[-1]
        print('No Element in Stack')

    # to remove the top element
    def pop(self):
        # Agar stack khali na ho
        if len(self.stack) > 0:
            return self.stack.pop()
        print('No Element in Stack')



AStack = Stack()
AStack.push("Mon")
AStack.push("Tue")
AStack.peek()
print(AStack.peek())
AStack.push("Wed")
AStack.push("Thu")
print(AStack.peek())
AStack.pop()
print(AStack.peek())