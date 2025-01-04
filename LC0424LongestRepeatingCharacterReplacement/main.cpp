#include<iostream>
#include<unordered_map>

using namespace std;


/*
	This solution uses sliding window technique with 
two pointers indicating the left and right edge of window.
	As right pointer is moving forward, 
left pointer shrinks the window making sure the condition is met: 
the length of window minus the count of most frequent letter shall not exceed k
*/
class Solution 
{
public:
    int characterReplacement(string s, int k) 
	{
		// Time complexity O(N)
		// Space complexity O(1) - O(26) = O(1)
		unordered_map<char, int> count;
		int l = 0, res = 0, maxFreq = 0;

		for (int r = 0; r < s.size(); ++r)
		{
			++count[s[r]];
			maxFreq = max(maxFreq, count[s[r]]);

			while (r - l + 1 - maxFreq > k)
			{
				--count[s[l]];
				++l;
			}
			res = max(res, r - l + 1);
		}

		return res;
    }
};


int main()
{
	cout << "Hello CMake." << endl;
	return 0;
}
