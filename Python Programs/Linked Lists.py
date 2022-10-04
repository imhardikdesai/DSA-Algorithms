class Node(object):
    def __init__(self, data):
        self.data = data
        self.nextNode = None

class LinkedList(object):
    def __init__(self):
        self.root = None
        self.size = 0

    def insertStart(self, data):
        self.size += 1
        newNode = Node(data)
        newNode.nextNode = self.root
        self.root = newNode
        
    def size1(self):
        return self.size

    def size_alt(self):
        curNode = self.root
        size = 0

        while curNode is not None:
            size+=1
            curNode = curNode.nextNode
        return size

    def insertEnd(self, data):
        curNode = self.root
        newNode = Node(data)

        while True:
            curNode = curNode.nextNode
            if curNode.nextNode is None:
                break

        curNode.nextNode = newNode
        newNode.nextNode = None

    def traverse(self):
        curNode = self.root
        while curNode is not None:
            print(curNode.data)
            curNode = curNode.nextNode

    def delete(self,data):
        if self.root is None:
            return False

        self.size -= 1
        curNode = self.root
        previousNode = None
        while curNode.nextNode is not None:
            if curNode.data == data:
                break
            else:
                previousNode = curNode
                curNode = curNode.nextNode

        if previousNode is None:
            previousNode = self.root
        else:
            previousNode.nextNode = curNode.nextNode
            curNode.nextNode = None

linked_list = LinkedList()
linked_list.insertStart(1)
linked_list.insertStart(45)
linked_list.insertStart(20)
linked_list.insertStart(78)
linked_list.insertStart(91)
linked_list.traverse()
print("\n")
print(linked_list.size_alt())
print(linked_list.size1())
linked_list.delete(1)
linked_list.delete(20)
linked_list.delete(78)
linked_list.delete(45)
linked_list.delete(90)
print("\n")
print(linked_list.size1())
