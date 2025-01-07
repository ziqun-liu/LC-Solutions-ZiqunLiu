#include<iostream>
#include<unordered_map>

using namespace std;


class Solution 
{
public:
    bool checkInclusion(string s1, string s2) 
	{ 
		// Time compleixty O(N)
		// Space complexity O(1)


		if (s1.length() > s2.length())
			return false;

		// Use two vectors of length 26 to count the frequency of 
		// each letter in s1 and first s1.length() letters in s2.
		vector<int> s1Count(26, 0);
		vector<int> s2Count(26, 0);

		// a - z 每个字母对应vector的0 - 25索引
		// subtracting 'a' maps the character to its zero-based index
		// 'a' - 'a' = 0
		// 'b' - 'a' = 1
		// Iterator though letters in s1, updating both s1Count and s2Count
		for (int i = 0; i < s1.length(); ++i)
		{
			s1Count[s1[i] - 'a']++;
			s2Count[s2[i] - 'a']++;
		}

		int matches = 0;
		for (int i = 0; i < 26; ++i)
		{ // 遍历 26 个字母（数组索引），统计 s1Count[i] 和 s2Count[i] 相等的字符种类数，存入变量 matches。
			if (s1Count[i] == s2Count[i])
				++matches;
		}

		// Sliding window technique
		int l = 0;
		for (int r = s1.length(); r < s2.length(); ++r)
		{
			if (matches == 26)
				return true;
			
			// right pointer
			int index = s2[r] - 'a'; // new letter, as index
			s2Count[index]++; // the letter count gets incremented
			// If the count of a letter in both array match after increment, increment `matches`
			if (s1Count[index] == s2Count[index]) 
				matches++;
			// If the count of a letter in both array match before increment, decrement `matches`
			// as there was a letter count match before the new letter getting added and 
			// after the new letter getting added there is no match
			else if (s1Count[index] + 1 == s2Count[index])
				matches--;

			// left pointer
			index = s2[l] - 'a';
			s2Count[index]--;
			if (s1Count[index] == s2Count[index])
				matches++;
			else if (s1Count[index] - 1 == s2Count[index])
				matches--;
			++l;
		}

		return matches == 26;

    }
};


int main()
{
	cout << "Hello CMake." << endl;
	return 0;
}
