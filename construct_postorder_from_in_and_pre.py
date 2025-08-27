class TreeNode:
	def __init__(self, val):
		self.val = val
		self.left = None
		self.right = None


class Solution:
	def construct(self, preorder: str, inorder: str):
		# preorder empty -> return None
		if not preorder:
			return None

		root = TreeNode(preorder[0])
		inorder_idx = inorder.find(preorder[0])

		root.left = self.construct(preorder[1:inorder_idx + 1], inorder[:inorder_idx])
		root.right = self.construct(preorder[inorder_idx + 1:], inorder[inorder_idx + 1:])

		return root

	def postorder(self, node: TreeNode):
		if not node:
			return ""

		return self.postorder(node.left) + self.postorder(node.right) + node.val


def main():
	sol = Solution()
	preorder = "ABCDFEG"
	inorder = "BADFCEG"
	root = sol.construct(preorder, inorder)
	print(sol.postorder(root))

if __name__ == '__main__':
	main()
