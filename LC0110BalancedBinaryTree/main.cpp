#include<iostream>

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
public:
    bool isBalanced(TreeNode* root) 
    {
        return getHeight(root) != -1;
    }

    // DFS Recursion
    int getHeight(TreeNode* node) // return the height of `node`
    { // TC O(N), SC O(N)
        if (!node)
            return 0;

        // post order traversal - left, right, middle
        int leftHeight = getHeight(node->left);
        if (leftHeight == -1)
            return -1;

        int rightHeight = getHeight(node->right);
        if (rightHeight == -1)
            return -1;

        return abs(leftHeight - rightHeight) > 1 ? -1 : 1 + max(leftHeight, rightHeight);
    }
};


int main()
{
	cout << "Hello CMake." << endl;
	return 0;
}
