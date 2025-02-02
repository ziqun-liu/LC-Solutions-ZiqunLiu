#include<iostream>
#include<vector>

using namespace std;


class Solution 
{
public:
	vector<vector<int>> res;
	vector<int> sol;

    vector<vector<int>> combinationSum(vector<int>& candidates, int& target) 
	{
		dfs(0, 0, candidates, target);
		return res;
    }

	void dfs(int i, int currSum, vector<int>& candidates, int& target)
	{
		if (currSum == target)
		{
			res.emplace_back(sol);
			return;
		}

		if (i == candidates.size() || currSum > target)
			return;

		sol.emplace_back(candidates[i]);
		dfs(i, currSum + candidates[i], candidates, target);
		sol.pop_back();

		dfs(i + 1, currSum, candidates, target);
	}
};


int main()
{
	cout << "Hello CMake." << endl;
	return 0;
}
