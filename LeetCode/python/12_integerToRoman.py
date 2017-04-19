class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        res = ''
        key = ['M','D','C','L','X','V','I']
        intkey = [1000,500,100,50,10,5,1]
        i = 0
        while(i<7):
            N = num/intkey[i]
            if(N<4):
                if(i<6 and num/intkey[i+1] == 9):
                    #9 and 4 is important
                    res+=key[i+1]+key[i-1]
                    num -= intkey[i+1]*4
                else:
                    for k in range(N):
                        res+=key[i]
            elif(N == 4):
                # no more than 3 times one roman number
                res += key[i]+key[i-1]
            num = num % intkey[i]
            i+=1

        return res

s = Solution()
print s.intToRoman(19)