#include<iostream>
#include<queue>

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
    class RecursiveDFS 
    {
    public:
        static int maxDepth(TreeNode* root)
        {
            // Time complexity O(N)
            // Space complexity worst case O(N), avg case O(logN)
            if (!root)
                return 0;

            return 1 + max(maxDepth(root->left), maxDepth(root->right));
        }
    };


    class IterativeDFS
    {
    public:
        static int maxDepth(TreeNode* root)
        {

        }
    };


    class BFS
    {
    public:
        static int maxDepth(TreeNode* root)
        {
            if (!root)
                return 0;

            int level = 0;
            queue<TreeNode*> queue;
            queue.push(root);

            while (!queue.empty())
            {
                int size = queue.size();
                for (int i = 0; i < size; ++i)
                {
                    TreeNode* n = queue.front();
                    queue.pop();
                    if (n->left)
                        queue.push(n->left);
                    if (n->right)
                        queue.push(n->right);
                }
                ++level;
            }

            return level;
        }
    };
};




int main()
{
	

	return 0;
}
