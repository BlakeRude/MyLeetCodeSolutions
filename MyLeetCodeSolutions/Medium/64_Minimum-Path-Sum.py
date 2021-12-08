class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        # Initialize with 0s
        columns = len(grid)
        rows = len(grid[0])
        scoregrid = [ [0]*rows for i in range(columns) ]
        # Iterate 2d array, creating score for taking certain pathways, final item will contain best score
        for i in range(columns):
            for j in range(rows):
                if i == 0 and j != 0:
                    scoregrid[i][j] = grid[i][j] + scoregrid[i][j-1]
                elif i != 0 and j == 0:
                    scoregrid[i][j] = grid[i][j] + scoregrid[i-1][j]
                elif i == 0 and j == 0:
                    scoregrid[i][j] = grid[i][j]
                else:
                    scoregrid[i][j] = grid[i][j] + min(scoregrid[i-1][j],scoregrid[i][j-1])
        return scoregrid[columns-1][rows-1]