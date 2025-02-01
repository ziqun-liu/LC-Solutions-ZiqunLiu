from typing import List


class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        sol, res = [], []
        hm = {num : 0 for num in nums}
        for num in nums:
            hm[num] += 1

        def dfs():
            if (len(sol) == len(nums)):
                res.append(sol.copy())
                return
            for num in hm:
                if hm[num]:
                    # Pick a number
                    sol.append(num)
                    hm[num] -= 1
                    dfs()

                    # Remove the number picked hence prepare for the next iteration
                    hm[num] += 1
                    sol.pop()
                    
        dfs()
        return res