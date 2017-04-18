class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if (len(nums) <= 2):
            return []
        res = []
        now = 0
        length = len(nums)
        nums.sort()
        mindistance = target - (nums[0]+ nums[1] + nums[2])
        # print nums
        while (now < length - 2):
            if (now >= 1):
                while (nums[now] == nums[now - 1] and now < length - 2):
                    now += 1
            start = now + 1
            stop = -1
            while (start - stop < length):
                #print start,stop,mindistance
                distance = target - (nums[now] + nums[start] + nums[stop])
                #print distance,mindistance
                if(distance == 0):
                    return target
                if(distance < 0):
                    while (start - stop < length and nums[stop] == nums[start - 1]):
                        stop -= 1
                    stop -= 1
                if(distance > 0):
                    while (start - stop < length and nums[start] == nums[start + 1]):
                        start += 1
                    start += 1
                if(abs(distance) < abs(mindistance)):
                    mindistance = distance
            now += 1
        return target - mindistance

s = Solution()
print s.threeSumClosest([0,1,2,-3],1)