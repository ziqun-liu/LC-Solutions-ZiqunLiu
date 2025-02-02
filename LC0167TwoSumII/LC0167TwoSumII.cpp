#include<iostream>
#include<vector>

using namespace std;


class Solution 
{
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
	{
		int l = 0, r = numbers.size();

		while (l < r)
		{
			int currSum = numbers[l] + numbers[r];
			if (currSum > target)
				r--;
			else if (currSum < target)
				l++;
			else
				return { l + 1, r + 1 };;
		}
		return {};
    }
};


int main()
{
	cout << "Hello CMake." << endl;
	return 0;
}
