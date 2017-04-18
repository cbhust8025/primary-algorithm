class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        dist = {
            '(':')',
            '{':'}',
            '[':']'
        }
        ls = list(s)
        stackchar = []
        for tem in ls:
            if(tem == '(' or tem == '[' or tem == '{'):
                stackchar.append(tem)
            elif(stackchar!=[] and tem == dist[stackchar[-1]]):
                stackchar.pop(-1)
            else:
                return False
        if(stackchar!=[]):
            return False
        else:
            return True

s = Solution()
print s.isValid('(}[])')