#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;


class Solution 
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
	{
        // Time O(N log N) - sorting over
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res = { intervals[0] };

        for (vector<int> &v: intervals)
        {
            if (v[0] > res.back()[1])
                res.push_back(v);
            else
                res.back()[1] = max(res.back()[1], v[1]);
        }

        return res;
    }
};


int main() {
    vector<vector<int>> intervals = {
        {1, 3}, {2, 6}, {8, 10}, {15, 18}
    };

    Solution solution;
    vector<vector<int>> merged = solution.merge(intervals);

    cout << "Merged Intervals: ";
    for (const auto& interval : merged) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
