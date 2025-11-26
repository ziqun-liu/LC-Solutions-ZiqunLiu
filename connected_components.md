# Connected Components in Undirected Graphs

一般地，优先掌握**无向图**连通分量。前提：`adj_list` 已经包含所有 n 个节点作为键

### DFS

`cc` 是一个 数组。例如，`cc[4] = 2`代表节点四属于第2个连通分量

```python
# dfs 邻接表版本
def dfs(u, adj_list, visited, cc, cc_id):
    visited[u] = True
    cc[u] = cc_id

    for v in adj_list[u]:
        if not visited[v]:
            dfs(v, adj_list, visited, cc, cc_id)
# dfs 邻接矩阵版本
def dfs(u, adj_matrix, visited, cc, cc_id):
    visited[u] = True
    cc[u] = cc_id
    
    for v in range(len(adj_matrix[0])):  # 遍历所有可能的邻居
        if adj_matrix[u][v] == 1 and not visited[v]:  # 检查是否有边
            dfs(v, adj_matrix, visited, cc, cc_id)


# 主函数
def dfs_all(adj, n):
    visited = [False] * n
    cc = [-1] * n
    count = 0  # 连通分量从 0 开始编号

    for node in range(n):
        if not visited[node]:
            dfs(node, adj, visited, cc, count)
            count += 1
    
    return count, cc
```

### BFS 

```python
# bfs 邻接表版本
def bfs(start, adj_list, visited, cc, cc_id):
    queue = deque([start])
    visited[start] = True
    
    while queue:
        u = queue.popleft()
        cc[u] = cc_id
        
        for v in adj_list[u]:
            if not visited[v]:
                queue.append(v)
                visited[v] = True

# bfs 邻接矩阵版本
def bfs(start, adj_matrix, visited, cc, cc_id)       :
    queue = deque([start])
    visited[start] = True
    
    while queue:
        u = queue.popleft()
        cc[u] = cc_id
        
        for v in range(len(adj_matrix[0])):
            if adj_matrix[u][v] == 1 and not visited[v]:
                queue.append(v)
                visited[v] = True
                

# 主函数
def bfs_all(adj, n):
    visited = [False] * n
    cc = [-1] * n
    count = 0
    
    for node in range(n):
        if not visited[node]:
            bfs(node, adj, visited, cc, count)
            count += 1
            
	return count, cc
```



# Connected Components in Directed Graphs