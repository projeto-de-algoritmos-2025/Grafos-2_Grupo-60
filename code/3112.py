from math import inf
from heapq import heappush, heappop

class Solution:
    def minimumTime(self, n: int, edges: list, disappear: list) -> list:
        graph = [[] for _ in range(n)]
        for u, v, w in edges: 
            graph[u].append((v, w))
            graph[v].append((u, w))

        ans = [inf] * n
        ans[0] = 0
        pq = [(0, 0)] 

        while pq:
            x, u = heappop(pq)
            if x != ans[u]:  
                continue
            if x >= disappear[u]:
                continue
            for v, w in graph[u]:
                new_time = x + w
                if new_time < disappear[v] and new_time < ans[v]:
                    ans[v] = new_time
                    heappush(pq, (new_time, v))

        return [x if x < inf else -1 for x in ans]