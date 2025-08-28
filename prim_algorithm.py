import heapq
from typing import List


class Solution:
    def prim(self, V: int, edges: List[List[int]]) -> (int, List[tuple]):
        """
        [
            [0, 1, 2],
            [0, 2, 1],
            [1, 2, 1],
            [2, 3, 2],
            [2, 4, 2],
            [3, 4, 1]
        ]
        """
        # TC O(E * logE)
        # SC O(V + E)
        visited = [False] * V  # SC V
        visited[0] = True
        mst = []
        res = 0

        adj = [[] for _ in range(V)]
        for u, v, w in edges:  # TC V, SC V + 2E
            adj[u].append((v, w))
            adj[v].append((u, w))

        heap = []  # (wt, node, parent) SC E
        for neighbor, weight in adj[0]:
            heapq.heappush(heap, (weight, neighbor, 0))

        while heap:  # TC E
            wt, node, parent = heapq.heappop(heap)  # TC E

            if visited[node]:
                continue
            visited[node] = True

            mst.append((parent, node))
            res += wt

            for neighbor, dist in adj[node]:  # TC E*logE - all edges E, heappush logE
                if not visited[neighbor]:
                    heapq.heappush(heap, (dist, neighbor, node))

        return res, mst


def main():
    edges = [[0,1,2], [0,2,1], [1,2,1], [2,3,2], [2,4,2], [3,4,1]]
    sol = Solution()
    res, mst = sol.prim(5, edges)

    print(res)  # 5
    print(mst)  # [(0, 2), (2, 1), (2, 3), (3, 4)]


if __name__ == '__main__':
    main()