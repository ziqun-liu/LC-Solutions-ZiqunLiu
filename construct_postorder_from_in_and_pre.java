class Solution {
    private Map<Character, Integer> inorderMap;
    
    public TreeNode construct(String preorder, String inorder) {
        // 预处理：建立字符到索引的映射
        inorderMap = new HashMap<>();
        for (int i = 0; i < inorder.length(); i++) {
            inorderMap.put(inorder.charAt(i), i);
        }
        
        return buildTree(preorder, 0, preorder.length() - 1, 
                        inorder, 0, inorder.length() - 1);
    }
    
    private TreeNode buildTree(String preorder, int preStart, int preEnd,
                              String inorder, int inStart, int inEnd) {
        if (preStart > preEnd) return null;
        
        TreeNode root = new TreeNode(preorder.charAt(preStart));
        int inorderIdx = inorderMap.get(root.val); // O(1) 查找
        int leftSize = inorderIdx - inStart;
        
        root.left = buildTree(preorder, preStart + 1, preStart + leftSize,
                             inorder, inStart, inorderIdx - 1);
        root.right = buildTree(preorder, preStart + leftSize + 1, preEnd,
                              inorder, inorderIdx + 1, inEnd);
        
        return root;
    }
}