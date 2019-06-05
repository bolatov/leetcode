class Solution:
    """
    @param rooms: m x n 2D grid
    @return: nothing
    """
    def wallsAndGates(self, rooms):
        # write your code here
        rows = len(rooms)
        cols = len(rooms[0]) if rows > 0 else 0
        dirs = [(0,1), (1,0), (0,-1), (-1,0)]
        def is_valid(i, j):
            return 0 <= i < rows and 0 <= j < cols and rooms[i][j] != -1
        queue = collections.deque([])
        for i, row in enumerate(rooms):
            for j, val in enumerate(row):
                if val == 0:
                    queue.append((i, j))
        while queue:
            i, j = queue.popleft()
            for di, dj in dirs:
                if is_valid(i+di, j+dj) and rooms[i+di][j+dj] > rooms[i][j] + 1:
                    rooms[i+di][j+dj] = rooms[i][j] + 1
                    queue.append((i+di, j+dj))
