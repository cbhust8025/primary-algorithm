class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        #print s,':',p
        lens = len(s)
        lenp = len(p)
        res = [[False for i in range(lens+1)] for i in range(lenp+1)]
        res[0][0] = True
        #print res
        for i in range(lenp):
            if(p[i] == '*'):
                #print "^",i
                if(i == 0):
                    continue
                if(i > 0 and res[i-1][0]):
                    #print 2,res[i][j]
                    res[i+1][0] = True
                if(p[i-1] == '.'):
                    num = 0
                    while(num<lens and i>0 and not res[i][num+1] and not res[i-1][num+1]):
                        num+=1
                    #print num,
                    for k in range(num,lens):
                        #print 3,i,j
                        res[i+1][k+1] = True
                    #print res
                else:
                    #print 1
                    for k in range(lens):
                        if(res[i][k+1] or (i>0 and res[i-1][k+1]) or (k>0 and i>0 and s[k]==s[k-1] and p[i-1]==s[k-1] and res[i+1][k])):
                            #print 4,res[i-1][k+1],res[i][k+1],res[i+1][k]
                            res[i+1][k+1] = True
            else:
                for j in range(lens):
                    if(s[j] == p[i] or p[i]=='.'):
                        #print 5,res[i][j],
                        res[i+1][j+1] = res[i][j]
                        #print res[i+1][j+1]
        #print res
        return res[-1][-1]

a = [1,2,3]
s = Solution()
print s.isMatch("aaaca",".*")