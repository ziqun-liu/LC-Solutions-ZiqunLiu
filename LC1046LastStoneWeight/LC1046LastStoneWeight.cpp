#include<iostream>
#include<queue>
using namespace std;


class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap;

        for (const int& num : stones)
            heap.push(num);

        while (heap.size() >= 2)
        {
            int a = heap.top();
            heap.pop();
            int b = heap.top();
            heap.pop();
            if (b < a)
                heap.push(a - b);
        }

        heap.push(0);
        return heap.top();
    }
};


int main()
{
	cout << "Hello CMake." << endl;
	return 0;
}
