# ====================== DFS ====================== 
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
