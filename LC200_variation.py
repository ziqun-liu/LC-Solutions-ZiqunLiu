class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
    	cnt = 0

    	new_col, new_row = len(grid[0]) + 2, len(grid) + 2
    	new_grid = [["1"] * new_col for _ in range(new_row)]

    	for i in range(len(grid)):
    		for j in range(len(grid[0])):
    			new_grid[i + 1][j + 1] = grid[i][j]

    	for i in range(new_row):
    		for j in range(new_col):
    			if new_grid[i][j] == "1":
    				cnt += 1
    				self.dfs(i, j, new_grid)

    	return cnt

    def dfs(self, i, j, grid):
        if (i < 0 or i >= len(grid) or j < 0 or j >= len(grid[0]) or grid[i][j] != '1'):
            return
        
        grid[i][j] = "2"
        # 访问四个方向
        self.dfs(i+1, j, grid)
        self.dfs(i-1, j, grid)
        self.dfs(i, j+1, grid)
        self.dfs(i, j-1, grid)
