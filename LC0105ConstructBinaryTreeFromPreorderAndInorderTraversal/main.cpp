#include<iostream>
#include<unordered_map>
#include<vector>


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


class Solution {
    // Time complexity O(N) - each recursion is O(1) and each node has one recursion call. Hashmap building is also O(N)
    // space complexity O(N) - hashmap
public:

};


int main()
{
	cout << "Hello CMake." << endl;
	return 0;
}
