# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isCompleteTree(self, root: TreeNode) -> bool:
        if not root:
            return True
        q = collections.deque([(root, 1)])
        position = 1
        while q:
            node, pos = q.popleft()
            if pos != position:
                return False
            if node.left:
                q.append((node.left, pos*2))
            if node.right:
                q.append((node.right, pos*2+1))
            position += 1
        return True
