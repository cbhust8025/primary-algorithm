class Solution(object):
    def convert(self, s, numRows):
        '''
        :type s: str
        :type numRows: int
        :rtype: str
        '''
        if (numRows == 1 or numRows == 0):
            return s
        if (len(s) == 0):
            return s
        list_s = list(s)
        res = ['$' for k in list_s]
        length = len(res)
        interval = 2 * numRows - 2
        i = 0
        for j in range(0, length, interval):
            res[i] = list_s[j]
            i += 1
        for k in range(1, numRows - 1):
            inter = 2 * k
            j = k
            while(j<length):
                res[i] = list_s[j]
                i += 1
                inter = interval - inter
                j += inter
        for j in range(numRows - 1, length, interval):
            res[i] = list_s[j]
            i += 1
        return ''.join(res)

    def show_martix(self, martix):
        for i in martix:
            for j in i:
                print j,' ',
            print '\n'

so = Solution()
print so.convert("aasdasdsadasdasdf",5)
