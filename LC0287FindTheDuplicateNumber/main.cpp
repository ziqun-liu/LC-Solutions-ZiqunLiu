#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution 
{
public:

    class FastAndSlowPointers // Floyd's tortoise and hare algorithm
    {
    public:
        static int findDuplicate(vector<int>& nums)
        {
            // Time complexity: O(N) - move along array
            // Space complexity: O(1) - no extra space

            int slow = nums[0];
            int fast = nums[0];

            // slow moves one step at a time. fast moves two steps at a time
            do {
                slow = nums[slow];
                fast = nums[nums[fast]];
            } while (slow != fast); // stops at node at which slow meets fast

            slow = nums[0]; // reset slow to beginning
            while (slow != fast)
            { // slow and fast both move one step at a time, until they meet
                slow = nums[slow];
                fast = nums[fast];
            }
            return slow;
        }
    };

    class HashSet
    {
    public:
        static int findDuplicate(vector<int>& nums)
        {
            // Time complexity: O(N)
            // Space complexity: O(N) - hash set
            unordered_set<int> hs;
            for (const int& n : nums)
            {
                if (hs.find(n) != hs.end())
                    return n;
                hs.insert(n);
            }
            return -1;
        }
    };
};

int main()
{

	return 0;
}
