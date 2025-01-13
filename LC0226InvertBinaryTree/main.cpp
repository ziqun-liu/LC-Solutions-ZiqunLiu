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
    class DFS 
    {
    public:
        static TreeNode* invertTree(TreeNode* root)
        {
            // Time complexity O(N) - visit each node once, each swap takes O(1)
            // Space compleixty O(N) - tree structure Balanced Tree avg time O(logN), 
            // worse case Completely Skewed Tree O(N)
            if (!root)
                return nullptr;

            TreeNode* tmp = root->left;
            root->left = root->right;
            root->right = tmp;

            invertTree(root->left);
            invertTree(root->right);

            return root;

        }
    };

    class BFS
    {
    public:
        static TreeNode* invertTree(TreeNode* root)
        {
            if (!root)
                return nullptr;

            queue<TreeNode*> queue;
            queue.push(root);

            while (!queue.empty())
            {
                TreeNode* node = queue.front();
                queue.pop();
                swap(node->left, node->right);
                if (node->left)
                    queue.push(node->left);
                if (node->right)
                    queue.push(node->right);
            }
            return root;
        }
    };
};




int main()
{

	return 0;
}
