/*
 * Ziqun Liu
 * https://leetcode.com/problems/sort-list/
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* sortedHead = nullptr;
        ListNode* dummy;
        ListNode* curr;

        while (head != nullptr)
        {
            curr = head;
            head = head->next;
            // The current node is smaller than the head of sorted list
            // or the sorted list is empty
            if (sortedHead == nullptr || curr->val < sortedHead->val)
            {
                curr->next = sortedHead;
                sortedHead = curr;
            }
            // The current node is larger than the head of sorted list
            else
            {
                dummy = sortedHead;
                // Continue to next node and check if curr is smaller
                // Find temp, the node before the insertion point
                while (dummy->next != nullptr && curr->val > dummy->next->val)
                    dummy = dummy->next;
                // Insert current between temp and temp->next
                curr->next = dummy->next;
                dummy->next = curr;
            }
        }
        return sortedHead;
    }
};

/*
 * Worst case time complexity O(N^2)
 */

/*
 * Worst case space complexity O(1)
 */
