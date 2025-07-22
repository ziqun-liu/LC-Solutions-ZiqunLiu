class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        """
        [
            [1,1,0],
            [1,1,0],
            [0,0,1]
        ]
        """
        n = len(isConnected)
        visited = [0] * n
        cnt = 0

        for i in range(n):
            if visited[i] == 0:
                cnt += 1
                self.dfs(i, visited, isConnected)

        return cnt

    def dfs(self, node, visited, isConnected):
        visited[node] = 1
        for i in range(len(isConnected)):
            # 遍历 node 的每个邻居
            # 例：node 是 2，i 从 0 到 2，这样就遍历了 [2][0] [2][1] [2][2]
            if isConnected[node][i] == 1 and visited[i] == 0:
                self.dfs(i, visited, isConnected)
