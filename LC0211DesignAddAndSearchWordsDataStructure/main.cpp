#include <iostream>
#include <unordered_map>

using namespace std;


class TrieNode
{
public:
    unordered_map<char, TrieNode*> children;
    bool word;
};


class WordDictionary 
{
    TrieNode *root;
public:
    WordDictionary(): root(new TrieNode()) {}

    void addWord(string word) 
    {
        TrieNode *curr = root;
        for (char c : word)
        {
            if (curr->children.find(c) == curr->children.end())
                curr->children[c] = new TrieNode();
            curr = curr->children[c];
        }
        curr->word = true;
    }

    bool search(string word) 
    {

    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */


int main()
{
	cout << "Hello CMake." << endl;
	return 0;
}
