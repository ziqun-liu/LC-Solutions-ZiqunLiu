#### Why topological sort?

- Traverse sequentially - nodes that are reachable first get visited first
- Hence minimizes the number of steps: O(V + E) - V is stack, E is all neighbors
- TC O(V+E + V+E) - V+E dfs, V visited each node noce, E all neighbors
- SC O(V + E) + O(V) + O(V) + O(V) + O(V) = O(V + E) - adj V+E, stk V, visited V, distance V, dfs call stack V 

```python
from typing import List


class Solution:

    def shortestPath(self, V: int, E: int,
                     edges: List[List[int]]) -> List[int]:
        
        adj = [[] for _ in range(V)]
        for u, v, dist in edges:
            adj[u].append((v, dist))
            
        # Topological sort to fill stack
        stk = []
        visited = [False for _ in range(V)]
        for i in range(V):
            if not visited[i]:
                self.dfs(i, visited, adj, stk)

        # Calculate distances
        distance = [float("inf") for _ in range(V)]
        #============ important ================
        # Problem description will ask 
        # which vertex should be the starting point for shortest path
        
        # Here assume the starting point is the top of the stack,
        # which is one of the nodes whose in-degree is 0
        distance[stk[-1]] = 0

        while stk:
            node = stk.pop()
            if distance[node] != float("inf"):
                for neighbor, dist in adj[node]:
                    distance[neighbor] = min(distance[neighbor], distance[node] + dist)
                    
        for i in range(V):
            if distance[i] == float("inf"):
                distance[i] = -1

        return distance

    def dfs(self, node, visited, adj, stk):
        visited[node] = True
        
        for neighbor, _ in adj[node]:
            if not visited[neighbor]:
                self.dfs(neighbor, visited, adj, stk)

        stk.append(node)

```

```python
adj = [
    [(1, 2)],
    [(3, 1)],
    [(3, 3)],
    [],
    [(0, 3), (2, 1)],
    [(4, 1)],
    [(4, 2), (5, 3)]
]

stk = [3, 1, 0, 2, 4, 5, 6]
```

