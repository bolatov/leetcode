class Solution:
    def matrixReshape(self, nums, r, c):
        """
        :type nums: List[List[int]]
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
        m = len(nums)
        n = len(nums[0]) if nums else 0
        if m * n != r * c:
            return nums
        matrix = [[]]
        i, j = 0, 0
        for row in range(m):
            for col in range(n):
                if j >= c:
                    i, j = i + 1, 0
                    matrix.append([])
                matrix[len(matrix) - 1].append(nums[row][col])
                j += 1
        return matrix