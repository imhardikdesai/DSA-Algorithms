class Node(object):
    def __init__(self, data):
        self.data = data
        self.rightChild = None
        self.leftChild = None


class BinarySearchTree(object):
    def __init__(self):
        self.root = None

    def insert(self, data):
        if not self.root:
            self.root = Node(data)
        else:
            self.insertNode(data, self.root)

    def insertNode(self, data, node):
        if data > node.data:
            if node.rightChild:
                self.insertNode(data, node.rightChild)
            else:
                node.rightChild = Node(data)
        else:
            if node.leftChild:
                self.insertNode(data, node.leftChild)
            else:
                node.leftChild = Node(data)

    def removeNode(self, data, node):
        if not node:
            return node

        if data < node.data:
            node.leftChild = self.removeNode(data, node.leftChild)
        elif data > node.data:
            node.rightChild = self.removeNode(data, node.rightChild)
        else:
            # This is a leaf node with no children
            if node.leftChild is None and node.rightChild is None:
                print("Removing a leaf node...")
                del node
                return None
            # This is a node with a left child
            if node.leftChild and not node.rightChild:
                print("Removing a node with a left child....")
                tempNode = node.leftChild
                del node
                return tempNode
            # This is a node with a right child
            elif not node.leftChild and node.rightChild:
                print("Removing a node with a right child...")
                tempNode = node.rightChild
                del node
                return tempNode
            # This node has both children
            print("Removing a node with both the children...")
            # This is the maximum value in the left subtree
            predecessor = self.getMax(node.leftChild)
            # This is the minimum value in the right subtree
            successor = self.getMin(node.rightChild)
            # We can swap the node with any of these values...
            # I choose the predecessor because it will be a leaf node when we swap it
            node.data = predecessor.data
            node.leftChild = self.removeNode(predecessor.data, node.leftChild)
        return node

    def remove(self, data):
        if self.root:
            self.root = self.removeNode(data, self.root)

    def getMinValue(self):
        if self.root:
            minNode = self.getMin(self.root)
            return minNode.data

    def getMin(self, node):
        if node.leftChild:
            return self.getMin(node.leftChild)
        return node

    def getMaxValue(self):
        if self.root:
            maxnode = self.getMax(self.root)
            return maxnode.data

    def getMax(self, node):
        if node.rightChild:
            return self.getMax(node.rightChild)
        return node

    def traverseIn(self):
        if self.root:
            self.traverseInOrder(self.root)
        else:
            print("Root is Null")

    def traverseInOrder(self, node):
        # Visit the left tree
        if node.leftChild:
            self.traverseInOrder(node.leftChild)
        # visit the root node
        print("{}".format(node.data))
        # Visit the right tree
        if node.rightChild:
            self.traverseInOrder(node.rightChild)

    def traversePre(self):
        if self.root:
            self.traversePreOrder(self.root)
        else:
            print("Root is null")

    def traversePreOrder(self, node):
        # Visit the root node
        print(node.data)
        # visit the left node
        if node.leftChild:
            self.traversePreOrder(node.leftChild)
        # visit the right node
        if node.rightChild:
            self.traversePreOrder(node.rightChild)

    def traversePost(self):
        if self.root:
            self.traversePostOrder(self.root)
        else:
            print("Root is null")
            return

    def traversePostOrder(self, node):
        # visit the left
        if node.leftChild:
            self.traversePostOrder(node.leftChild)
        # visit the right
        if node.rightChild:
            self.traversePostOrder(node.rightChild)
        # visit the root
        print(node.data)

    def height(self, node):
        if node.rightChild and node.leftChild:
            return 1+max(self.height(node.rightChild),self.height(node.leftChild))
        elif node.rightChild:
            return 1+self.height(node.rightChild)
        elif node.leftChild:
            return 1+self.height(node.leftChild)
        else:
            return 1

    def getHeight(self):
        if not self.root:
            return 0
        else:
            return self.height(self.root)


bst = BinarySearchTree()
bst.insert(32)
bst.insert(10)
bst.insert(55)
bst.insert(1)
bst.insert(19)
bst.insert(16)
bst.insert(23)
bst.insert(79)
print(bst.getMinValue())
print(bst.getMaxValue())
print("\n")
bst.traverseIn()
# print("\n")
# bst.traversePost()
# print("\n")
# bst.traversePre()
print("\n")
bst.remove(19)
print("\n")
bst.traverseIn()

