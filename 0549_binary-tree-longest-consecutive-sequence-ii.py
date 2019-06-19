"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""

class Solution:
    """
    @param root: the root of binary tree
    @return: the length of the longest consecutive sequence path
    """
    def longestConsecutive2(self, root):
        # write your code here
        ans = 0
        def dfs(node):
            if not node:
                return 0, 0
            inc, dec = 0, 0
            left_inc, left_dec = dfs(node.left)
            right_inc, right_dec = dfs(node.right)
            if node.left:
                if node.val + 1 == node.left.val:
                    inc = left_inc + 1
                elif node.val - 1 == node.left.val:
                    dec = left_dec + 1
            if node.right:
                if node.val + 1 == node.right.val:
                    inc = max(inc, right_inc + 1)
                elif node.val - 1 == node.right.val:
                    dec = max(dec, right_dec + 1)
            nonlocal ans
            ans = max(ans, inc + 1 + dec)
            return inc, dec
        dfs(root)
        return ans
