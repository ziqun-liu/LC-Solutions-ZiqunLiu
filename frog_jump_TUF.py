"""
Frog Jump
A frog wants to climb a staircase with n steps. 
Given an integer array heights, where heights[i] contains the height of the ith step.
To jump from the ith step to the jth step, 
the frog requires abs(heights[i] - heights[j]) energy, where abs() denotes the absolute difference. 
The frog can jump from any step either one or two steps, provided it exists. 
Return the minimum amount of energy required by the frog to go from the 0th step to the (n-1)th step.
一只青蛙想要爬上一个有 n 个台阶的楼梯。给定一个整数数组 heights，其中 heights[i] 表示第 i 个台阶的高度。
要从第 i 个台阶跳到第 j 个台阶，青蛙需要消耗 abs(heights[i] - heights[j]) 的能量，其中 abs() 表示绝对值差。
青蛙可以从任意台阶向前跳跃一步或两步（前提是目标台阶存在）。
返回青蛙从第 0 个台阶到达第 (n-1) 个台阶所需的最少能量。

Examples:
Input: heights = [2, 1, 3, 5, 4]

Output: 2

Explanation: One possible route can be,

0th step -> 2nd Step = abs(2 - 3) = 1

2nd step -> 4th step = abs(3 - 4) = 1

Total = 1 + 1 = 2.

Input: heights = [7, 5, 1, 2, 6]

Output: 9

Explanation: One possible route can be,

0th step -> 1st Step = abs(7 - 5) = 2

1st step -> 3rd step = abs(5 - 2) = 3

3rd step -> 4th step = abs(2 - 6) = 4

Total = 2 + 3 + 4 = 9.
"""

# ============= 1. Recursion ===================
class Solution1:
    def frogJump(self, heights):
        return self.f(len(heights) - 1, heights)
    
    def f(self, ind, heights):
        if ind == 0:
            return 0

        jump_one = self.f(ind - 1, heights) + abs(heights[ind] - heights[ind - 1])
        jump_two = float('inf')
        if ind > 1:
            jump_two = self.f(ind - 2, heights) + abs(heights[ind] - heights[ind - 2])

        return min(jump_one, jump_two)
# TC O(2^n) - 2 sub-problems at every position
# SC O(n) - call stack


# ============= 2. Memoization DP ===================
class Solution2:
	def frogJump(self, heights):
		dp = [-1] * (len(heights))
		return self.f(len(heights) - 1, dp, heights)

	def f(self, ind, dp, heights):
		if ind == 0:
			return 0

		if dp[ind] != -1:
			return dp[ind]

        jump_one = self.f(ind - 1, dp, heights) + abs(heights[ind] - heights[ind - 1])
        jump_two = float('inf')
        if ind > 1:
            jump_two = self.f(ind - 2, dp, heights) + abs(heights[ind] - heights[ind - 2])

        dp[ind] = min(jump_one, jump_two)

        return dp[ind]
# TC O(n) - n sub-problems
# SC O(n) - dp array n, call stack n


# ============= 3. Tabulation DP ===================
class Solution3:
	def frogJump(self, heights):
		n = len(heights)
		dp = [0] * n
		dp[0] = 0

		for i in range(1, n):
        	jump_one = dp[i - 1] + abs(heights[i] - heights[i - 1])
	        jump_two = float('inf')
	        if ind > 1:
	            jump_two = dp[i - 2] + abs(heights[i] - heights[i - 2])
        	dp[i] = min(jump_one, jump_two)

        return dp[n - 1]
# TC O(n) - for loop
# SC O(n) - dp array n


# ============= 4. O(1) space Tabulation DP ===================
class Solution4:
	def frogJump(self, heights):
		n = len(heights)
		if n <= 1:
			return 0

		prev2, prev = 0, abs(heights[1] - heights[0])

		for i in range(2, n):
        	jump_one = prev + abs(heights[i] - heights[i - 1])
            jump_two = prev2 + abs(heights[i] - heights[i - 2])
        	curr = min(jump_one, jump_two)

        	prev2 = prev1
        	prev = curr

        return prev
# TC O(n)
# SC O(1)




# ============= Follow-up ===================
# frog can jump to any step in the range [i + 1, i + k] 

# ============= 1. Recursion ===================
class Solution1:
    def frogJump(self, heights, k):
        return self.f(len(heights) - 1, heights)
    
    def f(self, ind, heights, k):
        if ind == 0:
            return 0

        min_steps = float('inf')
        for j in range(1, k + 1):
	        if ind - j >= 0:
		        jump = self.f(ind - j, heights) + abs(heights[ind] - heights[ind - j])
		        min_steps = min(min_steps, jump)

        return min_steps
# O(2^n * k)
# O(n)

# ============= 2. Memoization DP ===================
class Solution1:
    def frogJump(self, heights, k):
    	n = len(heights)
    	dp = [-1] * n
        return self.f(len(heights) - 1, dp, heights, k)
    
    def f(self, ind, dp, heights, k):
        if ind == 0:
            return 0

        if dp[ind] != -1:
        	return dp[ind]

        min_steps = float('inf')
        for j in range(1, k):
	        if ind - j >= 0:
		        jump = self.f(ind - j, heights) + abs(heights[ind] - heights[ind - j])
		        min_steps = min(min_steps, jump)
        dp[ind] = min_steps
        
        return dp[ind]
# TC O(n * k) 
# SC O(n) - call stack n, array n


# ============= 3. Tabulation DP ===================
class Solution:
    def frogJump(self, heights, k):
    	n = len(heights)
    	dp = [float('inf')] * n
    	dp[0] = 0

    	for i in range(1, n):
    		for j in range(1, k + 1):
    			if i - j >= 0:
    				jump = dp[i - j] + abs(heights[i] - heights[i - j])
    				dp[i] = min(dp[i], jump)

    	return dp[n - 1]
# TC O(n * k)
# SC O(n)
