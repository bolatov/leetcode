# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        if not root:
            return 0
        INT_MIN = -(1 << 32)
        ans = INT_MIN
        mp = collections.defaultdict(int)
        def dfs(node):
            if not node.left and not node.right:
                mp[node] = node.val
                return mp[node]
            left = dfs(node.left) if node.left else INT_MIN
            right = dfs(node.right) if node.right else INT_MIN
            mp[node] = max(node.val, max(node.val + left, node.val + right))
            return mp[node]
        dfs(root)
        q = collections.deque([root])
        while q:
            node = q.popleft()
            ans = max(ans, node.val)
            ans = max(ans, node.val + mp[node.left])
            ans = max(ans, node.val + mp[node.right])
            ans = max(ans, node.val + mp[node.left] + mp[node.right])
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
        return ans
