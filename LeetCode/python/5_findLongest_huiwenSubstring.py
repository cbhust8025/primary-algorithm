class Solution(object):
    def longestPalindrome(self, s):
        '''
        :type s: str
        :rtype: str
        '''
        #print s
        list_s = list(s)
        str = '$#'
        for k in list_s:
            str += k
            str += '#'
        str += '*'
        #print str
        list_str = list(str)
        P = [1 for x in list_str]
        #print P
        mx = 0
        id = 0
        for i in range(1,len(list_str)-1):
            if(mx > i):
                P[i] = min(mx-i, P[2*id-i])
            while(list_str[i+P[i]] ==list_str[i-P[i]]):
                P[i] += 1
            if(i+P[i]>mx):
                mx = i+P[i]
                id = i
            #print P
            #print id,mx
        max = 0
        for j in range(len(list_str)):
            if(P[j]>max):
                max = P[j]
                id = j
        result = ''.join(list_str[id-max+1:id+max])
        res = [i for i in list(result) if i != '#']
        return ''.join(res)

so  = Solution()
print so.longestPalindrome('btb')
