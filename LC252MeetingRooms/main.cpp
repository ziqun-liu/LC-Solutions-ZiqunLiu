#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:

    /**
     * Define disjoint
     * Two intervals are disjoint if and only if
     * the end time of one interval is smaller than or equal to the start time of the other interval
     * @param interval1
     * @param interval2
     * @return Boolean
     */
    static bool disjoint(const vector<int>& interval1, const vector<int>& interval2)
    {
        return interval1[1] <= interval2[0] || interval2[1] <= interval1[0];
    }

    /**
     * Define overlap
     * Two intervals are overlapping if and only if the negation of disjoint
     * @return
     */
    static bool overlap(const vector<int>& interval1, const vector<int>& interval2)
    {
        return interval1[1] > interval2[0] && interval2[1] > interval1[0];
    }


    class OrderedBruteForce
    {
    public:
        static bool canAttendMeetings(const vector<vector<int>>& intervals)
        {
            for (int i=0; i<intervals.size(); ++i)
            {
                for (int j=0; j<i; ++j)
                {
                    if (overlap(intervals[i], intervals[j]))
                        return false;
                }
            }
            return true;
        }
    }; // Time Complexity: O(n^2) Space Complexity: O(1)


    class Sorting
    {
    public:
        /**
         * Sort according to starting time
         * Traverse and compare ending time
         * @param intervals
         * @return
         */
        static bool canAttendMeetings(vector<vector<int>>& intervals)
        {
            // Can't use const reference as intervals are modified during sorting
            // Use a custom comparator and define a lambda function as the custom comparator
            sort(intervals.begin(), intervals.end(), [](const vector<int>& interval1, const vector<int>& interval2) -> bool
            {
                return interval1[0] < interval2[0];
            });

            for (int i = 1; i < intervals.size(); i++)
            {
                if (intervals[i - 1][1] > intervals[i][0])
                    return false;
            }
            return true;
        }
    }; // Time Complexity: O(nlogn) Space Complexity: O(1)

};

int main()
{
    vector<vector<int>> intervals1 = {{0, 30}, {5, 10}, {15, 20}};
    cout << (Solution::OrderedBruteForce::canAttendMeetings(intervals1) ? "True" : "False") << endl; // False

    vector<vector<int>> intervals2 = {{7, 10}, {2, 4}};
    cout << (Solution::OrderedBruteForce::canAttendMeetings(intervals2) ? "True" : "False") << endl; // True

    cout << (Solution::Sorting::canAttendMeetings(intervals1) ? "True" : "False") << endl;
    cout << (Solution::Sorting::canAttendMeetings(intervals2) ? "True" : "False") << endl;

    return 0;
}
