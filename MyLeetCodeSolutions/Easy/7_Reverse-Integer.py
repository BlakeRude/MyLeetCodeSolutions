class Solution:
    def reverse(self, x: int) -> int:
        flag = False
        if(x < 0): # if negative
            flag = True
            x *= -1
        x = list(map(int, str(x)))
        print(x)
        x = x[::-1]
        x2 = [str(integer) for integer in x]
        x = int("".join(x2))
        if(x > 2147483647):
            return 0
        elif(flag):
            return x * -1
        else:
            return x