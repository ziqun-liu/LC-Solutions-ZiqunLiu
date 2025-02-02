from typing import List


class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        # Time O(2^(t/m))
        # Space O(t / m)
        res, sol = [], []

        def dfs(i, curr_sum):
            if curr_sum == target:
                res.append(sol.copy())
                return
            if i == len(candidates) or curr_sum > target:
                return

            sol.append(candidates[i])
            dfs(i, curr_sum + candidates[i])
            sol.pop()
            
            # Skip the current element
            dfs(i + 1, curr_sum)

        dfs(0, 0)
        return res
