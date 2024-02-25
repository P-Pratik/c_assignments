from collections import defaultdict

class Graph:
    def __init__(self):
        self.graph = defaultdict(list)

    def test(self):
        print(self.graph)

    def addEdge(self, u, v):
        self.graph[u].append(v)
        self.graph[v].append(u)

    def BFS(self, s):
        visited = [False] * (max(self.graph) + 1)
        queue = []
        queue.append(s)
        visited[s] = True
        while queue:
            s = queue.pop(0)
            print(s, end=" ")
            for i in self.graph[s]:
                if visited[i] == False:
                    queue.append(i)
                    visited[i] = True

    def DFSUtil(self, v, visited):
        visited.add(v)
        print(v, end=" ")
        for neighbour in self.graph[v]:
            if neighbour not in visited:
                self.DFSUtil(neighbour, visited)

    def DFS(self, v):
        visited = set()
        self.DFSUtil(v, visited)


if __name__ == "__main__":
    gb = Graph()
    gb.addEdge(0, 1)
    gb.addEdge(0, 2)
    gb.addEdge(0, 3)
    gb.addEdge(2, 3)
    gb.addEdge(2, 4)

    gb.test()

    print("BFS")
    gb.BFS(2)

    print("\nDFS")
    gb.DFS(2)
    print()
