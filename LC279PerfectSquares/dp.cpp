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
    int numSquares(int n) { // Bottom-up from n is zero
        // Primitive array type does not support variable length
        // Need to use a vector
        // Need an array of size n + 1 and filled with value n
        vector<int> dp(n + 1, n);
        dp[0] = 0; // Base case

        for (int target = 1; target <= n; ++target) {
            for (int j = 1; j * j <= target; ++j) { // j < sqrt(n)
                // target - j*j is the remaining smaller problem
                dp[target] = min(dp[target], dp[target - j * j] + 1);
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
