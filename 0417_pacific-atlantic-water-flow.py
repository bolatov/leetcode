# My solution
class Solution:
    def pacificAtlantic(self, matrix: List[List[int]]) -> List[List[int]]:
        m = len(matrix)
        n = len(matrix[0]) if m > 0 else 0
        dirs = [(-1,0), (0,-1), (0,1), (1,0)]
        ans = []
        def cell_id(i, j):
            return i*n + j
        def is_valid(i, j, r, c, visited):
            return (
                0 <= i < m and 0 <= j < n
                and 0 <= r < m and 0 <= c < n 
                and matrix[r][c] <= matrix[i][j]
                and cell_id(r, c) not in visited)
        def dfs(i, j, is_pacific, visited):
            if cell_id(i, j) in reachable:
                return True
            visited.add(cell_id(i, j))
            if (i == 0 or j == 0) and is_pacific:
                return True
            if (i == m-1 or j == n-1) and (not is_pacific):
                return True
            for di, dj in dirs:
                r, c = i + di, j + dj
                if is_valid(i, j, r, c, visited):
                    visited.add(cell_id(r, c))
                    if dfs(r, c, is_pacific, visited):
                        return True
            return False
        reachable = set()
        for i in range(m):
            for j in range(n):
                if dfs(i, j, True, set()) and dfs(i, j, False, set()):
                    ans.append([i,j])
                    reachable.add(cell_id(i, j))
        return ans

# Optimized - (looked at others' submissions)
class Solution:
    def pacificAtlantic(self, matrix: List[List[int]]) -> List[List[int]]:
        m = len(matrix)
        n = len(matrix[0]) if m > 0 else 0
        pacific, atlantic = set(), set()
        dirs = [(0,1), (1,0), (0,-1), (-1,0)]
        def dfs(i, j, coords):
            coords.add((i, j))
            for di, dj in dirs:
                r, c = i + di, j + dj
                if (0 <= r < m
                    and 0 <= c < n
                    and (r,c) not in coords
                    and matrix[r][c] >= matrix[i][j]):
                    coords.add((r, c))
                    dfs(r, c, coords)
        for i in range(m):
            dfs(i, 0, pacific)
            dfs(i, n-1, atlantic)
        for j in range(n):
            dfs(0, j, pacific)
            dfs(m-1, j, atlantic)
        return list(pacific & atlantic)  # intersection of two sets as list
