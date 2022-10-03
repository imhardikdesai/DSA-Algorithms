import sys
import heapq


class Edge(object):
    # This is the class for every edge in the tree
    def __init__(self, weight, startVertex, targetVertex):
        # Each edge has a weight
        self.weight = weight
        # There is starting vertex
        self.startVertex = startVertex
        # There is also an ending vertex
        self.targetVertex = targetVertex


class Node(object):
    # We define our node class
    def __init__(self, name):
        self.name = name
        self.visited = False
        # This is the neighbours list
        self.adjacencyList = []
        # This is the predecessor of the node So that we can back track and find the shortest path
        self.predecessor = None
        # We define the minimum distance to be infinity
        # The sys.maxsize gives the infinity value
        # We set this up to all other nodes
        self.minDistance = sys.maxsize

    # This is the comparator of the node function
    def __cmp__(self, otherVertex):
        # We are pushing the the nodes into the heap
        # So we have to set it in what basis we are going to push them
        # We push them with the minimum distance as the priority value
        return self.cmp(self.minDistance, otherVertex.minDistance)

    # This is the less than function
    def __lt__(self, other):
        # We have to define in what basis we are going to order the nodes
        # We define them with the min Distance
        self_priority = self.minDistance
        other_priority = other.minDistance
        # We will return a boolean
        return self_priority < other_priority


class Algorithm(object):
    # This algorithm sets the shortest path for the given graph
    def shortest_path(self, vertexList, startVertex):
        # We create priority queue as an one dimensional array
        q = []
        # We set the starting node's distance to 0
        startVertex.minDistance = 0
        # We will push the starting vertex to the queue
        heapq.heappush(q, startVertex)
        # We will iterate throughout the queue while it's empty
        while len(q) > 0:
            # We take out the minimum distance node
            actual_vertex = heapq.heappop(q)
            # We iterate throughout the neighbours of the list
            for edge in actual_vertex.adjacencyList:
                u = edge.startVertex
                v = edge.targetVertex
                # We calculate the distance by adding the node's distance with the edge's weight
                temp_distance = u.minDistance + edge.weight
                # We check if the calculated distance is less than the node's distance
                if temp_distance < v.minDistance:
                    # We set the predecessor and the minDistance
                    v.predecessor = u
                    v.minDistance = temp_distance
                    # Finally we push it to the heap
                    heapq.heappush(q, v)

    def get_shortest_path(self, targetVertex):
        # We print out the vertex we are looking for
        print("Shortest path to vertex {} is {}".format(targetVertex.name, targetVertex.minDistance))
        # We set the node to be the target and we backtrack
        node = targetVertex
        while node is not None:
            print(node.name)
            # We increment it by setting it to its predecessor
            node = node.predecessor


node1 = Node("A")
node2 = Node("B")
node3 = Node("C")
node4 = Node("D")
node5 = Node("E")
node6 = Node("F")
node7 = Node("G")
node8 = Node("H")

edge1 = Edge(5, node1, node2)
edge2 = Edge(8, node1, node8)
edge3 = Edge(9, node1, node5)
edge4 = Edge(15, node2, node4)
edge5 = Edge(12, node2, node3)
edge6 = Edge(4, node2, node8)
edge7 = Edge(7, node8, node3)
edge8 = Edge(6, node8, node6)
edge9 = Edge(5, node5, node8)
edge10 = Edge(4, node5, node6)
edge11 = Edge(20, node5, node7)
edge12 = Edge(1, node6, node3)
edge13 = Edge(13, node6, node7)
edge14 = Edge(3, node3, node4)
edge15 = Edge(11, node3, node7)
edge16 = Edge(9, node4, node7)

node1.adjacencyList.append(edge1)
node1.adjacencyList.append(edge2)
node1.adjacencyList.append(edge3)
node2.adjacencyList.append(edge4)
node2.adjacencyList.append(edge5)
node2.adjacencyList.append(edge6)
node8.adjacencyList.append(edge7)
node8.adjacencyList.append(edge8)
node5.adjacencyList.append(edge9)
node5.adjacencyList.append(edge10)
node5.adjacencyList.append(edge11)
node6.adjacencyList.append(edge12)
node6.adjacencyList.append(edge13)
node3.adjacencyList.append(edge14)
node3.adjacencyList.append(edge15)
node4.adjacencyList.append(edge16)


vertexList = (node1, node2, node3, node4, node5, node6, node7, node8)

algorithm = Algorithm()
algorithm.shortest_path(vertexList, node1)
algorithm.get_shortest_path(node4)
