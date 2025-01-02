#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// Definition for singly-linked list.
struct ListNode 
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};


class Solution 
{
public:
	class MergeOneByOne
	{
	public:
		// Time complexity: O(n * k) - k is the total number of lists and n is the total number of nodes across k lists
		// Space complexity: O(1)
		ListNode* mergeKLists(vector<ListNode*>& lists) 
		{
			if (lists.empty())
				return nullptr;

			for (int i = 1; i < lists.size(); ++i)
				lists[i] = merge(lists[i], lists[i - 1]);

			return lists.back();
		}
	private:
		ListNode* merge(ListNode* l1, ListNode* l2) 
		{
			ListNode dummy;
			ListNode* curr = &dummy;

			while (l1 && l2)
			{
				if (l1->val < l2->val)
				{
					curr->next = l1;
					l1 = l1->next;
				} else
				{
					curr->next = l2;
					l2 = l2->next;
				}
				curr = curr->next;
			}

			if (l1)
				curr->next = l1;
			else
				curr->next = l2;

			return dummy.next;
		}
	};


	class DivideAndConquerIteration
	{
		// Time complexity: O(n log(k)) - each merge is O(n)
		// Space complexity: O(k) - k lists
	public:
		ListNode* mergeKLists(vector<ListNode*>& lists)
		{
			if (lists.empty())
				return nullptr;
			// while-loop runs log(k) times, and each time merge() takes O(n) time
			// First iteration of while-loop takes O(k) memory, second iteration takes O(k / 2) memory, etc.
			while (lists.size() > 1) 
			{
				vector<ListNode*> mergedLists;
				for (int i = 0; i < lists.size(); i+=2)
				{
					ListNode* l1 = lists[i];
					ListNode* l2 = (i + 1 < lists.size()) ? lists[i + 1] : nullptr;
					mergedLists.push_back(merge(l1, l2));
				}
				lists = mergedLists;
			}
			return lists[0];
		}
	private:
		ListNode* merge(ListNode*l1, ListNode* l2) // TC O(n), SC O(1)
		{
			ListNode dummy;
			ListNode* curr = &dummy;

			while (l1 && l2)
			{
				if (l1->val < l2->val)
				{
					curr->next = l1;
					l1 = l1->next;
				} else
				{
					curr->next = l2;
					l2 = l2->next;
				}
				curr = curr->next;
			}

			if (l1)
				curr->next = l1;
			else
				curr->next = l2;

			return dummy.next;
		}
	};


	class DivideAndConquerRecursion
	{
	public:
		ListNode* mergeKLists(vector<ListNode*>& lists)
		{
			if (lists.empty())
				return nullptr;

			return divide(lists, 0, lists.size() - 1); // perform log(k) times, each time merge takes n time, thus O(N log(k))
		}

	private:
		ListNode* divide(vector<ListNode*> lists, int l, int r) // TC O(1), SC O(logk)
		{
			// Base cases
			if (l > r)
				return nullptr;
			if (l == r)
				return lists[l];

			int mid = l + (r - l) / 2;
			ListNode* left = divide(lists, l, mid);
			ListNode* right = divide(lists, mid + 1, r);

			return merge(left, right);
		}

		ListNode* merge(ListNode* l1, ListNode* l2) // TC O(n), SC O(1)
		{
			ListNode dummy;
			ListNode* curr = &dummy;

			while (l1 && l2)
			{
				if (l1->val < l2->val)
				{
					curr->next = l1;
					l1 = l1->next;
				} else
				{
					curr->next = l2;
					l2 = l2->next;
				}
				curr = curr->next;
			}

			if (l1)
				curr->next = l1;
			else
				curr->next = l2;

			return dummy.next;
		}
	};


	class Heap
	{
		// Time complexity O(N log(k)) - each node's heap operation takes O(log(k)), and there are N nodes
		// Space complexity O(k) - k lists, store each of their head node
	public:
		ListNode* mergeKLists(vector<ListNode*>& lists)
		{
			if (lists.empty())
				return nullptr;

			auto comparator = [](ListNode* a, ListNode* b) { return a->val > b->val; };
			// Time complexity of min heap is log(k), space complexity is k
			priority_queue<ListNode*, vector<ListNode*>, decltype(comparator)> minHeap(comparator);

			for (ListNode* list : lists) // Time complexity O(k log(k))
			{
				if (list != nullptr)
					minHeap.push(list);
			}

			ListNode dummy;
			ListNode* curr = &dummy;

			while (!minHeap.empty()) // TC O(N log(k))
			{
				ListNode* top = minHeap.top();
				minHeap.pop();
				curr->next = top;
				curr = curr->next;

				if (top->next)
					minHeap.push(top->next); // TC O(log(k)) each push
			}

			return dummy.next;
		}
	};
};


int main()
{

	return 0;
}

/*
1. Space complexity
	At any time, the lists and mergedLists vectors collectively hold references (pointers) to 
all the linked lists being processed. Even though the number of lists is halved in each round, 
the initial storage for k lists dominates.
	The code doesn’t create new list nodes—it only modifies the next pointers of existing nodes.

*/
