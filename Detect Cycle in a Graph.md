# Detect Cycle in a Graph

## Q1. Detect cycle in an undirected graph

可以用 BFS 也可以用 DFS

##### DFS 

- 需要一个 visited array
- 外层循环跑 V 次解决多个 component 的情况
- dfs 函数可以理解为前序，先把当前节点标记已访问

```python
class Solution:
    """
        TC O(V + 2E + V) = O(V + E) - V is number of nodes, 2E is number of neighbors, V is number of components
        SC O(V + V) = O(V) - V is recursive call stack, V is visited array
    """
	def isCycle(self, V, edges):
        adj_list = [[] for _ in range(V)]
        
        for u, v in edges:
            adj_list[u].append(v)
            adj_list[v].append(u)
            
        visited = [False] * V
        
        for i in range(V):
            if not visited[i]:
                if self.detect(i, -1, adj_list, visited):
                    return True
                    
        return False
        
    def detect(self, node, parent, adj_list, visited):
        visited[node] = True
        
        for nei in adj_list[node]:
            if not visited[nei]:
                if (self.detect(nei, node, adj_list, visited)):
                    return True
            elif nei != parent:
                return True
                
        return False
```

##### BFS

- Queue 需要保存父节点 (node, parent)
- bfs 当邻节点已被访问且不为父节点时检测到环

## Q2. Detect cycle in a directed graph

两种方法：DFS，Kahn's Algorithm(BFS + in_degree)

##### DFS

- 除了 visited 数组，还需要 path_visited 数组追踪路径
- dfs 函数可以理解为后序遍历的一个变体——先 dfs 遍历未访问的邻节点，再恢复路径标注成未访问

```python
class Solution:
    # TC O(V + 2E + V) = O(V + E)
    # SC O(2V + V) = O(V)
    def isCycle(self, V, edges):
        adj_list = [[] for _ in range(V)]
        for u, v in edges:
            adj_list[u].append(v)

        visited = [False for _ in range(V)]
        path_visited = [False for _ in range(V)]
        
        # Outer loop makes sure all nodes, including nodes that 
        # are not reachable by one dfs call stack, are reached
        for i in range(V):
            if not visited[i]:
                if self.dfs(i, visited, path_visited, adj_list):
                    return True
                    
        return False
        
    def dfs(self, node, visited, path_visited, adj):
        visited[node] = True
        path_visited[node] = True
        
        for neighbor in adj[node]:
            # 1. If neighbor is not visited, certainly is not on path either. Do dfs
            if not visited[neighbor]:
                if self.dfs(neighbor, visited, path_visited, adj):
                    return True
            # 2. If neighbor is visited and on path, cycle if found
            elif path_visited[neighbor]:
                return True
            # 3. If neighbor is visited and not on path, continue to the next neighbor
            # So do nothing in this case
        
        path_visited[node] = False
                
        return False
```

##### Kahn's Algorithm

- 两种拓扑排序中的一种

```python
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
        cnt = 0
        while dq:
            node = dq.popleft()
            cnt += 1
            for neighbor in adj[node]:
                # 此处不用担心 in_degree[neighbor] 是 0
                # 因为 in_degree 是 0 的节点已经全部在队列中
                in_degree[neighbor] -= 1
                if in_degree[neighbor] == 0:
                    dq.append(neighbor)
                    
        return cnt != V
```

