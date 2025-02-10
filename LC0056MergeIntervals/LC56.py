from typing import List


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key = lambda k: k[0])
        res = [intervals[0]]

        for interval in intervals:
            if interval[0] > res[-1][1]:
                res.append(interval)
            else:
                res[-1][1] = max(interval[1], res[-1][1])

        return res