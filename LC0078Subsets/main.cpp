#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:

	vector<vector<int>> subsets(vector<int>& nums)
	{
		vector<vector<int>> res;
		backtrack(0, res, {}, nums);
		return res;
	}

	void backtrack(int i, vector<vector<int>>& res, vector<int> subset, vector<int>& nums)
	{
		if (i >= nums.size())
		{
			res.push_back(subset);
			return;
		}

		subset.push_back(nums[i]);
		backtrack(i + 1, res, subset, nums);

		subset.pop_back();
		backtrack(i + 1, res, subset, nums);
	}
};


int main()
{
	Solution sol;
	vector<int> nums = { 3, 1, 2 };
	vector<vector<int>> res = sol.subsets(nums);

	cout << "All subsets:" << endl;
	for (const auto& subset : res) {
		cout << "{ ";
		for (int num : subset) {
			cout << num << " ";
		}
		cout << "}" << endl;
	}

	return 0;
}
