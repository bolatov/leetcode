# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumRootToLeaf(self, root: TreeNode) -> int:
        ans = 0
        def dfs(node, val):
            val <<= 1
            val |= node.val
            if not node.left and not node.right:
                nonlocal ans
                ans += val
                return
            if node.left:
                dfs(node.left, val)
            if node.right:
                dfs(node.right, val)
        dfs(root, 0)
        return ans
