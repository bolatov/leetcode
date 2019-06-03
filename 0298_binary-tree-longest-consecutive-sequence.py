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
    def longestConsecutive(self, root):
        # write your code here
        if not root:
            return 0
        queue = collections.deque([(root, 1)])
        ans = 0
        while queue:
            node, cnt = queue.popleft()
            ans = max(ans, cnt)
            if node.left:
                queue.append((node.left, cnt+1 if node.left.val-node.val==1 else 1))
            if node.right:
                queue.append((node.right, cnt+1 if node.right.val-node.val==1 else 1))
        return ans
