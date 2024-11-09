/*
 * Ziqun Liu
 * https://leetcode.com/problems/sort-list/
 *
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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* mid = getMid(head);
        ListNode* right = mid->next;
        mid->next = nullptr;
        return merge(sortList(head), sortList(right));
    }

private:
    ListNode* getMid(ListNode* head)
    {
        ListNode* slow = head, *fast = head->next; // Note that the fast is set to be head->next
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right)
    {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        while (left && right)
        {
            if (left->val < right->val)
            {
                curr->next = left;
                left = left->next;
            } else
            {
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }
        if (left) curr->next = left;
        else curr->next = right;
        return dummy->next;
    }
};

/*
 * Time complexity O(N log N)
 * Split O(log N)
 * Merge O(N)
 */

/*
 * Space complexity
 * O (log N)
 * no extra space is needed, only log(n) recursive layers
 */