"""
Link of the question - https://practice.geeksforgeeks.org/problems/find-the-median0527/1
"""

class Solution:
	def find_median(self, v):
        n = len(v)
        v.sort()
        if n%2 == 1:
            return v[n//2]
        return (v[n//2 - 1] + v[n//2])//2
