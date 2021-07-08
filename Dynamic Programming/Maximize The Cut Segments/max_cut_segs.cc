/*
Link to the question - https://practice.geeksforgeeks.org/problems/cutted-segments1642/1
Approach 1 - Recursion. 
Approach 2 - DP
*/

class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        
    //     Approach 1
    //     int ans = maximizeUtil(n, x, y, z);
    //     return max(ans, 0);
    // }
    // int maximizeUtil(int n, int x, int y, int z) {
    //     if(n == 0)
    //         return 0;
    //     if(n < 0)
    //         return -1;
            
    //     int n_x, n_y, n_z;
    //     n_x = maximizeUtil(n - x, x, y, z);
    //     n_y = maximizeUtil(n - y, x, y, z);
    //     n_z = maximizeUtil(n - z, x, y, z);
        
    //     int maximum = max(n_x, max(n_y, n_z));
    //     if(maximum < 0)
    //         return -1;
    //     return maximum + 1;
    
        
    //  Appraoch 2    
        int a[n + 1], x_, y_, z_;
        a[0] = 0;
        for(int i = 1; i < n + 1; i++) {
            x_ = y_ = z_ = -1;
            if(i >= x) 
                if(a[i - x] >= 0)
                    x_ = a[i - x];
            
            if(i >= y) 
                if(a[i - y] >= 0)
                    y_ = a[i - y];
            
            if(i >= z) 
                if(a[i - z] >= 0)
                    z_ = a[i - z];
            
            
            if(x_ < 0 && y_ < 0 && z_ < 0) 
                a[i] = -1;
            else
                a[i] = max(max(x_, y_), z_) + 1;
        }
    
        return max(0, a[n]);
    }
};
