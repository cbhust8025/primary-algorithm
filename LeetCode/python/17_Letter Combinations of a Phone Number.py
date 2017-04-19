class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        dict = {
            1: ['*'],
            2: ['a', 'b', 'c'],
            3: ['d', 'e', 'f'],
            4: ['g', 'h', 'i'],
            5: ['j', 'k', 'l'],
            6: ['m', 'n', 'o'],
            7: ['p', 'q', 'r', 's'],
            8: ['t', 'u', 'v'],
            9: ['w', 'x', 'y', 'z'],
            0: [' ']
        }
        res = []
        ld = list(digits)
        for k in ld:
            res = self.addstring(int(k), dict, res)
        return res

    def addstring(self, N, dict, str):
        if(len(str) == 0):
            return dict[N]
        res = []
        for temp in str:
            for m in dict[N]:
                res.append(temp+m)
        return res

s = Solution()
print s.letterCombinations('123')