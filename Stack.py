

class Stack:
    def __init__(self):
        self.stack = []

    # To add element to stack
    def push(self, data):
        if data not in self.stack:
            self.stack.append(data)
            return True
        return False
    

    # To peek Top element
    def peek(self):
        if len(self.stack) > 0:
            return self.stack[-1]
        print('No Element in Stack')

    # to remove the top element
    def pop(self):
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