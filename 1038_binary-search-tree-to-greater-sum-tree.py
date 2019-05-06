# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        def helper(node, agg):
            if not node:
                return agg
            node.val += helper(node.right, agg)
            return helper(node.left, node.val)
        helper(root, 0)
        return root
