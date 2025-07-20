################### Top-down memoization ###################
def fib1(n, dp):
	if n <= 1:
		return n
	
	if dp[n] != -1:
		return dp[n]

	dp[n] = fib(n - 1, dp) + fib(n - 2, dp)
	return dp[n]

def main():
	n = 5
	dp = [-1 for _ in range(n + 1)]
	print(fib(n, dp))

main()
TC O(n) - call once every num
SC O(n) - call stack n, array n


################### bottom-up tabulation ###################
def fib2(n):
	if n <= 2:
		return n
	dp = [n] * (n + 1)
	dp[0], dp[1] = 0, 1
	for i in range(2, n + 1):
		dp[i] = dp[i - 1] + dp[i - 2]

	return dp[n]

TC O(n)
SC O(n) - array n


################### constant space ###################
def fib3(n):
	if n <= 2:
		return n

	prev2, prev1 = 0, 1

	for i in range(2, n + 1):
		curr = prev + prev2
		prev2 = prev
		prev = curr

	return prev

TC O(n)
SC O(1)