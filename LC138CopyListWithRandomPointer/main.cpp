#include<iostream>
#include<unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    class O1SpaceComplexity{
    public:
        static Node* copyRandomList(Node* head) 
        {
            // Time complexity: O(N) traverse the list twice
            // Space complexity: O(1) generate the new list in place

            if (!head)
                return nullptr;

            // Interweave
            for (Node* n = head; n;)
            {
                Node* copy = new Node(n->val);
                copy->next = n->next;
                n->next = copy;
                n = copy->next;
            }
            // The list is now A -> A' -> B -> B' -> C -> C'

            // Copy random pointers
            for (Node* n = head; n; n = n->next->next)
            {
                if (n->random)
                {
                    n->next->random = n->random->next;
                    // A->next is A'. Say A->random is C and then A->random->next is C'. 
                    // This is setting A'->random to C'. Genius
                }
            }

            Node* newHead = head->next; // Here head->next is the copied node

            // Separate the lists
            for (Node* n = head; n; n = n->next)
            {
                Node* copy = n->next;
                n->next = copy->next;
                if (copy->next)
                    copy->next = copy->next->next;
            } // Here head->next is modified to be pointing to "B" like original

            return newHead;

        }
    };

    class TwoPass
    {
    public:
        static Node* copyRandomList(Node* head)
        {
            // Space complexity O(n) - need to traverse while list
            // Time complexity O(n) - need to create a map from each old to each new node

            unordered_map<Node*, Node*> h;
            // 1. copy all nodes while mapping each old node to each new node
            for (Node* cur = head; cur; cur = cur->next)
                h[cur] = new Node(cur->val);

            // 2. assign the "next" and "random" pointers of the new nodes
            for (Node* cur = head; cur; cur = cur->next)
            {
                if (cur->next) h[cur]->next = h[cur->next];
                if (cur->random) h[cur]->random = h[cur->random];
            }
            return h[head];
        }
    };
};

int main()
{
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);

    node1->next = node2;
    node2->next = node3;

    node1->random = node3; // 1 -> 3
    node2->random = node1; // 2 -> 1
    node3->random = node2; // 3 -> 2

    Node* copiedList = Solution::O1SpaceComplexity::copyRandomList(node1);
    Node* anotherList = Solution::TwoPass::copyRandomList(node1);
    
    cout << node1 << endl;
    cout << copiedList << endl;
    cout << endl;

    cout << node1 << endl;
    cout << anotherList << endl;

	return 0;
}
