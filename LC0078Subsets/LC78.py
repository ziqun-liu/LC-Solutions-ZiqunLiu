from typing import List


class Solution:
    # Time O(N2^N) space O(N)
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res, subset = [], []

        def dfs(i):
            if i == len(nums):
                res.append(subset.copy())
                return

            subset.append(nums[i])
            dfs(i + 1)

            # undo the append
            subset.pop()
            dfs(i + 1)

        dfs(0)
        return res

        