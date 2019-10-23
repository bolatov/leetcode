class Solution:
    def queensAttacktheKing(self, queens: List[List[int]], king: List[int]) -> List[List[int]]:
        n = 8
        offs = [-1, 0, 1]
        dirs = set([(i, j) for i in offs for j in offs if i | j])
        print(dirs)
        board = [[0 for _ in range(n)] for _ in range(n)]
        for i, j in queens:
            board[i][j] = 1
        ans = []
        for di, dj in dirs:
            i, j = king
            while 0<=i<n and 0<=j<n:
                if board[i][j]:
                    ans.append([i, j])
                    break
                i += di
                j += dj
        return ans
