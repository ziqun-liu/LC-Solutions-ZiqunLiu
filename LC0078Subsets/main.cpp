#include <iostream>
#include <vector>

using namespace std;


class Solution 
{
public:
	vector<int> subset;
	vector<vector<int>> res;

    vector<vector<int>> subsets(vector<int>& nums) 
	{
		backtrack(0, nums);
		return res;
    }

	void backtrack(int i, vector<int>& nums)
	{
		if (i >= nums.size())
		{
			res.push_back(subset);
			return;
		}

		subset.push_back(nums[i]);
		backtrack(i + 1, nums);

		subset.pop_back();
		backtrack(i + 1, nums);
	}
};


int main()
{
	cout << "Hello CMake." << endl;
	return 0;
}
