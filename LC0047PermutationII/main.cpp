#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;


class Solution 
{
public:
	vector<int> sol;
	vector<vector<int>> res;
	unordered_map<int, int> hm;

    vector<vector<int>> permuteUnique(const vector<int>& nums)
	{
		for (const int& num : nums)
			hm[num]++;

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

		for (auto it=hm.begin(); it!=hm.end(); it++)
		{
			if (it->second)
			{
				sol.emplace_back(it->first);
				hm[it->first]--;
				dfs(nums);

				hm[it->first]++;
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
