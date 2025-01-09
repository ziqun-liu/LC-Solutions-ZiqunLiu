#include<deque>
#include<iostream>
#include<vector>

using namespace std;


class Solution 
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
	{
		// Time complexity O(N) - every element can only be added to the deque once
		// Space complexity O(N)

		deque<int> dq;
		int l = 0;
		vector<int> output(nums.size() - k + 1);

		for (int r = 0; r < nums.size(); ++r)
		{
			// Add a number at the right of deque:
			// compare the right-most element in deque with new number - nums[r]
			// making sure the deque is monotonic, that is no smaller value exists
			while (!dq.empty() && nums[dq.back()] < nums[r])
				dq.pop_back();
			dq.push_back(r);

			// Remove a number from the left of deque
			// check if the left-most element is out of window bound
			if (l > dq.front())
				dq.pop_front();

			// Update result
			if (r + 1 >= k)
			{
				output[l] = nums[dq.front()];
				l++;
			}
		}

		return output;
    }
};


int main()
{
	
	return 0;
}
