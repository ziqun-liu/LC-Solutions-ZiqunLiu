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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Time complexity: O(n) - traverse two lists
        // Space complexity: O(n) - two lists

        ListNode dummy;
        ListNode* curr = &dummy;
        int carry = 0;

        while (l1 || l2 || carry)
        {
            int sum = carry;
            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }

        return dummy.next;
    }
};

int main()
{
    ListNode A(3);
    ListNode B(4, &A);
    ListNode C(2, &B);

    ListNode I(4);
    ListNode II(6, &I);
    ListNode III(5, &II);

    Solution solution;
    ListNode* result = solution.addTwoNumbers(&C, &III);

    while (result) {
        cout << result->val;
        if (result->next) cout << " -> ";
        ListNode* toDelete = result;
        result = result->next;
        delete toDelete;
    }
    cout << endl;

	return 0;
}
