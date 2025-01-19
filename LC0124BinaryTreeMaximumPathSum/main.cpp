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
    int maxPath = INT_MIN; // Result variable
public:
    int maxPathSum(TreeNode* root) 
    {
        dfs(root);
        return maxPath;
    }

    int dfs(TreeNode* node)
    {
        // What is being returned each time of recursion is a value that does not allow split from current root node
        // What is calculated as maxPath is a value that allows split
        if (!node)
            return 0;
        
        int leftMax = max(0, dfs(node->left));
        int rightMax = max(0, dfs(node->right));

        // Result is allowed to split
        maxPath = max(maxPath, node->val + leftMax + rightMax);

        // Return cannot split
        return node->val + max(leftMax, rightMax);
    }
};


int main()
{
	cout << "Hello CMake." << endl;
	return 0;
}
