class Node(object):
    def __init__(self, data):
        self.data = data
        self.height = 0
        self.leftChild = None
        self.rightChild = None


class AVL_Tree(object):
    def __init__(self):
        self.root = None

    def insert(self, data):
        self.root = self.insertNode(data, self.root)

    def remove(self, data):
        if self.root:
            self.root = self.removeNode(data, self.root)

    def removeNode(self, data, node):
        if not node:
            return node
        if data < node.data:
            node.leftChild = self.removeNode(data, node.leftChild)
        elif data > node.data:
            node.rightChild = self.removeNode(data, node.rightChild)
        else:
            # Removing the leaf node
            if not node.leftChild and not node.rightChild:
                print("Removing a leaf node....")
                del node
                return None

            # Removing a node which has a single child
            if node.leftChild and not node.rightChild:
                print("Removing a node with a left child....")
                tempNode = node.leftChild
                del node
                return tempNode
            elif not node.leftChild and node.rightChild:
                print("Removing a node with a right child....")
                tempNode = node.rightChild
                del node
                return tempNode

            # Removing the node with both the children
            print("Removing a node with both the children....")
            predecessor = self.getMax(node.leftChild)
            node.data = predecessor.data
            node.leftChild = self.removeNode(predecessor.data, node.leftChild)

    def getMaxValue(self):
        if self.root:
            maxNode = self.getMax(self.root)
            return maxNode.data

    def getMax(self, node):
        if node.rightChild:
            self.getMax(node.rightChild)
        return node

    def getMinValue(self):
        if self.root:
            minNode = self.getMin(self.root)
            return minNode.data

    def getMin(self, node):
        if node.leftChild:
            self.getMin(node.leftChild)
        return node

    def insertNode(self, data, node):
        if not node:
            return Node(data)
        if data < node.data:
            node.leftChild = self.insertNode(data, node.leftChild)
        else:
            node.rightChild = self.insertNode(data, node.rightChild)

        node.height = max(self.calcHeight(node.leftChild), self.calcHeight(node.rightChild))+1
        return self.settleViolation(data, node)

    def settleViolation(self, data, node):
        balance = self.calcBalanced(node)

        # Case 1: if the value in balance is greater than 1 it should be rotated to the right..
        # This is a doubly left heavy situation
        if balance > 1 and data < node.leftChild.data:
            print("Left..left heavy situation....")
            return self.rotateRight(node)
        # Case 2: if the value in the balance is less than -1 i should be rotated to the left
        # This is a doubly right heavy situation
        if balance < -1 and data > node.rightChild.data:
            print("Right ..right heavy situation...")
            return self.rotateLeft(node)
        # Case 3: if the value in the balance is greater than 1 and data is greater than node
        # This is a left right heavy situation..
        if balance > 1 and data > node.leftChild.data:
            print("Left right heavy situation...")
            node.leftChild = self.rotateLeft(node.leftChild)
            return self.rotateRight(node)
        # Case 4: if the value in the balance is less than -1 and the data is less than node
        # This is the right left heavy situation
        if balance < -1 and data < node.rightChild.data:
            print("Right..left heavy situation....")
            node.rightChild = self.rotateRight(node.rightChild)
            return self.rotateLeft(node)
        return node

    def calcHeight(self, node):
        if not node:
            return -1
        return node.height

    # If this function returns the value > 1 rotate right
    # If this function returns the value < 1 rotate left
    def calcBalanced(self, node):
        if not node:
            return 0
        return self.calcHeight(node.leftChild)-self.calcHeight(node.rightChild)

    def traverseIn(self):
        if self.root:
            self.traverseInOrder(self.root)
        else:
            print("Tree is null...")
        return

    def traverseInOrder(self, node):
        if node.leftChild:
            self.traverseInOrder(node.leftChild)
        print(node.data)
        if node.rightChild:
            self.traverseInOrder(node.rightChild)

    def rotateRight(self, node):
        print("Rotating on right on node..........", node.data)
        curNode = node.leftChild

        node.leftChild = curNode.rightChild
        curNode.rightChild = node

        node.height = max(self.calcHeight(node.leftChild), self.calcHeight(node.rightChild)) + 1
        curNode.height = max(self.calcHeight(curNode.leftChild), self.calcHeight(curNode.rightChild)) + 1
        return curNode

    def rotateLeft(self, node):
        print("Rotating on left on node..........", node.data)
        curNode = node.rightChild

        node.rightChild = curNode.leftChild
        curNode.leftChild = node

        node.height = max(self.calcHeight(node.leftChild), self.calcHeight(node.rightChild)) + 1
        curNode.height = max(self.calcHeight(curNode.leftChild), self.calcHeight(curNode.rightChild)) + 1
        return curNode


avl = AVL_Tree()
avl.insert(1)
avl.insert(2)
avl.insert(3)
avl.insert(4)
avl.insert(5)
avl.insert(6)
avl.traverseIn()