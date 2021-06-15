/*
Link to the question - https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1#

Approach 1 - Merge two arrays, sort and return uniques count. Time complexity - O((n + m)*log(n + m))

Approach 2 - Using hashset to store unique values in both arrays
*/

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        
        /*Approach 1
        int union_arr[n + m];
        for(int i = 0; i < n + m; i++) {
            if(i < n)
                union_arr[i] = a[i];
            else 
                union_arr[i] = b[i - n];
        } 
        sort(union_arr, union_arr + m + n);
        
        int counter = 1;
        for(int i = 1; i < n + m; i++)
            if(union_arr[i] != union_arr[i - 1])
                counter++;
        return counter;
        */
        
        //Approach 2
        unordered_set<int> s;
        for(int i = 0; i < m + n; i++) {
            if(i < n)
                s.insert(a[i]);
            else
                s.insert(b[i - n]);
        }
        
        return s.size();
    }
};
