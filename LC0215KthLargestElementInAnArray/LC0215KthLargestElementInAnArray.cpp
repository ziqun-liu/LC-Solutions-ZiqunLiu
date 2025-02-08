#include<iostream>
#include<queue>
#include<vector>

using namespace std;


class Solution {
public:
	class QuickSelect
	{
	public:
		int findKthLargest(vector<int>& nums, int k) 
		{
			return quickSelect(0, nums.size() - 1, nums, k);
		}

		int quickSelect(int l, int r, vector<int>& nums, int &k)
		{
			int ptr = l;
			for (int i = l; i < r; i++)
			{
				if (nums[i] <= nums[r])
				{
					swap(nums[ptr], nums[i]);
					ptr++;
				}
			}
			swap(nums[ptr], nums[r]);

			if (ptr > nums.size() - k)
				return quickSelect(l, ptr - 1, nums, k);
			else if (ptr < nums.size() - k)
				return quickSelect(ptr + 1, r, nums, k);
			else
				return nums[ptr];
		}
	};


	class Heap
	{
	public:
		int findKthLargest(vector<int>& nums, int k) 
		{
			priority_queue<int, vector<int>, greater<int>> heap;

			for (const int num : nums)
			{
				heap.push(num);
				if (heap.size() > k)
					heap.pop();
			}
			return heap.top();
		}
	};
};


int main()
{
	cout << "Hello CMake." << endl;
	return 0;
}
