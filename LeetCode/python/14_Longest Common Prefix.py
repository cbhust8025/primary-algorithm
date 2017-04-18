class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if(len(strs)== 0):
            return ''
        if(len(strs)== 1):
            return strs[0]
        Ls = []
        res = ''
        minL = len(strs[0])
        for tem in strs:
            if(minL > len(tem)):
                minL = len(tem)
            Ls.append(list(tem))
        i = 0
        while(i < minL):
            temp = Ls[0][i]
            for str in Ls:
                if(temp != str[i]):
                    return res
            res += temp
            i+=1
        return res