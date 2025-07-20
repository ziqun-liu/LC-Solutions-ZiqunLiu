def LCA(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
    # p或q有可能不存在在树中
    if not root:
        return root

    if not self.exists(root, p) or not self.exists(root, q):
        return None
    return self.dfs(root, p, q)

def dfs(self, root, p, q):
    if not root:
        reurn None

    if root == p or root == q:
        return root

    left = dfs(root.left, p, q)
    right = dfs(root.right, p, q)

    if left and right:
        return root
    else:
        return left or right

def exists(self, root, target):
    if not root:
        return False

    if root == target:
        return True

    return self.exists(root.left, target) or self.exists(root.right, target)