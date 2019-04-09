class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        def solve(be, max_value):
            if be >= len(preorder) or preorder[be] > max_value:
                return be, None
            root = TreeNode(preorder[be])
            be, root.left = solve(be+1, root.val)
            be, root.right = solve(be, max_value)
            return be, root
        return solve(0, max(preorder))[1]
