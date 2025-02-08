#include<iostream>
#include<queue>
#include<vector>

using namespace std;


class KthLargest 
{
public:
    priority_queue<int, vector<int>, greater<int>> heap;
    int k;

    KthLargest(int k, vector<int>& nums) : k { k }
    {
        for (const int num : nums)
        {
            heap.push(num);
            if (heap.size() > k)
                heap.pop();
        }
    }

    int add(int val) 
    {
        heap.push(val);
        if (heap.size() > k)
            heap.pop();
        return heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */


int main()
{
	cout << "Hello CMake." << endl;
	return 0;
}
