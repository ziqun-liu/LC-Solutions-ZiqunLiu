"""
6.26. Sequence alignment. 

When a new gene is discovered, a standard approach to understanding its
function is to look through a database of known genes and find close matches. 
The closeness of two genes is measured by the extent to which they are aligned. 

To formalize this, think of a gene as being a long string over an alphabet 
Σ = {A, C, G, T}. Consider two genes (strings) x = ATGCC and y = TACGCA. 

An alignment of x and y is a way of matching up these two strings by writing 
them in columns, for instance:

    –  A  T  –  G  C  C
    T  A  –  C  G  C  A

Here the "–" indicates a "gap." The characters of each string must appear in 
order, and each column must contain a character from at least one of the strings. 

The score of an alignment is specified by a scoring matrix δ of size 
(|Σ| + 1) × (|Σ| + 1), where the extra row and column are to accommodate gaps. 

For instance the preceding alignment has the following score:
    δ(–,T) + δ(A,A) + δ(T,–) + δ(–,C) + δ(G,G) + δ(C,C) + δ(C,A).

Give a dynamic programming algorithm that takes as input two strings x[1...n] 
and y[1...m] and a scoring matrix δ, and returns the highest-scoring alignment. 
The running time should be O(mn).
"""

def sequence_alignment(x, y, delta):
    """
    Find the highest-scoring alignment of two strings.
    
    Args:
        x: first string (length n)
        y: second string (length m)
        delta: scoring matrix function δ(a, b) that returns score for aligning a and b
               (use '–' or '-' to represent gap)
    
    Returns:
        score: the highest alignment score
        alignment: tuple of (aligned_x, aligned_y) showing the optimal alignment
    
    Time complexity: O(mn)
    Space complexity: O(mn)
    """
    n = len(x)
    m = len(y)
    
    # dp[i][j] = max score for aligning x[0:i] and y[0:j]
    dp = [[0] * (m + 1) for _ in range(n + 1)]
    
    # Initialize base cases
    # dp[0][0] = 0 (already set)
    for i in range(1, n + 1):
        dp[i][0] = dp[i-1][0] + delta(x[i-1], '-')
    for j in range(1, m + 1):
        dp[0][j] = dp[0][j-1] + delta('-', y[j-1])
    
    # Fill the dp table
    for i in range(1, n + 1):
        for j in range(1, m + 1):

            # Three choices:
            # 1. Match/mismatch x[i-1] with y[j-1]
            match = dp[i-1][j-1] + delta(x[i-1], y[j-1])

            # 2. Align x[i-1] with gap
            gap_in_y = dp[i-1][j] + delta(x[i-1], '-')

            # 3. Align gap with y[j-1]
            gap_in_x = dp[i][j-1] + delta('-', y[j-1])
            
            dp[i][j] = max(match, increment_i, increment_j)
    
    # Backtrack to find the actual alignment
    aligned_x = []
    aligned_y = []
    i, j = n, m
    
    while i > 0 or j > 0:
        if i > 0 and j > 0 and dp[i][j] == dp[i-1][j-1] + delta(x[i-1], y[j-1]):
            # Match/mismatch
            aligned_x.append(x[i-1])
            aligned_y.append(y[j-1])
            i -= 1
            j -= 1
        elif i > 0 and dp[i][j] == dp[i-1][j] + delta(x[i-1], '-'):
            # Delete from x (gap in y)
            aligned_x.append(x[i-1])
            aligned_y.append('-')
            i -= 1
        else:
            # Insert into x (gap in x)
            aligned_x.append('-')
            aligned_y.append(y[j-1])
            j -= 1
    
    # Reverse because we built it backwards
    aligned_x.reverse()
    aligned_y.reverse()
    
    return dp[n][m], (''.join(aligned_x), ''.join(aligned_y))
