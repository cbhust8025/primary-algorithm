class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        if(len(str) == 0):
            return 0
        str = str.strip(' ')
        print str
        if(len(str) == 1):
            if (str == '+' or str == '-'):
                return 0
        if(str[0] == '+' and str[1] == '-'):
            return 0
        elif(str[0] == '-' and str[1] == '+'):
            return 0
        else:
            if(str[0] == '+' or str[0] == '-'):
                temp = str[0]
                for i in range(1,len(str)):
                    if(str[i]<='9' and str[i] >= '0'):
                        temp+=str[i]
                    else:
                        try:
                            return self.max_min(int(temp))
                        except:
                            return 0
                try:
                    return self.max_min(int(temp))
                except:
                    return 0
            else:
                temp = ''
                for i in range(0, len(str)):
                    if (str[i] <= '9' and str[i] >= '0'):
                        temp += str[i]
                    else:
                        try:
                            return self.max_min(int(temp))
                        except:
                            return 0
                try:
                    return self.max_min(int(temp))
                except:
                    return 0

    def max_min(self, temp):
        if(temp > 2147483647):
            return 2147483647
        if(temp < -2147483648):
            return -2147483648
        return temp
so = Solution()
print so.myAtoi('   -321 ')
