# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Codec:
    # Time complexity O(N) - visit each node once
    # Space complexity O(N) - entire tree created on memeory

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        res = []

        def preorder(node):
            if not node:
                res.append("null")
            else:
                res.append(str(node.val))
                preorder(node.left)
                preorder(node.right)
        
        preorder(root)

        return ','.join(res)

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        nodes_str = data.split(',')
        self.i = 0

        def construct():
            if nodes_str[self.i] == "null":
                self.i += 1
                return None
            else:
                new_node = TreeNode(int(nodes_str[self.i]))
                self.i += 1
                new_node.left = construct()
                new_node.right = construct()
                return new_node 
            # At the end, call stack goes back to the first function call and
            # returns the first node, that is, the head node of the tree
        
        return construct()
        

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))