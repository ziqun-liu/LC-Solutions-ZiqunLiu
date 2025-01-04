#include<iostream>
#include<unordered_set>
#include<unordered_map>

using namespace std;


class Solution {
public:
	class SlidingWindow {
	public:
		static int lengthOfLongestSubstring(string s) {
			/*
			Time complexity O(2N) = O(N) 
			  - outer loop O(N), inner loop O(1) each time, total O(2N)
			    every character is visited twice, once by r and once by l
			Space complexity O(min(N, C)) 
			  - N is the length of the string, and C is the size of the character set.
			    O(N) if all characters in s are distinct
			*/

			unordered_set<char> charSet;
			
			// Initalize left pointer
			int l = 0;
			
			// Initialize result variable
			int res = 0;

			for (int r = 0; r < s.size(); ++r)
			{
				// If value at right pointer was not encountered,
				// increment left pointer, remove value at left pointer, and
				// add value at right pointer
				while (charSet.find(s[r]) != charSet.end())
				{
					charSet.erase(s[l]);
					++l;
				}
				charSet.insert(s[r]);

				// This is the template for result variable
				res = max(res, r - l + 1);
			}
			return res;
		}
	};


	class SlidingWindowOptimal
	{
	public:
		static int lengthOfLongestSubstring(string s) 
		{
			// Time complexity O(N)
			// Space complexity O(min(N, C))
			unordered_map<char, int> mp;
			int l = 0, res = 0;

			for (int r = 0; r < s.size(); ++r)
			{
				if (mp.find(s[r]) != mp.end())
					l = max(mp[s[r]] + 1, l);
				mp[s[r]] = r;
				res = max(res, r - l + 1);
			}

			return res;
		}
	};
};


int main()
{
	cout << "Hello CMake." << endl;
	return 0;
}
