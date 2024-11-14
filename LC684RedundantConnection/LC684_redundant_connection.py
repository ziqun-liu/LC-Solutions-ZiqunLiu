import collections
from typing import List

class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        seen = set()
        adjacency_lists = collections.defaultdict(list)
        last_redundant_edge = []

        def dfs(graph, node, target):
            if node not in seen:
                seen.add(node)
                if node == target: return True
                for neighbor in graph[node]:
                    if dfs(graph, neighbor, target): return True
            return False

        for edge in edges:
            seen.clear()
            if edge[0] in adjacency_lists and edge[1] in adjacency_lists and dfs(adjacency_lists, edge[0], edge[1]):
                last_redundant_edge = edge
            adjacency_lists[edge[0]].append(edge[1])
            adjacency_lists[edge[1]].append(edge[0])
        return last_redundant_edge
