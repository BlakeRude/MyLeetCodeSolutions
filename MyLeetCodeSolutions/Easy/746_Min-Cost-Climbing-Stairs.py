class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        top = len(cost)
        f = []
        f.append(cost[0])
        f.append(cost[1])
        #Iterate through remaining
        for i in range(2, top):
            print(i)
            f.append(cost[i] + min(f[i-1],f[i-2]))
        return min(f[top-1],f[top-2])