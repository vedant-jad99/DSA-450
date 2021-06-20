"""
Link to the question - https://leetcode.com/problems/next-permutation/
"""

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        i = n - 1
        while i > 0:
            if nums[i] > nums[i - 1]:
                j = n - 1
                while j >= i:
                    if nums[j] > nums[i - 1]:
                        nums[j], nums[i - 1] = nums[i - 1], nums[j]
                        break
                    j -= 1
                break
            i -= 1
        
        limit = (n - i)//2
        count = 0
        while count < limit:
            nums[i + count], nums[n - count - 1] = nums[n - count - 1], nums[i + count]
            count += 1
