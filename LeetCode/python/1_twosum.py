class Solution(object):
    def twoSum(self, nums, target):
        '''
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        '''
        temp = [target-x for x in nums]
        res = []
        abs = []
        for i,x in enumerate(nums):
            if(x in temp):
                if(x == target/2):
                    abs.append(i)
                else:
                    res.append(i)
        if(len(res)== 0):
            return abs
        return res
so = Solution()
print so.twoSum([1,9,4,4,56,90,3,6],8)