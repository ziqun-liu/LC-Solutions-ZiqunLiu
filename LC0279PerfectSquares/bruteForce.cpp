#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSquares(int n)
    {
        // Create an array of perfect square numbers
        vector<int> squaresVec;
        for (int i=1; i<sqrt(n)+1; ++i)
            squaresVec.push_back(i*i);

        return minNumSquares(n, squaresVec);
    }

private:
    int minNumSquares(int num, const vector<int>& squareVec)
    {
        // Base case of recursion
        if (find(squareVec.begin(), squareVec.end(), num) != squareVec.end()) return 1;

        int result = INT_MAX;
        for (const int& square : squareVec)
        {
            if (square > num) break;
            // Keep count of each layer of call stack
            int currCount = 1 + minNumSquares(num - square, squareVec);
            result = min(result, currCount);
        }
        return result;
    }
};
