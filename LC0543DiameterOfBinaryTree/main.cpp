#include <iostream>

using namespace std;


struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


class Solution 
{
    // Time complexity O(N) - N nodes
    // Space complexity O(N) - degenerate binary tree
    // 1. recursion
    // 2. height of tree - the length of the longest path from a node to any leaf node
    // 3. diameter of tree - the longest path between any two nodes in the tree
    // 4. path between two nodes
    //  The path between two nodes is the series of edges connecting them. 
    //  The longest such path in a binary tree, the diameter, 
    //  may pass through the root of a subtree or lie entirely within one of the subtrees. 
    //  For any node, the number of edges in the path is equal to the sum 
    //  of the heights of its left and right subtrees.
public:
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int maxLen = 0;
        dfsHeight(root, maxLen);
        return maxLen;
    }

private:
    // DFS returns max heights in each iteration:
    // At each node, the algorithm calculates max(left, right) + 1
    // max(left, right) + 1, where left and right are the heights of the left and right child 
    // subtrees.This value is then returned to the parent node as part of the DFS traversal.
    int dfsHeight(TreeNode* node, int &result)
    {
        if (!node)
            return 0;

        int left = dfsHeight(node->left, result);
        int right = dfsHeight(node->right, result);

        result = max(left + right, result);

        return max(left, right) + 1;
    }

};



int main()
{
	cout << "Hello CMake." << endl;
	return 0;
}
