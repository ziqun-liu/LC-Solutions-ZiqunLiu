#include<iostream>
#include<queue>

using namespace std;


class Solution 
{
public:
	class MaxHeapWithSelfDefinedComparator {
	public:
		struct less
		{
			bool operator()(const vector<int>& a, const vector<int>& b)
			{
				return pow(a[0], 2) + pow(a[1], 2) < pow(b[0], 2) + pow(b[1], 2);
			}
		};

		vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
		{
			priority_queue<vector<int>, vector<vector<int>>, less> heap;

			for (const vector<int>& point : points)
			{
				heap.push(point);
				if (heap.size() > k)
					heap.pop();
			}

			vector<vector<int>> res;
			while (!heap.empty())
			{
				res.push_back(heap.top());
				heap.pop();
			}
			return res;
		}
	};


	class MaxHeap
	{
	public:
		vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
			// Default is max-heap
			// Max-heap: store {negative distance, x, y}
			priority_queue<vector<int>> heap;

			for (const vector<int>& point : points) {
				int dist = pow(point[0], 2) + pow(point[1], 2);
				heap.push({ -dist, point[0], point[1] });  // Use negative distance

				if (heap.size() > k)
					heap.pop();  // Remove the farthest point
			}

			// Extract k closest points from heap
			vector<vector<int>> res;
			while (!heap.empty()) {
				res.push_back({ heap.top()[1], heap.top()[2] });  // Extract x, y
				heap.pop();
			}
			return res;
		}
	};


	class MinHeap {
	public:
		struct greater
		{
			bool operator()(const vector<int>& a, const vector<int>& b)
			{
				return pow(a[0], 2) + pow(a[1], 2) > pow(b[0], 2) + pow(b[1], 2);
			}
		};

		vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
		{
			priority_queue<vector<int>, vector<vector<int>>, greater> heap;

			for (const vector<int>& point : points)
				heap.push(point);

			vector<vector<int>> res;
			for (int i=0; i<k; i++)
			{
				res.push_back(heap.top());
				heap.pop();
			}
			return res;
		}
	};
};


int main() {
	vector<vector<int>> points = { {3, 3}, {5, -1}, {-2, 4} };
	int k = 2;

	Solution sol;
	vector<vector<int>> result = sol.kClosest(points, k);

	// Print the output
	for (const auto& point : result) {
		cout << "[" << point[0] << ", " << point[1] << "] ";
	}
	cout << endl;

	return 0;
}

