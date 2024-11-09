from typing import List


class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
        intervals.sort(key=lambda interval: interval[0])

        for i in range(1, len(intervals)):
            if intervals[i - 1][1] > intervals[i][0]:
                return False
        return True


solution = Solution()
intervals = [[0, 30], [5, 10], [15, 20]]
print("True" if solution.canAttendMeetings(intervals) else "False")
