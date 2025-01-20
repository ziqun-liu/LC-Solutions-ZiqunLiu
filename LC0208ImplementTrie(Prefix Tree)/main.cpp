#include <any>
#include <iostream>
#include <unordered_map>


using namespace std;


class Trie 
{
    any trie;
public:
    Trie(): trie(unordered_map<char, any>()) {}

    void insert(string word) 
    {
        auto* hm = any_cast<unordered_map<char, any>>(&trie);

        for (char c : word)
        {
            if (hm->find(c) == hm->end())
                (*hm)[c] = unordered_map<char, any>();
            hm = any_cast<unordered_map<char, any>>(&(*hm)[c]);
        }
        (*hm)['.'] = '.';
    }

    bool search(string word) 
    {
        auto* hm = any_cast<unordered_map<char, any>>(&trie);

        for (char c : word)
        {
            if (hm->find(c) == hm->end())
                return false;
            hm = any_cast<unordered_map<char, any>>(&(*hm)[c]);
        }
        return hm->find('.') != hm->end();
    }

    bool startsWith(string prefix) 
    {
        auto* hm = any_cast<unordered_map<char, any>>(&trie);

        for (char c : prefix)
        {
            if (hm->find(c) == hm->end())
                return false;
            hm = any_cast<unordered_map<char, any>>(&(*hm)[c]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */


int main()
{
	cout << "Hello CMake." << endl;
	return 0;
}
