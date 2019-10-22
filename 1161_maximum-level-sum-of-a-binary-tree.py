# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque
class Solution:
    def maxLevelSum(self, root: TreeNode) -> int:
        if not root:
            return 0
        level, maxsum = 0, float('-inf')
        q = deque([root])
        curlevel = 0
        while q:
            size = len(q)
            curlevel += 1
            cursum = 0
            for _ in range(size):
                node = q.popleft()
                cursum += node.val
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            if cursum > maxsum:
                maxsum = cursum
                level = curlevel
        return level
