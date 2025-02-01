#include <iostream>
#include <vector>

using namespace std;



class Solution
{
public:
	vector<int> sol;
	vector<vector<int>> res;

	vector<vector<int>> permute(const vector<int>& nums)
	{
		dfs(nums);
		return res;
	}

	void dfs(const vector<int>& nums)
	{
		if (sol.size() == nums.size())
		{
			res.emplace_back(sol);
			return;
		}
		for (const int& num : nums)
		{
			if (!count(sol.begin(), sol.end(), num))
			{
				sol.emplace_back(num);
				dfs(nums);
				sol.pop_back();
			}
		}
	}
};


int main()
{
	cout << "Hello CMake." << endl;
	return 0;
}
