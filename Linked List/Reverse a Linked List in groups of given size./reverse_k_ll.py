"""
Link to the question - https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1#
Approach - Recursive.
Time and space complexity - O(n), O(n/k) [Recusrion stack only, program space - O(1)]
"""

class Node:
    def __init__(self, data):
		self.data = data
		self.next = None

class Solution:
    def reverse(self,head, k):
        # Code here
        if head is None or head.next is None:
            return head
        if k == 1:
            return head
            
        var = k
        temp, tracker, prev = head, head, None
        
        while var > 0 and head is not None:
            head = head.next
            tracker.next = prev
            prev = tracker
            tracker = head
            var -= 1
            
        temp.next = self.reverse(head, k)
        return prev
