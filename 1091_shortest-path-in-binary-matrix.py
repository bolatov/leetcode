from collections import deque
class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        if grid[0][0] or grid[-1][-1]:
            return -1
        dirs = [-1, 0, 1]
        n = len(grid)
        q = deque([(0, 0)])
        pathlen = 0
        def is_valid(i, j):
            return (0 <= i < n and 0 <= j < n  # check if in range
                    and not grid[i][j])  # check if not visited and not blocked
        while q:
            pathlen += 1
            qsize = len(q)
            for _ in range(qsize):
                i, j = q.popleft()
                grid[i][j] = 1  # mark as visited
                if i == n-1 and j == n-1:
                    return pathlen
                for di in dirs:
                    for dj in dirs:
                        if is_valid(i + di, j + dj):
                            q.append((i + di, j + dj))
                            grid[i + di][j + dj] = 1
        return -1
