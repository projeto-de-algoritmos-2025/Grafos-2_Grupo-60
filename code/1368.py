import heapq
from typing import List

class Solution:
    def minCost(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0]) 
        dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)] # direita, esquerda, baixo e cima.
        
        pq = [(0, 0)]  
        dist = [float('inf')] * (m * n)
        dist[0] = 0

        while pq:
            cost, cell = heapq.heappop(pq)
            if cell == m * n - 1: 
                return cost

            if cost > dist[cell]:
                continue 

            row, col = divmod(cell, n)
            for d, (dx, dy) in enumerate(dirs, start=1):
                nx, ny = row + dx, col + dy
                if 0 <= nx < m and 0 <= ny < n:
                    next_cell = nx * n + ny
                    new_cost = cost + (grid[row][col] != d)
                    if new_cost < dist[next_cell]:
                        dist[next_cell] = new_cost
                        heapq.heappush(pq, (new_cost, next_cell))

        return -1 
