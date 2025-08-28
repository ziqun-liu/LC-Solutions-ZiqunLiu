import heapq
from typing import List


class FloydWarshall:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        # Floyd Warshall needs a matrix
        matrix = [[float('inf')] * n for _ in range(n)]
        for from_, to_, weight_ in edges:
            matrix[from_][to_] = weight_
            matrix[to_][from_] = weight_

        # Every city has 0 distance to itself
        for i in range(n):
            matrix[i][i] = 0

        # Relax the distances
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    if matrix[i][k] == float('inf') or matrix[k][j] == float('inf'):
                        continue
                    matrix[i][j] = min(matrix[i][k] + matrix[k][j], matrix[i][j])

        smallest_cnt = n
        res = -1
        for i in range(n):  # Each row / each city
            cnt = 0
            for j in range(n):  # Each column / each adjacent city
                # Increment count in each row if the cell value is under threshold
                if matrix[i][j] <= distanceThreshold:
                    cnt += 1

            if cnt <= smallest_cnt:
                smallest_cnt = cnt  # Update the smallest qualified number
                res = i  # Update the city

        return res


class Dijkstra:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        # Adjacency list
        adj = [[] for _ in range(n)]  # SC O(V + E) = O(V + V^2) = O(V^2)
        for fro, to, wei in edges:
            adj[fro].append((to, wei))
            adj[to].append((fro, wei))

        smallest_cnt = n
        res = -1
        for i in range(n):  # Each city TC O(V)
            cnt = self.dijkstra(i, adj, distanceThreshold)
            if cnt <= smallest_cnt:
                smallest_cnt = cnt  # Update the smallest qualified number
                res = i  # Update the city

        return res

    def dijkstra(self, node, adj, distanceThreshold):
        # TC O(E * logV) = O(V^2 * logV)
        visited = set()  # Store nodes
        heap = [(0, node)]  # heap: [(weight, node)]

        while heap:
            dist, curr = heapq.heappop(heap)

            if curr in visited:
                continue
            visited.add(curr)

            for neighbor, weight in adj[curr]:
                # 这里没有 distance 数组，有的是整数 distanceThreshold
                if dist + weight <= distanceThreshold:
                    heapq.heappush(heap, (dist + weight, neighbor))

        return len(visited) - 1

