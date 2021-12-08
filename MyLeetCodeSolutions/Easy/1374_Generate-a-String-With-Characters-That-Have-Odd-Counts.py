class Solution:
    def generateTheString(self, n: int) -> str:
        result = ""
        if (n%2) == 1:    #if odd
            for m in range(0,n):
                result = result+'a'
        else:               #if even
            for m in range(0,n-1):
                result = result + 'a'
            result = result + 'b'
        return result