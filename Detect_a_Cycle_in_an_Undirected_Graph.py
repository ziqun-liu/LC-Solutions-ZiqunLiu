from collections import deque


# ================== Detect a Cycle in an Undirected Graph using DFS ==================
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


# ================== Detect a Cycle in an Undirected Graph using BFS ==================
class Solution:
    def isCycle(self, V, edges):
    """
        TC O(V + 2E + V) = O(V + E) - V is number of nodes, 2E is number of neighbors, V is number of components
        SC O(V + V + V + 2E) - V is deque, V is visited, V + 2E is adjacency list (not accounted for if given)
    """
        adj_list = [[] for _ in range(V)]
        
        for u, v in edges:
            adj_list[u].append(v)
            adj_list[v].append(u)
            
        visited = [False] * V
        
        for i in range(V):
            if not visited[i]:
                if self.detect(i, adj_list, visited):
                    return True
                    
        return False
            
        
    def detect(self, node, adj_list, visited):
        visited[node] = True
        dq = deque([(node, -1)])
        
        while dq:
            node, parent = dq.popleft()
            for neighbor in adj_list[node]:
                if not visited[neighbor]:
                    visited[neighbor] = True
                    dq.append((neighbor, node))
                elif neighbor != parent:
                    return True
                
        return False
        
