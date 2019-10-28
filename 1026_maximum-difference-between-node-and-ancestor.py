class Solution:
    def maxAncestorDiff(self, root: TreeNode) -> int:
        ans = 0
        def dfs(node, value, fn):
            nonlocal ans
            ans = max(ans, abs(node.val-value))
            if node.left:
                dfs(node.left, fn(node.val, value), fn)
            if node.right:
                dfs(node.right, fn(node.val, value), fn)
        dfs(root, root.val, max)
        dfs(root, root.val, min)
        return ans
