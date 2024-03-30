class Solution:
    def largestLocal(self, grid: List[List[int]]) -> List[List[int]]:
        i,j = 0,0
        n = len(grid) - 2
        result = []
        for i in range(n):
            row = []
            for j in range(n):
                subGrid = [
                    grid[i][j:j+3],
                    grid[i+1][j:j+3],
                    grid[i+2][j:j+3],
                ]
                row.append(self.largest3x3Grid(subGrid))
            result.append(row) 
        return result
    
    def largest3x3Grid(self, grid: List[List[int]]) -> int:
        maxLi = 0
        for li in grid:
            maxLi = max(maxLi, max(li))

        return maxLi
