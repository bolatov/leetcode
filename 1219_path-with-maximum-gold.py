class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        def is_valid(i, j):
            return 0 <= i < rows and 0 <= j < cols and grid[i][j] > 0
        def backtrack(i, j, remaining=25):
            maxgold = 0
            for di, dj in dirs:
                if is_valid(i+di, j+dj) and remaining > 0:
                    curvalue = grid[i][j]
                    grid[i][j] = 0
                    maxgold = max(backtrack(i+di, j+dj, remaining-1), maxgold)
                    grid[i][j] = curvalue
            return maxgold + grid[i][j]
        return max(
            backtrack(i, j) for i in range(rows) for j in range(cols) if grid[i][j] > 0
        )
