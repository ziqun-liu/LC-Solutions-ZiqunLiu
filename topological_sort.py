# ======================== DFS ======================== 
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

# ======================== Kahn's Algorithm (BFS) ======================== 
from collections import deque

class Solution:
    
    def topoSort(self, V, edges):
        # queue, in_degree, put in_degree is zero into queue
        # TC O(2E + V+2E + V+2E) = O(V + E)
        # SC O(2E + V + V)
        
        in_degree = [0 for _ in range(V)]
        adj = [[] for _ in range(V)]
        dq = deque()
        res = []

        # 1. 构建邻接表
        for u, v in edges:
            adj[u].append(v)
            
        # 2. 计算入度
        for node in range(V):
            for neighbor in adj[node]:
                in_degree[neighbor] += 1
        
        # 3. 初始化：入度为0的节点入队
        for i in range(V):
            if in_degree[i] == 0:
                dq.append(i)
        
        # 4. BFS 
        while dq:
            node = dq.popleft()
            res.append(node)
            for neighbor in adj[node]:
                in_degree[neighbor] -= 1
                if in_degree[neighbor] == 0:
                    dq.append(neighbor)
                    
        # if len(res) != V:
            # 存在环，无法完成拓扑排序
            # return []  # 或抛出异常
                    
        return res
