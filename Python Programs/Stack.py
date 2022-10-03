class Stack():
    def __init__(self):
        self.stack = []

    def push(self, data):
        self.stack.append(data)

    def pop(self):
        return self.stack.pop()

    def isEmpty(self):
        return len(self.stack) == 0

    def peek(self):
        if not self.isEmpty():
            return self.stack[-1]
        else:
            print("Stack is empty")
            return

    def getItems(self):
        return self.stack

    def sizeStack(self):
        return len(self.stack)

stack = Stack()
stack.push(1)
stack.push(2)
stack.push(3)
stack.push(4)
print("Size : ", stack.sizeStack())
print("Popped: ", stack.pop())
print("Peek : ", stack.peek())
print(stack.isEmpty())
print(stack.getItems())
