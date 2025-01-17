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


class Solution {     // in-order
    class GlobalMin
    {
    public:
        long long maxVal = LONG_MIN;
        
        bool isValidBST(TreeNode* root)
        {
            if (!root)
                return true;

            bool left = isValidBST(root->left);

            if (root->val > maxVal)
                maxVal = root->val;
            else
                return false;

            bool right = isValidBST(root->right);

            return left && right;
        }
    };


    class Pre 
    {
    public:
        TreeNode* pre = nullptr; // 用来记录前一个节点
        
        bool isValidBST(TreeNode* root) 
        {
            if (root == nullptr) return true;

            bool left = isValidBST(root->left);

            if (pre != nullptr && pre->val >= root->val) 
                return false;
            pre = root; // 记录前一个节点

            bool right = isValidBST(root->right);

            return left && right;
        }
    };


    class Nullptr
    {
    public:
        bool isValidBST(TreeNode* root) 
        {
            return valid(root, nullptr, nullptr);
        }

        bool valid(TreeNode* node, TreeNode* leftBound, TreeNode* rightBound) 
        {
            if (!node)
                return true;

            if ((leftBound && node->val <= leftBound->val) ||
                (rightBound && node->val >= rightBound->val))
                return false;

            return valid(node->left, leftBound, node) &&
                   valid(node->right, node, rightBound);
        }
    };
};


int main()
{
	cout << "Hello CMake." << endl;
	return 0;
}
