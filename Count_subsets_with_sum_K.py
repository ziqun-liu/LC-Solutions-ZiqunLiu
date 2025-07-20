"""
Count subsets with sum K
Hint
Given an array arr of n integers and an integer K, count the number of subsets 
of the given array that have a sum equal to K. Return the result modulo (109 + 7).


Examples:
Input: arr = [2, 3, 5, 16, 8, 10], K = 10
Output: 3
Explanation: The subsets are [2, 8], [10], and [2, 3, 5].

Input: arr = [1, 2, 3, 4, 5], K = 5
Output: 3
Explanation: The subsets are [5], [2, 3], and [1, 4].

Constraints:
 1 <= n <= 100
1 <= arr[i] <= 103
1 <= K <= 103
"""

# ================ Memoization ================
class Solution:
    def perfectSum(self, arr, K):
        dp = [[-1] * (K + 1) for _ in range(len(arr))]

        return self.f(len(arr) - 1, K, arr, dp)
     
    def f(self, ind, target, arr, dp):
        # f(ind, target) signifies that how many subsets there are till the ind position
        # Explore all posibilities: pick & not_pick
        # sum all possibilities and return

        # Base case
        if target == 0:
            return 1

        if ind == 0:
            return 1 if arr[0] == target else 0

        if dp[ind][target] != -1:
            return dp[ind][target]

        # All possibilities
        not_pick = self.f(ind - 1, target, arr, dp)
        pick = 0
        if arr[ind] <= target:
            pick = self.f(ind - 1, target - arr[ind], arr, dp)

        # Sum all possibilities
        dp[ind][target] = pick + not_pick

        return dp[ind][target]


# ================ Tabulation ================
class Solution:
    def perfectSum(self, arr, K):
        """
        dp = [  K + 1 columns
                 [0,x,x,x,x]
      n rows     [0,x,x,x,x]
                 [0,x,x,x,x]        
            ]
        """
        dp = [[0] * (K + 1) for _ in range(len(arr))]

        # Base case
        for i in range(len(arr)):
            dp[i][0] = 1

        if arr[0] <= K:
            dp[0][arr[0]] = 1

        # All possibilities
        for ind in range(1, len(arr)):
            for target in range(K + 1):
                not_pick = dp[ind - 1][target]
                pick = 0
                if arr[ind] <= target:
                    pick = dp[ind - 1][target - arr[ind]]
                # Sum all possibilities
                dp[ind][target] = pick + not_pick

        return dp[len(arr) - 1][K]


# ================ Space-optimized ================
class Solution:
    def perfectSum(self, arr, K):
        prev = [0] * (K + 1)

        # Base cases
        prev[0] = 1

        if arr[0] <= K:
            prev[arr[0]] = 1

        # All possibilities
        for ind in range(1, len(arr)):
        	curr = [0] * (K + 1)
            for target in range(K + 1):
                not_pick = prev[target]
                pick = 0
                if arr[ind] <= target:
                    pick = prev[target - arr[ind]]
                # Sum all possibilities
                curr[target] = pick + not_pick
            prev = curr

        return prev[K]
