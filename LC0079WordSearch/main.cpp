#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;


class Solution
{
public:
	int ROWS, COLS;
	bool exist(vector<vector<char>>& board, string& word)
	{
		ROWS = board.size(), COLS = board[0].size();
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				if (dfs(i, j, 0, board, word))
					return true;
			}
		}
		return false;
	}

	bool dfs(int r, int c, int i, vector<vector<char>>& board, string& word)
	{
		if (i == word.size())
			return true;
		if (r < 0 || c < 0 ||
			r >= ROWS || c >= COLS ||
			word[i] != board[r][c] || board[r][c] == ' ')
			return false;

		char curr = board[r][c];
		board[r][c] = ' ';
		bool res = dfs(r, c + 1, i + 1, board, word) ||
			       dfs(r, c - 1, i + 1, board, word) ||
			       dfs(r + 1, c, i + 1, board, word) ||
			       dfs(r - 1, c, i + 1, board, word);
		board[r][c] = curr;
		return res;
	}
};


int main()
{
	cout << "Hello CMake." << endl;
	return 0;
}
