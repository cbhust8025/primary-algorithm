class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        i = 0
        j = -1
        length = len(height)-1
        temp = length
        maxC = length * min(height[i],height[j])
        while(i-j<=temp):
            if(height[i]<=height[j]):
                maxC = max(length*height[i], maxC)
                i+=1
            else:
                maxC = max(length*height[j], maxC)
                j-=1
            length -= 1
        return maxC

s = Solution()
print s.maxArea([2,3,4,5,18,17,6])