class Solution:

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.max_len = 0
        self.dfs(root)
        return self.max_len

    def dfs(self, root):
        if not root:
            return 0
        l = self.dfs(root.left)
        r = self.dfs(root.right)
        self.max_len = max(self.max_len, l + r)
        return 1 + max(l, r)