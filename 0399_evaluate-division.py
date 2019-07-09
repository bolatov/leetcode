class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        g = collections.defaultdict(list)
        for eq, val in zip(equations, values):
            nom, denom = eq
            g[nom].append((denom, val))
            g[denom].append((nom, 1 / val))
        def solve(src, dst):
            if src not in g:
                return -1.0
            if src == dst:
                return 1.0
            visited = set()
            q = collections.deque([(neigh, val) for neigh, val in g[src]])
            while q:
                length = len(q)
                for _ in range(length):
                    node, curval = q.popleft()
                    visited.add(node)
                    if node == dst:
                        return curval
                    for neigh, val in g[node]:
                        if neigh not in visited:
                            visited.add(neigh)
                            nextval = curval * val
                            q.append((neigh, nextval))
            return -1.0
        res = []
        for nom, denom in queries:
            res.append(solve(nom, denom))
        return res
