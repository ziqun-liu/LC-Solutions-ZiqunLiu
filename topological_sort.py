class Solution:
    # 解决依赖关系排序问题
    # 使每个事物都出现在它所依赖的事物之后
    # 核心思想是：始终选择当前没有前置依赖的元素
    # 只能在有向无环图（DAG）上进行——无向是双向依赖，不行，有环是循环依赖没有明确的起始点，不行
    def topoSort(self, V, edges):
        adj = [[] for _ in range(V)]
        for u, v in edges:
            adj[u].append(v)

        visited = [False for _ in range(V)]
        stk = []
        
        # 主函数做循环和 dfs
        for i in range(V):
            if not visited[i]:
                self.dfs(i, visited, adj, stk)
                
        return stk[::-1]
        
    def dfs(self, node, visited, adj, stk):
        visited[node] = True
        
        # 每个 dfs 做后序遍历——遍历每个节点的邻接节点并进行 dfs
        for neighbor in adj[node]:
            if not visited[neighbor]:
                self.dfs(neighbor, visited, adj, stk)
        
        stk.append(node)
