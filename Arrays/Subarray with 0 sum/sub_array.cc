/*
Link to the question - https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1#

Naive approach - 
Check for all the sub-arrays and check their sum. Time complexity - O(n^2)

The approach here is - 
We check the prefix sum for each element. Prefix sum is the sum of all elements before that index. We also keep track of the running sum.
If the running sum is zero, we return true. If the prefix sum is same for 2 different elements, it means that we have a sub-array whose sum is 0, as somwhere in between, all the 
elements have summed upto zero, thus giving the same sum. We can store the prefix sum in a hashmap, for constant time checking. The time complexity - O(n)
*/

class Solution{
    public:
    bool subArrayExists(int arr[], int n)
    {
        map<int, int> prefix_sum;
        int sum = 0;
        for(int i = 1; i < n + 1; i++) {
            sum += arr[i - 1];
            if(sum == 0)
                return true;
            if(prefix_sum.find(sum) != prefix_sum.end())
                return true;
            
            prefix_sum.insert({sum, i});
        }
        return false;
    }
};
