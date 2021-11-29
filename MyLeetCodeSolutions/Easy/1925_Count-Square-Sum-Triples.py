class Solution:
    def countTriples(self, n: int) -> int:
        countTriples = 0
        if n == 1:
            return countTriples # 0
        for x in range(1,n):
            for y in range(1,n):
                z = x*x + y*y
                z = sqrt(z)
                if z.is_integer() and z <= n:
                    countTriples+=1
        return countTriples