### Dijkstra

`https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1`

You are given a weighted undirected graph having **n** vertices numbered from **1 to n** and **m** edges along with their weights. Find the **shortest** **weight** **path** between the vertex 1 and the vertex **n**, if there exists a path, and return a list of integers whose first element is the **weight** of the path, and the rest consist of the nodes on that path. If no path exists, then return a list containing a single element **-1**.

The input list of edges is as follows - **{a, b, w}**, denoting there is an edge between **a** and **b**, and **w** is the weight of that edge.

```python
import heapq


from typing import List
class Solution:
    def shortestPath(self,n:int, m:int, edges:List[List[int]] )->List[int]:
        adj = [[] for _ in range(n + 1)]
        distance = [float('inf') for _ in range(n + 1)]
        distance[1] = 0
        
        for a, b, w in edges:
            adj[a].append((w, b))
            adj[b].append((w, a))
    
        heap = [(0, 1)]
        parents = [-1 for _ in range(n + 1)]
        while heap:
            dist, node = heapq.heappop(heap)
            for w, neighbor in adj[node]:
                if dist + w < distance[neighbor]:
                    distance[neighbor] = dist + w
                    parents[neighbor] = node
                    heapq.heappush(heap, (dist + w, neighbor))

        if distance[n] == float("inf"):
            return [-1]

        res = []
        curr = n
        while curr != -1:
            res.append(curr)
            curr = parents[curr]
        res.reverse()

        return [distance[n]] + res
```

因为需要返回整个路径，所以需要维护一个父节点数组。

如果只需要返回最短路径：

```python
import heapq
from typing import List

class Solution:
    def shortestPath(self, n: int, m: int, edges: List[List[int]]) -> int:
        # 构建邻接表
        adj = [[] for _ in range(n + 1)]
        for a, b, w in edges:
            adj[a].append((w, b))
            adj[b].append((w, a))
        
        # Dijkstra算法
        distance = [float('inf')] * (n + 1)
        distance[1] = 0
        heap = [(0, 1)]
        
        while heap:
            dist, node = heapq.heappop(heap)
            
            if dist > distance[node]:
                continue
                
            for w, neighbor in adj[node]:
                if dist + w < distance[neighbor]:
                    distance[neighbor] = dist + w
                    heapq.heappush(heap, (dist + w, neighbor))
        
        return distance[n] if distance[n] != float('inf') else -1
```

