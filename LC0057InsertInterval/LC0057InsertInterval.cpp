#include<iostream>
#include<vector>

using namespace std;


class Solution 
{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
	{
		vector<vector<int>> res;

		for (int i = 0; i < intervals.size(); i++)
		{
			// Non-overlapping case 1
			if (newInterval[1] < intervals[i][0])
			{
				res.push_back(newInterval);
				res.insert(res.end(), intervals.begin() + i, intervals.end());
				return res;
				// copy(intervals.begin() + i, intervals.end(), back_inserter(res));
			} 
			// Non-overlapping case 2
			else if (newInterval[0] > intervals[i][1])
				res.push_back(intervals[i]);
			// Overlapping - update newInterval
			else
				newInterval = { min(intervals[i][0], newInterval[0]), max(intervals[i][1], newInterval[1]) };
		}
		res.push_back(newInterval);
		return res;
    }
};


int main()
{
	cout << "Hello CMake." << endl;
	return 0;
}
