#coding=utf-8
#题目要求：Determine whether an integer is a palindrome. Do this without extra space.
#判断是否一个整数为回文整数，类似41314这样就属于回文整数
#须注意0=<x<10的一位数均为回文整数，大于10的整数需要进行剥离两边数字一一比对。
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        # 须注意0=<x<10的一位数均为回文整数
        if(x< 0):
            return False
        if(x<10):
            return True
        #计算此整数的总位数
        t = x
        b = 0
        while(t/10!=0):
            b+=1
            t/=10
        left = 10**b
        right = 1
        while(left>=right):
            if(x/left%10 != x/right%10):
                return False
            left/=10
            right*=10
        return True

a = Solution()
print a.isPalindrome(3443)
