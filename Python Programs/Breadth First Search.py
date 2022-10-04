class Node(object):
    def __init__(self, name):
        # This will store the data of the node
        self.name = name
        # This is the neighbours of the node
        self.adjacencyList = []
        # We create a boolean to check the node is visited or not
        self.visited = False
        # Should ask
        self.predecessor = None


class BreadthFirstSearch(object):
    def bfs(self, start_node):
        # We create a queue with the starting node
        queue = [start_node]
        # We set that the given node is visited
        start_node.visited = True
        # We iterate through the queue until it's not empty
        while queue:
            # We get the first item in the queue -> FIFO structure
            actual_node = queue.pop(0)
            # We print it out
            print(actual_node.name)
            # We iterate through the neighbours and visit them also adding them to the queue
            for node in actual_node.adjacencyList:
                if not node.visited:
                    node.visited = True
                    queue.append(node)


n1 = Node("A")
n2 = Node("B")
n3 = Node("C")
n4 = Node("D")
n5 = Node("E")
n6 = Node("F")
n7 = Node("G")
n8 = Node("H")

n1.adjacencyList.append(n2)
n1.adjacencyList.append(n3)
n2.adjacencyList.append(n4)
n2.adjacencyList.append(n5)
n1.adjacencyList.append(n6)
n3.adjacencyList.append(n7)
n4.adjacencyList.append(n8)

bfs = BreadthFirstSearch()
bfs.bfs(n1)
