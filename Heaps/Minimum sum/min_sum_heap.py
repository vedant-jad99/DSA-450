"""
Link to the question - https://practice.geeksforgeeks.org/problems/minimum-sum4058/1
Appraoch 1 (Correct): This problem can also be solved as follows - sort them, and for every alternate even and od positions, create the numbers and add them.
Approach 2 (Correct): Form a heap, for every alternate pop operation create a number and add them.
"""

import heapq

class Solution:
    def solve(self, arr, n):
        # code here
        
        """
        arr.sort()
        n1, n2 = 0, 0
        for i in range(0, n, 2):
            n1 = n1 * 10 + arr[i]
            if i + 1 < n:
                n2 = n2 * 10 + arr[i + 1]
        return str(n1 + n2)
        """
        
        n1, n2 = 0, 0
        heapq.heapify(arr)
        for i in range(n):
            if i%2:
                n1 = n1 * 10 + heapq.heappop(arr)
                continue
            n2 = n2 * 10 + heapq.heappop(arr)
            
        return str(n1 + n2)
        
