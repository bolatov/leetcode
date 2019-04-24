# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class CBTInserter:

    def __init__(self, root: TreeNode):
        self.root = root
        self._count(self.root)

    def _count(self, node):
        if not node:
            return 0
        node._cnt = 1 + self._count(node.left) + self._count(node.right)
        return node._cnt
        
    def _insert(self, node, v):
        l = 0 if not node.left else node.left._cnt
        r = 0 if not node.right else node.right._cnt
        node._cnt += 1
        if l == 0:
            node.left = TreeNode(v)
            node.left._cnt = 1
            return node.val
        elif r == 0:
            node.right = TreeNode(v)
            node.right._cnt = 1
            return node.val
        elif (l > 1 and l & (l+1) != 0) or l == r:
            return self._insert(node.left, v)
        else:
            return self._insert(node.right, v)

    def insert(self, v: int) -> int:
        return self._insert(self.root, v)

    def get_root(self) -> TreeNode:
        return self.root


# Your CBTInserter object will be instantiated and called as such:
# obj = CBTInserter(root)
# param_1 = obj.insert(v)
# param_2 = obj.get_root()
