#include <iostream>

using namespace std;


// Definition for a binary tree node.
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Codec 
{
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));


int main()
{
    // Input: root = [1,2,3,null,null,4,5]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec ser, deser;
    TreeNode* ans = deser.deserialize(ser.serialize(root));

	return 0;
}
