class TreeNode:
    def __init__(self, key, left=None, right=None, parent=None):
        self.key = key
        self.left = left
        self.right = right
        self.parent = parent


class BST:
	def find_min(self, root: TreeNode):
		if not root.left:
			return root.key
		return self.find_min(root.left)

	def find_max(self, root: TreeNode):
		if not root.right:
			return root.key
		return self.find_max(root.right)

	def insert(self, root: TreeNode, key: int):
		# time O(H)
		if root == None:
			return TreeNode(key)
		if root.key == key:
			return root
		if root.key < key:
			root.right = self.insert(root.right, key)
		else:
			root.left = self.insert(root.left, key)
		return root

	def find(self, root: TreeNode, key: int):
		# time O(H)
		if root == None:
			return False
		if root.key == key:
			return True
		if root.key < key:
			return self.find(root.right, key)
		return self.find(root.left, key)

	def delete(self, node: TreeNode, key: int):
		    """
    从 BST 中删除指定值的节点
    
    算法思路：
    1. 递归查找要删除的节点
    2. 根据节点的子节点情况，分三种情况处理：
       - 情况 1: 叶子节点或只有右孩子 → 返回右孩子（可能为 None）
       - 情况 2: 只有左孩子 → 返回左孩子
       - 情况 3: 有两个孩子 → 用右子树的最小值（successor）替换，
                 然后在右子树中递归删除 successor
    
    参数:
        root (TreeNode): 当前子树的根节点
        key (int): 要删除的节点的值
    
    返回:
        TreeNode: 删除操作后，当前子树的新根节点
                  可能是：
                  - 原来的 root（删除的是子树内部节点）
                  - 其他节点（删除的是 root 本身）
                  - None（删除后子树为空）
    
    时间复杂度: O(h)，h 为树的高度
        - 平衡树: O(log n)
        - 最坏情况（退化成链表）: O(n)
    
    空间复杂度: O(h)，递归调用栈的深度
    
    注意:
        - 如果要删除整棵树的根节点，必须接收返回值：
          root = bst.delete(root, root.key)
        - 如果 key 不存在，树结构不变
        - 删除操作会保持 BST 的性质
    """
		if not node:
			return None

		if node.key < key:
			self.delete(node.right, key)
		if node.key > key:
			self.delete(node.left, key)
		else:
			successor_key = self.find_min(node.right)  # 1. 找到 successor 的值
			node.key = successor_key  # 用 successor 的值替换当前节点
			node.right = self.delete(node.right, successor_key)  # 删除原来的 successor

		return node

	def predecessor(self, node: TreeNode):
		if node.left:
			return self.find_max(node.left)

		p = node.parent
		while p:
			if p.key < node.key:
				return p
			else:
				p = p.parent

		return None

	def successor(self, node: TreeNode):
		if node.right:
			return self.find_min(node.right)

		p = node.parent
		while p:
			if p.key > node.key:
				return p
			else:
				p = p.parent

		return None






