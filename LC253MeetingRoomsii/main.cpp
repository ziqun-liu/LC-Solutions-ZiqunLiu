#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    /**
     * The min-heap priority queue preserves the minimum ending time, that is,
     * the room in which the meeting is ending the earliest
     */
    class PriorityQueue {
    public:
        static int minMeetingRooms(vector<vector<int>> &intervals) {
            sort(intervals.begin(), intervals.end(),
                 [](const vector<int> &a, const vector<int> &b) -> bool {
                     return a[0] < b[0]; // Cannot use std::less<T> here since vector<int> is not directly comparable
                 }
            );

            // This is how a min-heap pq is cleared in C++
            // The second parameter is the underlying container, default to vector<int>
            // The third parameter is a comparator, default to functor std::less<T>
            // Since a non-default third parameter is used, the second parameter cannot be omitted although default
            priority_queue<int, vector<int>, greater<int>> pq;

            for (const vector<int> &interval: intervals) {
                if (!pq.empty() && pq.top() <= interval[0])
                    pq.pop();
                pq.push(interval[1]);
            }

            return pq.size();
        }
    };

    /**
     * I feel that this method is not intuitive.
     * Sort starting times and ending times separately.
     * A meeting's ending makes one room available
     */
    class SortingStartEnd {
    public:
        static int minMeetingRooms(vector<vector<int>> &intervals) {
            int count = 0, result = 0, start = 0, end = 0;
            vector<int> starts(intervals.size());
            vector<int> ends(intervals.size());

            // Propagate two arrays by starting times and ending times
            for (int i = 0; i < intervals.size(); ++i)
                starts[i] = intervals[i][0];
            sort(starts.begin(), starts.end());

            for (int i = 0; i < intervals.size(); ++i)
                ends[i] = intervals[i][1];
            sort(ends.begin(), ends.end());

            // An ending time is smaller than or equal to a starting time
            // suggests that a meeting has concluded, and hence
            // the count of meeting rooms gets decremented.
            while (start < intervals.size()) {
                if (starts[start] >= ends[end]) {
                    ++end;
                    --count;
                } else {
                    ++start;
                    ++count;
                }
                result = max(result, count);
            }
            return result;
        }
    }; // Time complexity O(N logN) - sorting takes nlogn
    // Space complexity O(N) - store two vectors
};

int main() {
    Solution solution;

    vector<vector<int>> intervals = {{0,  30},
                                     {5,  10},
                                     {15, 20}};
    cout << (Solution::PriorityQueue::minMeetingRooms(intervals) == Solution::SortingStartEnd::minMeetingRooms(intervals)) << endl;

    intervals = {{7, 10},
                 {2, 4}};
    cout << (Solution::PriorityQueue::minMeetingRooms(intervals) == Solution::SortingStartEnd::minMeetingRooms(intervals)) << endl;

    return 0;
}
