class Queue():

    def __init__(self):
        self.queue = []

    def isEmpty(self):
        return self.queue == []

    def enqueue(self, data):
        self.queue.append(data)

    def dequeue(self):
        return self.queue.pop(0)

    def peek(self):
        return self.queue[0]

    def sizeQueue(self):
        return len(self.queue)

queue = Queue()
queue.enqueue(1)
queue.enqueue(2)
queue.enqueue(3)
queue.enqueue(4)
print("Size : ", queue.sizeQueue())
print("Dequeued : ", queue.dequeue())
print("Peek : ", queue.peek())
