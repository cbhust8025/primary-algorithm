class Solution(object):
    def reverse(self, x):
        '''
        :type x: int
        :rtype: int
        '''
        res = []
        if(x>0):
            res.append('+')
            res.append(list(str(x)))
        else:
            list_x = list(str(x))
            res.append(list_x[0])
            res.append(list_x[1:])
        res[1].reverse()
        result = int(res[0]+''.join(res[1]))
        if(result<=2147483647 and result>= -2147483648):
            return result
        else:
            return 0
so = Solution()
print so.reverse(1534236469)