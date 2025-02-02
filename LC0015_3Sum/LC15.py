class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort() # O(N logN) space O(N)
        
        for i, num in enumerate(nums):
            if i > 0 and num == nums[i - 1]:
                continue

            l, r = i + 1, len(nums) - 1

            while l < r: # nested loop O(N^2)
                three_sum = num + nums[l] + nums[r]
                if three_sum > 0:
                    r -= 1
                elif three_sum < 0:
                    l += 1
                else:
                    res.append([num, nums[l], nums[r]])
                    l += 1
                    while nums[l] == nums[l - 1] and l < r:
                        l += 1
        return res
