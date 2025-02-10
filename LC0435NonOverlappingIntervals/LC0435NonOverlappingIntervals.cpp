#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;


class Solution 
{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
	{
		int res = 0;
		sort(intervals.begin(), intervals.end());
		int prevEnd = intervals[0][1];

		for (int i=1; i<intervals.size(); i++)
		{
			if (intervals[i][0] >= prevEnd)
				prevEnd = intervals[i][1];
			else
			{
				res++;
				prevEnd = min(prevEnd, intervals[i][1]);
			}
		}
		return res;
    }
};


int main()
{
	cout << "Hello CMake." << endl;
	return 0;
}
