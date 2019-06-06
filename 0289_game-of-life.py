class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        rows = len(board)
        cols = len(board[0]) if rows > 0 else 0
        neighbors = [(0,1), (1,0), (0,-1), (-1,0), (-1,-1), (1,1), (1,-1), (-1,1)]
        alive = [-1, 1]
        for i in range(rows):
            for j in range(cols):
                live_neighbors = 0
                for di, dj in neighbors:
                    r, c = i+di, j+dj
                    live_neighbors += (0 <= r < rows and 0 <= c < cols and board[r][c] in alive)
                if board[i][j] in alive:
                    if live_neighbors < 2 or live_neighbors > 3:
                        board[i][j] = -1
                elif live_neighbors == 3:
                    board[i][j] = 2
        print(board)
        for i in range(rows):
            for j in range(cols):
                board[i][j] = 1 if board[i][j] > 0 else 0
