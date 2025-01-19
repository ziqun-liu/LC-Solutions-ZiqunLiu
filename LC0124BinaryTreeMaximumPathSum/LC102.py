from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.max_path = root.val

        def dfs(node):
            if not node:
                return 0

            left_max = max((dfs(node.left)), 0)
            right_max = max(dfs(node.right), 0)

            self.max_path = max(self.max_path, node.val + left_max + right_max)
            return node.val + max(left_max, right_max)

        dfs(root)
        return self.max_path
        