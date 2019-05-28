class Solution:
    """
    @param n: An integer
    @param edges: a list of undirected edges
    @return: true if it's a valid tree, or false
    """
    def validTree(self, n, edges):
        # write your code here
        if n <= 1:
            return True
        graph = collections.defaultdict(set)
        for u, v in edges:
            graph[u].add(v)
            graph[v].add(u)
        colors = [0 for _ in range(n)]
        def has_cycle(i=0):
            colors[i] = 1
            for neigh in graph[i]:
                graph[neigh].remove(i)
                if colors[neigh] == 1 or has_cycle(neigh):
                    return True
            colors[i] = 2
            return False
        is_cyclic = has_cycle(0)
        return not is_cyclic and all([color==2 for color in colors])
