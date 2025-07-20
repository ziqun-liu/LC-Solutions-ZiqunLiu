"""
Maximum sum of non adjacent elements
100
Medium
Hint
Given an integer array nums of size n. Return the maximum sum possible using the elements of nums such that no two elements taken are adjacent in nums.



A subsequence of array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.


Examples:
Input: nums = [1, 2, 4]

Output: 5

Explanation: [1, 2, 4], the underlined elements are taken to get the maximum sum.

Input: nums = [2, 1, 4, 9]

Output: 11

Explanation: [2, 1, 4, 9], the underlined elements are taken to get the maximum sum.
"""

# =============== 1. Memoization ===================
class Solution:
    def nonAdjacent(self, nums):
		n = len(nums)
    	dp = [float('inf')] * n
		return self.solve(n - 1, nums, dp)

    def solve(self, ind, nums, dp):
    	if ind < 0:
    		return 0
    	if ind == 0:
    		return nums[0]

		if dp[ind] != float('inf'):
			return dp[ind]

    	pick = nums[ind] + self.solve(ind - 2, nums, dp)
    	not_pick = self.solve(ind - 1, nums, dp)
    	dp[ind] = max(pick, not_pick)

    	return dp[ind]
# TC O(n)
# SC O(n + n)

# =============== 2. Tabulation ===================
class Solution2:
    def nonAdjacent(self, nums):
		n = len(nums)
		if n == 0:
			return nums[0]

    	dp = [float('inf')] * n

    	dp[0], dp[1] = nums[0], max(nums[0], nums[1])
    	for i in range(2, n + 1):
	    	pick = nums[i] + dp[i - 2]
	    	not_pick = dp[i - 1】
	    	dp[i] = max(pick, not_pick)

	    return dp[n - 1]

# TC O(n)
# SC O(n)


# =============== 3. Space optimized ===================
class Solution2:
    def nonAdjacent(self, nums):
		n = len(nums)
		if n == 0:
			return nums[0]

    	prev2, prev = nums[0], max(nums[0], nums[1])
    	for i in range(2, n + 1):
	    	pick = nums[i] + prev2
	    	not_pick = prev
	    	curr = max(pick, not_pick)
	    	prev2 = prev
	    	prev = nums[i]

	    return prev

# TC O(n)
# SC O(1)
