class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if(len(nums) <= 2):
            return []
        res = []
        now = 0
        length = len(nums)
        nums.sort()
        #print nums
        while(now<length-2):
            if(now >= 1):
                while(nums[now] == nums[now -1] and now <length -2):
                    now += 1
            start = now + 1
            stop = -1
            while(start -stop < length):
                if(nums[now] + nums[start]+ nums[stop] == 0):
                    res.append([nums[now], nums[start], nums[stop]])
                    while ( start -stop < length and nums[start] == nums[start +1]):
                        start+=1
                    while ( start - stop < length and nums[stop] == nums[stop -1]):
                        stop -=1
                    start += 1
                    stop -= 1
                elif(nums[now] + nums[start]+ nums[stop] < 0):
                    start += 1
                elif(nums[now] + nums[start]+ nums[stop] > 0):
                    stop -= 1
            now += 1
        return res

s = Solution()
print s.threeSum([0,0,0])