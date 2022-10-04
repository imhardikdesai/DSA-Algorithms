class Node(object):
    def __init__(self, name):
        self.name = name
        self.adjacencyList = []
        self.visited = False
        self.predecessor = None


class DepthFirstSearch(object):
    # This is the recursive solution
    def dfs(self, node):
        # We set the node to be visited
        node.visited = True
        # We print it
        print(node.name)
        # Then we iterate through the neighbour list
        for n in node.adjacencyList:
            # If it is not visited we call the function recursively
            if not n.visited:
                # We don't return so it will iterate fully
                self.dfs(n)


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

dfs = DepthFirstSearch()
dfs.dfs(n1)
