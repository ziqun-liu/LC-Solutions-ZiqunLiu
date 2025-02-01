from typing import List


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        # Time O(N * N!) space O(N) - excluding res
        sol = []
        res = []

        def dfs():
            if len(sol) == len(nums):
                res.append(sol.copy())
                return
            
            for i in nums:
                if i not in sol:
                    sol.append(i)
                    dfs()
                    sol.pop()

        dfs()
        return res

