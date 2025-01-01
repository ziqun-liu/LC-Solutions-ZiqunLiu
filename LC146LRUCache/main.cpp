#include<iostream>
#include<unordered_map>

using namespace std;

class LRUCache 
{
    class Node
    {
    public:
        int key;
        int value;
        Node* next;
        Node* prev;
        Node(int key, int value) : key(key), value(value), next(nullptr), prev(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> cache; // Map key to node
    Node* dummyHead;
    Node* dummyTail;

public:
    LRUCache(int capacity): capacity(capacity), dummyHead(new Node(0, 0)), dummyTail(new Node(0, 0))
    {
        cache.clear();
        dummyHead->next = dummyTail; // head is Least Recently Used
        dummyTail->prev = dummyHead; // tail is Most Recently Used
    }

    int get(int key) // TC: O(1), SC: O(N) - capacity O(N) and hashmap O(capacity)
    {
        // if the value does not exit, return -1
        if (cache.find(key) == cache.end())
            return -1;

        // Remove node and place at the end of list
        this->remove(cache[key]);
        this->insert(cache[key]);

        return cache[key]->value;
    }

    void put(int key, int value) 
    {
        if (cache.find(key) != cache.end()) // Node exist. Remove value
            this->remove(cache[key]);
        
        // Node does not exist. Insert node
        cache[key] = new Node(key, value);
        this->insert(cache[key]);
            
        if (cache.size() > capacity)
        {
            Node* lru = dummyHead->next;
            this->remove(lru); // Remove from list
            cache.erase(lru->key); // Delete from hashmap
            delete lru;
        }
    }

private:

    void remove(Node* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(Node* node) // insert at the right
    {
        Node* tail = dummyTail->prev;
        tail->next = node;
        node->prev = tail;
        node->next = dummyTail;
        dummyTail->prev = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    LRUCache* lru = new LRUCache(2);

    lru->put(1, 1);
    lru->put(2, 2);
    cout << lru->get(1) << endl; // Output: 1

    lru->put(3, 3);              // Evicts key 2
    cout << lru->get(2) << endl; // Output: -1

    lru->put(4, 4);              // Evicts key 1
    cout << lru->get(1) << endl; // Output: -1
    cout << lru->get(3) << endl; // Output: 3
    cout << lru->get(4) << endl; // Output: 4

    delete lru;
    return 0;
}


/*



*/