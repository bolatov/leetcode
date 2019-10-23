class Solution:
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        zero_count = 0
        start_i, start_j = 0, 0
        def is_valid(i, j):
            return 0 <= i < rows and 0 <= j < cols and grid[i][j] in [0, 2]
        def backtrack(i, j, zeros):
            if grid[i][j] == 2:
                return zeros == 0
            paths = 0
            for di, dj in [(0,1), (1,0), (0,-1), (-1,0)]:
                next_i, next_j = i + di, j + dj
                if is_valid(next_i, next_j):
                    value = grid[i][j]
                    grid[i][j] = 1
                    paths += backtrack(next_i, next_j, zeros - (value == 0))
                    grid[i][j] = value
            return paths
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    start_i, start_j = i, j
                elif grid[i][j] == 0:
                    zero_count += 1
        return backtrack(start_i, start_j, zero_count)
