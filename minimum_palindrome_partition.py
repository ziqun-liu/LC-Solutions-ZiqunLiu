"""
Given a string s, partition the string into the minimum number of substrings such that every substring is a palindrome.
Return the minimum number of palindromic substrings needed.

Input: s = "banana"
Output: 2
Explanation: The string can be partitioned as ["b", "anana"].
Both "b" and "anana" are palindromes.
"""


def min_palindrome_partition(s):
	n = len(s)

	# Construct is_palindrome matrix
	is_palindrome = [[False] * n for _ in range(n)]

	for j in range(n):  # j is column index
		for i in range(j + 1):  # i is row index
			if i == j:
				is_palindrome[i][j] = True
			elif j == i + 1:
				is_palindrome[i][j] = (s[i] == s[j])
			else:
				is_palindrome[i][j] = (s[i] == s[j] and is_palindrome[i + 1][j - 1])


	# Dp array for min partition
	dp = [float('inf')] * (n + 1)
	dp[0] = 0

	for i in range(1, n + 1):
		for j in range(i):
			if is_palindrome[j][i - 1]:
				dp[i] = min(dp[i], dp[j] + 1)

	return dp[n]
