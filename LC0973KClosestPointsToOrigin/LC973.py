from typing import List
import heapq


class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        heap = []
        
        for x, y in points:
            dist = x ** 2 + y ** 2
            heapq.heappush(heap, [-dist, x, y])
            if len(heap) > k:
                heapq.heappop(heap)

        res = []
        while len(heap):
            res.append([heap[0][1], heap[0][2]])
            heapq.heappop(heap)

        return res