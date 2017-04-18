class Solution(object):
    def find_kth(self, num, k):
        #find kth small number
        if(len(num)<k):
            return 'k is too big!'
        small = []
        big = []
        pivot = num.pop()
        for t in num:
            if(t<= pivot):
                small.append(t)
            else:
                big.append(t)
        if(len(small)>k-1):
            return self.find_kth(small,k)
        elif(len(small) == k-1):
            return pivot
        else:
            return self.find_kth(big,k-1-len(small))

    def find_kth_2(self, num1, num2, k):
        #find kth small number between num1+num2
        if(len(num1) > len(num2)):
            return self.find_kth_2(num2, num1, k)
        if(len(num1) == 0):
            return num2[k-1]
        if(k == 1):
            return min(num1[0],num2[0])
        pa = min(k/2, len(num1))
        pb = k - pa
        if(num1[pa- 1] < num2[pb-1]):
            return self.find_kth_2(num1[pa:],num2,pb)
        elif(num1[pa - 1]> num2[pa-1]):
            return self.find_kth_2(num1, num2[pb:], pa)
        else:
            return num1[pa-1]

    def findMedianSortedArrays(self, nums1, nums2):
        '''
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        '''
        total = len(nums1)+len(nums2)
        if(total%2==1):
            return self.find_kth_2(nums1,nums2,total/2 +1)
        else:
            return (self.find_kth_2(nums1,nums2,total/2 +1 )+ self.find_kth_2(nums1,nums2,total/2))/2.0
so = Solution()
print so.findMedianSortedArrays([1,3],[2])
print so.find_kth([3,5,1,2,7,6,29,10],8)