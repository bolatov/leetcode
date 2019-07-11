# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def delNodes(self, root: TreeNode, to_delete: List[int]) -> List[TreeNode]:
        new_root = TreeNode(0)
        new_root.left = root
        exclude = set(to_delete)
        exclude.add(0)
        q = collections.deque([new_root])
        ans = []
        while q:
            node = q.popleft()
            if node.val in exclude:
                if node.left:
                    left = node.left
                    node.left = None
                    if left.val not in exclude:
                        ans.append(left)
                    q.append(left)
                if node.right:
                    right = node.right
                    node.right = None
                    if right.val not in exclude:
                        ans.append(right)
                    q.append(right)
            else:
                if node.left:
                    q.append(node.left)
                    if node.left.val in exclude:
                        node.left = None
                if node.right:
                    q.append(node.right)
                    if node.right.val in exclude:
                        node.right = None
        return ans
