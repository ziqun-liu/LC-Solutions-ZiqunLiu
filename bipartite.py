from collections import deque

# ====================== BFS ======================
# TC O(V + V + 2E) = O(V + E) - outer loop V, BFS V + 2E
# SC O(V + V) = O(V) - color array V, deque V
class Solution:
	def is_bipartite(self, V: int, adj_list: list) -> bool:
		# 节点从 0 开始
		color = [-1 for _ in range(V)]

		for start in range(V):
			if color[start] == -1:
				color[start] = 0
				dq = deque([start])

				while dq:
					node = dq.popleft()
					for neighbor in adj_list[node]:
						if color[neighbor] == -1:
							color[neighbor] = 1 - color[node]
							dq.append(neighbor)
						elif color[neighbor] == color[node]:
							return False

		return True


class Solution:
    def is_bipartite(self, V: int, adj_list: list) -> bool:
        # 如果节点从1开始，我们需要V+1大小的数组来包含节点1到V
        color = [-1 for _ in range(V + 1)]
        
        # 检查从节点1到V的所有组件
        for start in range(1, V + 1):
            if color[start] == -1:  # 未访问的节点
                # 从这个组件开始BFS
                color[start] = 0
                dq = deque([start])
                
                while dq:
                    node = dq.popleft()
                    # adj_list[node-1]因为邻接表数组仍然是0索引的
                    for neighbor in adj_list[node - 1]:
                        if color[neighbor] == -1:
                            # 用相反的颜色着色
                            color[neighbor] = 1 - color[node]
                            dq.append(neighbor)
                        elif color[neighbor] == color[node]:
                            # 与当前节点相同颜色 - 不是二分图
                            return False
        
        return True


# ====================== DFS ======================
# TC O(V + E)
# SC O(V)

class Solution:
	def is_bipartite(self, V: int, adj_list: list) -> bool:
		color = [-1 for _ in range(V)]

		for start in range(V):
			if color[start] == -1:
				color[start] = 0
				if not self.dfs(start, adj_list, color):
					return False

		return True

	def dfs(self, start: int, adj_list: list, color: list):
		for neighbor in adj_list[start]:
			if color[neighbor] == -1:
				color[neighbor] = 1 - color[start]
				if not self.dfs(neighbor, adj_list, color):
					return False
			elif color[neighbor] == color[start]:
				return False

		return True
