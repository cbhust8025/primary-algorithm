class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        dict = {
            'M': 1000,
            'D': 500,
            'C': 100,
            'L': 50,
            'X': 10,
            'V': 5,
            'I': 1,
        }
        sL = list(s)
        sL.reverse()
        res = 0
        N = 1
        for sss in sL:
            M = dict[sss]
            if(M==N):
                res+=M
            elif(M>N):
                res+=M
                N = M
            elif(M<N):
                res-=M
        return res

s = Solution()
print s.romanToInt('MV')