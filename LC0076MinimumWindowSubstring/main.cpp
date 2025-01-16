#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;


class Solution 
{
public:
    string minWindow(string s, string t) 
	{
		// Time complexity O(N) - iterate through string s
		// Space complexity O(M) - number of unique chars in string t

		if (t.empty())
		{
			return "";
		}

		unordered_map<char, int> targetMap;
		unordered_map<char, int> windowMap;

		for (char& c : t)
		{
			targetMap[c]++;
		}
		
		int need = targetMap.size();
		int l = 0, have = 0, minLen = INT_MAX;
		pair<int, int> res = { -1, -1 };

		for (int r = 0; r < s.length(); ++r)
		{
			if (targetMap.contains(s[r]))
			{
				windowMap[s[r]]++;
				if (windowMap[s[r]] == targetMap[s[r]]) // once comparison
					++have;
			}
			
			while (have == need) // once comparison
			{
				if (r - l + 1 < minLen)
				{
					minLen = r - l + 1;
					res = { l, r };
				}

				windowMap[s[l]]--;
				
				// windowMap[s[l]] < targetMap[s[l]] is needed because
				// each letter can have numerous occurrances
				if (targetMap.contains(s[l]) && windowMap[s[l]] < targetMap[s[l]])
					--have;

				++l;
			}
		}
		return minLen == INT_MAX ? "" : s.substr(res.first, minLen);
    }
};


int main()
{
	

	return 0;
}
