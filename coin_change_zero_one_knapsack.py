"""
Problem 6.18: Bounded Change-Making Problem

Consider the following variation on the change-making problem (Exercise 6.17): 
you are given denominations x1, x2, ..., xn, and you want to make change for 
a value v, but you are allowed to use each denomination at most once. 

For instance, if the denominations are 1, 5, 10, 20, then you can make change 
for 16 = 1 + 15 and for 31 = 1 + 10 + 20 but not for 40 (because you can't 
use 20 twice).

Input: Positive integers x1, x2, ..., xn; another integer v.
Output: Can you make change for v, using each denomination xi at most once?

Show how to solve this problem in time O(nv).
"""

coins = [1, 5, 10, 20], v = 16
n = len(coins)

def coin_change_zero_one_knapsack(coins):
	dp = [[float("inf")] * (v + 1) for _ in range(n + 1)]

	# Base case: amount $0 needs 0 coins
	for i in range(n + 1):
		dp[i][0] = 0

	# Outer loop traverse denomination
		# i is index of denominations
	# Inner loop traverse amount v
	for i in range(1, n + 1):
		for j in range(v + 1):
			if coins[i - 1] <= j:
				dp[i][j] = min(1 + dp[i - 1][j - coins[i - 1]], dp[i - 1][j])
			else:
				dp[i][j] = dp[i - 1][j]

	return dp[n][v] if dp[n][v] != float("inf") else -1


print(coin_change_zero_one_knapsack(coins, 16))  # 3: 1+5+10
print(coin_change_zero_one_knapsack(coins, 31))  # 3: 1+10+20
print(coin_change_zero_one_knapsack(coins, 40))  # -1
print(coin_change_zero_one_knapsack(coins, 6))   # 2: 1+5


def can_change(coins):
	dp = [[False] * (v + 1) for _ in range(n + 1)]

	# Base case: amount $0 alway can get change (trivial)
	for i in range(n + 1):
		dp[i][0] = True

	for i in range(1, n + 1):
		for j in range(v + 1):
			if coins[i - 1] <= j:
				dp[i][j] = dp[i - 1][j] or dp[i - 1][j - coins[i - 1]]
			else:
				dp[i][j] = dp[i - 1][j]

	return dp[n][v]


coins = [1, 5, 10, 20]

print(can_change(coins, 16))  # True: 1+5+10
print(can_change(coins, 31))  # True: 1+10+20
print(can_change(coins, 40))  # False: can't use 20 twice
print(can_change(coins, 6))   # True: 1+5
print(can_change(coins, 100)) # False: exceeds total number of coins