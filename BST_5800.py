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
	    """
	    插入节点，并正确维护 parent 指针
	    """
	    if root == None:
	        return TreeNode(key)
	    
	    if root.key == key:
	        return root
	    
	    if root.key < key:
	        root.right = self.insert(root.right, key)
	        # 更新 parent 指针
	        root.right.parent = root
	    else:
	        root.left = self.insert(root.left, key)
	        # 更新 parent 指针
	        root.left.parent = root
	    
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
	    从 BST 中删除指定值的节点，并正确维护 parent 指针
	    
	    时间复杂度: O(h)
	    """
	    # Base case: 节点不存在
	    if not node:
	        return None
	    
	    # Step 1: 递归查找要删除的节点
	    if key < node.key:
	        node.left = self.delete(node.left, key)
	        # 更新 parent 指针
	        if node.left:
	            node.left.parent = node
	        return node
	    elif key > node.key:
	        node.right = self.delete(node.right, key)
	        # 更新 parent 指针
	        if node.right:
	            node.right.parent = node
	        return node
	    
	    # Step 2: 找到了要删除的节点 (node.key == key)
	    
	    # 情况 1: 没有左孩子
	    if not node.left:
	        # 返回右孩子，并更新其 parent
	        if node.right:
	            node.right.parent = node.parent
	        return node.right
	    
	    # 情况 2: 只有左孩子
	    if not node.right:
	        # 返回左孩子，并更新其 parent
	        if node.left:
	            node.left.parent = node.parent
	        return node.left
	    
	    # 情况 3: 有两个孩子
	    # 用 successor 替换当前节点的值
	    successor_key = self.find_min(node.right)
	    node.key = successor_key
	    
	    # 在右子树中删除 successor
	    node.right = self.delete(node.right, successor_key)
	    # 更新右子树的 parent
	    if node.right:
	        node.right.parent = node
	    
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






