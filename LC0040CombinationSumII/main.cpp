#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;


class Solution 
{
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
	{
		vector<vector<int>> res;
		vector<int> sol;

		sort(candidates.begin(), candidates.end());
		dfs(0, 0, candidates, target, sol, res);

		return res;
    }

private:
	void dfs(int i, int currSum, vector<int>& candidates, int target, vector<int>& sol, vector<vector<int>> &res)
	{
		if (currSum == target)
		{
			res.emplace_back(sol);
			return;
		}
		if (currSum > target || i == candidates.size())
			return;

		sol.emplace_back(candidates[i]);
		dfs(i + 1, currSum + candidates[i], candidates, target, sol, res);
		sol.pop_back();

		while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1])
			i++;

		dfs(i + 1, currSum, candidates, target, sol, res);
	}
};


int main()
{
	Solution solution;

	vector<int> candidates = { 10, 1, 2, 7, 6, 5, 1 };
	int target = 8;

	vector<vector<int>> results = solution.combinationSum2(candidates, target);

	cout << "Combinations that sum to " << target << ":\n";
	for (const auto& combination : results)
	{
		cout << "[";
		for (size_t j = 0; j < combination.size(); ++j)
		{
			cout << combination[j];
			if (j < combination.size() - 1) cout << ", ";
		}
		cout << "]\n";
	}

	return 0;
}

