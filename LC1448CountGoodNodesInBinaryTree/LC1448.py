class DFS:
    def goodNodes(self, root: TreeNode) -> int:
        
        def dfs(node, maxVal):
            if not node:
                return 0
            result = 1 if node.val >= maxVal else 0
            result += dfs(node.left, max(maxVal, node.val))
            result += dfs(node.right, max(maxVal, node.val))
            return result
        
        return dfs(root, root.val)


class BFS:
    def goodNodes(self, root: TreeNode) -> int:
        res = 0
        q = collections.deque()
        q.append((root, root.val))

        while q:
            node, max_val = q.popleft()
            if node.val >= max_val:
                res += 1
            if node.left:
                q.append((node.left, max(node.val, max_val)))
            if node.right:
                q.append((node.right, max(node.val, max_val)))

        return res