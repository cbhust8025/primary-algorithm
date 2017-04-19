class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        '?' Matches any single character.
        '*' Matches any sequence of characters (including the empty sequence).
        The matching should cover the entire input string (not partial).
        The function prototype should be:
        bool isMatch(const char *s, const char *p)
        """
        lens = len(s)
        lenp = len(p)
        res = [False for i in range(lens+1)]
        res[0] = True
        for i in range(lenp):
            #print res,'1'
            if(p[i] == '*'):
                num = 0
                while(num <= lens and not res[num]):
                    num += 1
                #print num
                for k in range(num,lens+1):
                    res[k] = True
                #print res
            else:
                for j in range(lens):
                    res[-1-j] = res[-2-j] and (p[i] == '?' or p[i] == s[-1-j])
            res[0] = res[0] and (p[i] == '*')
            #print res
        return res[-1]

s = Solution()
print s.isMatch("ho",
"**ho")