# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class FindElements:

    def __init__(self, root: TreeNode):
        self.root = root
        self.root.val = 0
        self.values = set()
        self._recover(root)

    def _recover(self, node):
        if node.left:
            val = node.val*2 + 1
            node.left.val = val
            self.values.add(val)
            self._recover(node.left)
        if node.right:
            val = node.val*2 + 2
            node.right.val = node.val * 2 + 2
            self.values.add(val)
            self._recover(node.right)
        
    def find(self, target: int) -> bool:
        return target in self.values
        

# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)
