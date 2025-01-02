#include<iostream>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Time complexity O(N) - every node is visited once
        // Space complexity O(1) - only a few pointers are used and no extra memory is used

        ListNode dummy(0, head);
        ListNode* groupPrev = &dummy; // groupPrev is the one node before the group

        while (true) // while-loop keeps running until break is executed
        {
            ListNode* kth = getKth(groupPrev, k);
            if (!kth) // if kth is null break from the loop
                break;

            ListNode* groupNext = kth->next; // The node after the group

            // Do reversing linked list
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            // example. say k = 2
            // groupPrev -> A -> B -> groupNext
            // B is kth
            while (curr != groupNext)
            {
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }
            // ex: B -> A -> groupNext

            // groupPrev is the one node before the group
            // groupPrev->next is the first node of the group before reversal, 
            // and the last node of the group after reversal
            ListNode* tmp = groupPrev->next; // ex: A
            // kth is the last node of the group before reversal, 
            // and the first node of the group after reversal
            groupPrev->next = kth; 
            groupPrev = tmp;
        }
        return dummy.next;
    }
private:
    ListNode* getKth(ListNode* node, int k)
    {
        while (node && k > 0)
        {
            node = node->next;
            --k;
        }
        return node;
    }
};


int main()
{
	cout << "Hello CMake." << endl;
	return 0;
}
