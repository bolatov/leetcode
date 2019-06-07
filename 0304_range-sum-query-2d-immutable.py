class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        rows = len(matrix)
        cols = len(matrix[0]) if rows > 0 else 0
        for i in range(1, rows):
            matrix[i][0] += matrix[i-1][0]
        for j in range(1, cols):
            matrix[0][j] += matrix[0][j-1]
        for i in range(1, rows):
            for j in range(1, cols):
                matrix[i][j] += matrix[i-1][j] + matrix[i][j-1] - matrix[i-1][j-1]
        self.mm = matrix

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        ans = self.mm[row2][col2]
        if row1 > 0:
            ans -= self.mm[row1-1][col2]
        if col1 > 0:
            ans -= self.mm[row2][col1-1]
        if row1 > 0 and col1 > 0:
            ans += self.mm[row1-1][col1-1]
        return ans


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)
