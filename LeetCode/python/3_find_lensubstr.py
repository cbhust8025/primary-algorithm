class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if(len(s) == 0):
            return 0
        list_s = list(s)
        a = [1 for k in list_s]
        max = 1
        sub_str = [list_s[0]]
        flag = 0
        temp = -1
        for i,k in enumerate(list_s):
            if(i == 0):
                continue
            for j, m in enumerate(sub_str):
                if (k == m):
                    flag = 1
                    temp = j
            if(flag == 0):
                sub_str.append(k)
                a[i] = len(sub_str)
                if (a[i] > max):
                    max = a[i]
            else:
                sub_str = sub_str[temp+1:]
                sub_str.append(k)
                temp = -1
                flag = 0
                a[i] = len(sub_str)
                if (a[i] > max):
                    max = a[i]
        return max

so = Solution()
print so.lengthOfLongestSubstring('abscacasa')