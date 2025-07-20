class Solution:
    def __init__(self, text1, text2):
        self.text1 = text1
        self.text2 = text2

    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        # dp[i][j] := lcs of tex1[:i] and text2[:j]
        n, m = len(self.text1), len(self.text2)

        # Tabulation 法：多开一列和一行作为 base case
        dp = [[0] * (m + 1) for _ in range(n + 1)]

        # Memoization 法从右向左，所以 bottom-up 从左向右
        for ind1 in range(1, n + 1):
            for ind2 in range(1, m + 1):
                # 若相等，各退一位
                if self.text1[ind1 - 1] == self.text2[ind2 - 1]:
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1]
                # 若不等，取 text1 退一位与 text2 退一位的大的值
                else:
                    dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1])

        return dp[n][m]


"""
                AB|CD
        A|CD              AB|C
    |CD     A|C        A|C      AB|
          |C   A|    A|   |c

"""

