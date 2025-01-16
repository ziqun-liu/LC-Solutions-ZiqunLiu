#include<iostream>

using namespace std;


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {
    }
};


class Solution 
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        TreeNode* curr = root;
        while (curr)
        {
            if (p->val > curr->val && q->val > curr->val)
                curr = curr->right;
            else if (p->val < curr->val && q->val < curr->val)
                curr = curr->left;
            else
                return curr;
        }
        return nullptr;
    }
};


int main()
{
	cout << "Hello CMake." << endl;
	return 0;
}
