from typing import List


class Recursion:  # SC O(M+N), TC O(2^(M+N))
    def longest_common_subsequence(self, s1: str, s2: str) -> int:
        return self.lcs(s1, s2, len(s1) - 1, len(s2) - 1)

    def lcs(self, s1: str, s2: str, ind1: int, ind2: int):
        if ind1 < 0 or ind2 < 0:
            return 0

        if s1[ind1] == s2[ind2]:
            return 1 + self.lcs(s1, s2, ind1 - 1, ind2 - 1)

        return max(self.lcs(s1, s2, ind1 - 1, ind2), self.lcs(s1, s2, ind1, ind2 - 1))


class Memoization:  # SC O(MN + M+N) = O(MN), TC O(MN)
    def longest_common_subsequence(self, s1: str, s2: str) -> int:
        m, n = len(s1), len(s2)
        memo = [[-1 for _ in range(n)] for _ in range(m)]
        return self.lcs(s1, s2, len(s1) - 1, len(s2) - 1, memo)

    def lcs(self, s1: str, s2: str, ind1: int, ind2: int, memo: List[List[int]]) -> int:
        if ind1 < 0 or ind2 < 0:
            return 0

        if memo[ind1][ind2] != -1:
            return memo[ind1][ind2]

        if s1[ind1] == s2[ind2]:
            memo[ind1][ind2] = 1 + self.lcs(s1, s2, ind1 - 1, ind2 - 1, memo)
            return memo[ind1][ind2]

        memo[ind1][ind2] = max(self.lcs(s1, s2, ind1 - 1, ind2, memo), self.lcs(s1, s2, ind1, ind2 - 1, memo))
        return memo[ind1][ind2]


class Tabulation:  # SC O(MN), TC O(MN)
    def longest_common_subsequence(self, s1: str, s2: str) -> int:
        m, n = len(s1), len(s2)

        dp = [[0 for _ in range(n + 1)] for _ in range(m + 1)]

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if s1[i-1] == s2[j-1]:
                    dp[i][j] = 1 + dp[i-1][j-1]
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])

        return dp[m][n]

class SpaceOptimized:  # SC O(N), TC O(MN)
    def longest_common_subsequence(self, s1: str, s2: str) -> int:
        m, n = len(s1), len(s2)

        # Use two arrays SC O(2N) = O(N)
        prev = [0] * (n + 1)
        curr = [0] * (n + 1)

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if s1[i-1] == s2[j-1]:
                    curr[j] = 1 + prev[j-1]
                else:
                    curr[j] = max(prev[j], curr[j-1])
            prev = curr.copy()

        return prev[n]


class SpaceOptimized2:
    def longest_common_subsequence(self, s1: str, s2: str) -> int:
        m, n = len(s1), len(s2)

        # Use one array SC O(N)
        dp = [0] * (n + 1)

        for i in range(1, m + 1):
            prev_diagonal = 0
            for j in range(1, n + 1):
                temp = dp[j]
                if s1[i-1] == s2[j-1]:
                    dp[j] = 1 + prev_diagonal
                else:
                    dp[j] = max(dp[j], dp[j-1])
                prev_diagonal = temp

        return dp[n]


def main():
    currPassword = "password"
    newPassword = "pss$w#rd"


    rec = Recursion()
    mem = Memoization()
    tab = Tabulation()
    spa1 = SpaceOptimized()
    sp2 = SpaceOptimized2()
    length1 = rec.longest_common_subsequence(currPassword, newPassword)
    length2 = mem.longest_common_subsequence(currPassword, newPassword)
    length3 = tab.longest_common_subsequence(currPassword, newPassword)
    length4 = spa1.longest_common_subsequence(currPassword, newPassword)
    length5 = sp2.longest_common_subsequence(currPassword, newPassword)
    print(length1, length2, length3, length4, length5)  # p s s w r d


    """
    Variation
    The minimum number of insertions + deletions:
     
    return len(a) + len(b) − 2·LCS(a, b)

    Let L be the length longest common subsequence of strings a and b.

    To turn a into L, you must delete every character of a that isn’t in L: that’s len(a) − L deletions.

    From L to b, you must insert every character that b has beyond L: that’s len(b) − L insertions.

    Total minimum operations (when only insertions and deletions are allowed) is:

    (len(a) − L) + (len(b) − L) = len(a) + len(b) - 2L
    """

    """
    Variation
    The minimum number of insertions + deletions + substitutions:
    
    In this case, the algorithm need to change.
    """
    def levenshtein(a: str, b: str) -> int:
        m, n = len(a), len(b)
        dp = [list(range(n + 1))] + [[i] + [0] * n for i in range(1, m + 1)]
        """
        dp =
        [
          [0, 1, 2, 3, 4],   # row 0
          [1, 0, 0, 0, 0],   # row 1
          [2, 0, 0, 0, 0],   # row 2
          [3, 0, 0, 0, 0]    # row 3
        ]
        """
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if a[i - 1] == b[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    dp[i][j] = 1 + min(
                        dp[i - 1][j],  # delete
                        dp[i][j - 1],  # insert
                        dp[i - 1][j - 1]  # substitute
                    )
        return dp[m][n]

if __name__ == '__main__':
    main()
