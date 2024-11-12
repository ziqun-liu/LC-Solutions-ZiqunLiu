#include <iostream>
#include <vector>

using namespace std;

/*
 * 1. What the dp array represents: The minimum number of perfect squares each number entry needs
 * 2. Formula
 * 3. Base case: dp[0] = 0
 * 4. Traversal order
 * 5. Derive dp array using an example
 */
class Solution {
public:
    int numSquares(int n) {
        // Primitive array type does not support variable length
        // Need to use a vector
        // Need an array of size n + 1 and filled with value n
        vector<int> dp(n + 1, n);
        dp[0] = 0; // Base case

        for (int i=1; i<=n; ++i)
        {
            for (int j=1; j*j<=i; ++j)
            {
                if (i < j * j) break;
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};

/*
 * Time complexity: O(N * sqrt(N)) outer n, inner sqrt(n)
 */

/*
 * Space complexity: O(N) dp array
 */
