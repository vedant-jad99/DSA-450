"""
Link to question - https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1#
Approach 1 (Wrong answer): Traverse the entire tree and check if max-heap property is satisfied. If no, then return false.
                            This approach is wrong, as the most basic property of heap is, it is a "complete binary tree", and this must also be checked.
                            
Approach 2: Get the total count of nodes. Check if the tree is complete binary tree or not. If it is, check if heap property satisfied or not.
Time and space complexity - O(n), O(h) [ Recursion stack ]
"""

class Node:
    def __init__(self,val):
        self.data = val
        self.left = None
        self.right = None

class Solution:
    #Your Function Should return True/False
    def isHeap(self, root):
        #Code Here
        def maxHeap(root):
            if root is None:
                return True
            if root.left is None and root.right is None:
                return True
            
            if root.left is not None:
                if root.data < root.left.data:
                    return False
            
            if root.right is not None:
                if root.data < root.right.data:
                    return False
            
            return maxHeap(root.left) and maxHeap(root.right)
        
        if self.check_complete_bt(root, 0, self.count_nodes(root)):
            return maxHeap(root)
        return False
        
    def check_complete_bt(self, root, index, count):
        if root is None:
            return True
        if index >= count:
            return False
            
        return self.check_complete_bt(root.left, 2*index + 1, count) and self.check_complete_bt(root.right, 2*index + 2, count)
        
                
    def count_nodes(self, root):
        if root is None:
            return 0
        
        return self.count_nodes(root.left) + 1 + self.count_nodes(root.right)
