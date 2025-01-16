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
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        // Time complexity O(N) - visit every node once
        // Space complexity O(N) - degenerate tree
        if (!p && !q)
            return true;
        if (p && q && p->val == q->val)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        else
            return false;
    }
};


int main()
{
	cout << "Hello CMake." << endl;
	return 0;
}
