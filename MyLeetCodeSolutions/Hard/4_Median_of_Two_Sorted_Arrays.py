class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums = nums1 + nums2
        nums = sorted(nums)
        l = len(nums)
        if((l % 2) == 1): #if one median 
            return float(nums[(l)//2])
        else: #if two medians to divide
            print((l)//2)
            return float( ( (nums[(l)//2]) + (nums[((l)//2)-1]) ) / 2)