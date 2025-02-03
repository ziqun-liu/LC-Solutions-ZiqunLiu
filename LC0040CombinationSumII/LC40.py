from typing import List


class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()

        sol, res = [], []

        def dfs(i, curr_sum):
            if curr_sum == target:
                res.append(sol.copy())
                return
            if i == len(candidates) or curr_sum > target:
                return
            
            # Binary tree with n elements: Time O(2^N)
            # Add to res, create copy so time O(N 2^N)
            # Space - call stack O()

            sol.append(candidates[i])
            dfs(i + 1, curr_sum + candidates[i])
            sol.pop()
            
            while i + 1 < len(candidates) and candidates[i] == candidates[i + 1]:
                i += 1

            dfs(i + 1, curr_sum)

        dfs(0, 0)
        return res