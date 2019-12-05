def build_graph(n, reversed_edges):
    graph = {i: [] for i in range(n)}
    for dst, src in reversed_edges:
        graph[src].append(dst)
    return graph

WHITE, GRAY, BLACK = 0, 1, 2
def has_cycle(graph):
    n = len(graph)
    colors = [WHITE for i in range(n)]
    
    def helper(i):
        colors[i] = GRAY
        for j in graph[i]:
            if colors[j] == GRAY or helper(j):
                return True
        colors[i] = BLACK
        return False
    
    # Check each vertex
    for i in graph.keys():
        if colors[i] == WHITE:
            if helper(i):
                return True
    return False

def top_sort(graph):
    visited = [False] * len(graph)
    stack = []
    
    def helper(i):
        visited[i] = True
        for j in graph[i]:
            if not visited[j]:
                helper(j)
        stack.append(i)
     
    # Start from each vertex
    for i in graph.keys():
        if not visited[i]:
            helper(i)
    return reversed(stack)
    
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        graph = build_graph(numCourses, prerequisites)
        if has_cycle(graph):
            return []
        return top_sort(graph)
