"""
Yuckdonald's Restaurant Location Problem

Yuckdonald's is considering opening a series of restaurants along Quaint Valley 
Highway (QVH). The n possible locations are along a straight line, and the 
distances of these locations from the start of QVH are, in miles and in 
increasing order, m_1, m_2, ..., m_n. 

The constraints are as follows:

- At each location, Yuckdonald's may open at most one restaurant. The expected 
  profit from opening a restaurant at location i is p_i, where p_i > 0 and 
  i = 1, 2, ..., n.

- Any two restaurants should be at least k miles apart, where k is a positive 
  integer.

Goal: Give an efficient algorithm to compute the maximum expected total profit 
subject to the given constraints.
"""
positions = [1, 3, 6, 8, 12]
profits = [5, 6, 5, 3, 8]
k = 3
n = len(positions)

# f is the max expected total profit
# i is the number of positions considered so we need to express the state of i = 1
# therefore need n + 1 length array
def f(i):
	if i == 0:
		return 0

	not_take = f(i - 1)

	j = i - 1
	while j > 0 and positions[i - 1] - positions[j - 1] < k:
		j -= 1

	take = f(j) + profits[i - 1]

	return max(not_take, take)


memo = [-1] * (n + 1)
def memoization(i, memo):
	if i == 0:
		return 0

	if memo[i] != -1:
		return memo[i]

	not_take = memoization(i - 1, memo)

	j = i - 1
	while j > 0 and positions[i - 1] - positions[j - 1] < k:
		j -= 1

	take = memoization(j, memo) + profits[i - 1]

	memo[i] = max(take, not_take)
	return memo[i]


dp = [0] * (n + 1)
def tabulation(dp):
	for i in range(1, n + 1):
		j = i - 1
		while j > 0 and positions[i - 1] - positions[j - 1] < k:
			j -= 1
		dp[i] = max(dp[i - 1], dp[j] + profits[i - 1])

	return dp[n]

