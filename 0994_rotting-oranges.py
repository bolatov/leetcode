from collections import deque
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0]) if len(grid) else 0
        q = deque([(i, j) for i in range(n) for j in range(m) if grid[i][j] == 2])
        dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        ans = 0
        while q:
            ok = False
            sz = len(q)
            for _ in range(sz):
                i, j = q.popleft()
                for ii, jj in dirs:
                    if 0 <= i + ii < n and 0 <= j + jj < m and grid[i+ii][j+jj] == 1:
                        ok = True
                        grid[i+ii][j+jj] = 2
                        q.append((i+ii, j+jj))
            ans += ok
        if any(orange == 1 for row in grid for orange in row):
            return -1
        return ans
                
