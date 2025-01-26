#include<iostream>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<vector>

using namespace std;


class TrieNode
{
public:
	unordered_map<char, TrieNode*> children;
	bool isWord;

	TrieNode(): isWord(false) {}
	~TrieNode()
	{
		for (auto& keyValuePair : children)
			delete keyValuePair.second;
	}

	void addWord(const string &word)
	{
		TrieNode* curr = this;
		for (const char& c : word)
		{
			if (curr->children.find(c) == curr->children.end())
				curr->children[c] = new TrieNode();
			curr = curr->children[c];
		}
		curr->isWord = true;
	}
};


class Solution 
{
	int ROWS, COLS;
	unordered_set<string> res;
	vector<vector<bool>> visited;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
	{
		TrieNode* root = new TrieNode();
		for (const string& word : words)
			root->addWord(word);
		
		ROWS = board.size();
		COLS = board[0].size();
		visited.assign(ROWS, vector<bool>(COLS, false));

		for (int r = 0; r < ROWS; ++r)
		{
			for (int c = 0; c < COLS; ++c)
			{
				dfs(board, r, c, root, "");
			}
		}
		return vector<string>(res.begin(), res.end());
    }

	void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node, string word)
	{
		if (r < 0 || c < 0 ||
			r == ROWS || c == COLS ||
			node->children.find(board[r][c]) == node->children.end() ||
			visited[r][c] == true)
			return;

		visited[r][c] = true;
		node = node->children[board[r][c]];
		word += board[r][c];
		if (node->isWord)
			res.insert(word);

		dfs(board, r + 1, c, node, word);
		dfs(board, r - 1, c, node, word);
		dfs(board, r, c + 1, node, word);
		dfs(board, r, c - 1, node, word);
		visited[r][c] = false;
	}
};


int main()
{
	cout << "Hello CMake." << endl;
	return 0;
}
