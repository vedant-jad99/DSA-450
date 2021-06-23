/*
Link to the question - https://practice.geeksforgeeks.org/problems/ncr1019/1#
Approach 1 -
    Dynamic Programming and modular arithmatic: Making use of the recurse relation - nCr = (n- 1)Cr + (n - 1)C(r - 1). Efficient but uses more space.
    Time and Space complexity - O(n*r)
    
Approach 2 -
    Dynamic Programming and modular arithmatic: Here we observe a unique property of binomial coefficients. For a given n, nCr will form numbers of Pascal traingle(1 <= r <= n).
    n = 0 ==>     1
    n = 1 ==>    1 1
    n = 2 ==>   1 2 1
    n = 3 ==> 1 4 6 4 1
    and so on...
    Here we calculate the nth row of Pascal's triangle.
    Time and space complexity - O(n*r), O(r)
*/

class Solution{
    int modulo = 1000000007;
    public:
        //Approach 1:
        
        // int nCr(int n, int r){
        //     // code here
        //     if(r > n)
        //         return 0;
        //     if(r == n)
        //         return 1;
        //    
        //     int cache[r + 1][n + 1];
        //     for(int i = 0; i < n + 1; i++) {
        //         cache[0][i] = 0;
        //         if(i == 0)
        //             continue;
        //         cache[1][i] = i;
        //         if(i < r + 1)
        //             cache[i][0] = 0;
        //     }
        //
        //     for(int i = 2; i < r + 1; i++)
        //         for(int j = 1; j < n + 1; j++)
        //             if(i > j)
        //                 cache[i][j] = 0;
        //             else
        //                 cache[i][j] = (cache[i - 1][j - 1] + cache[i][j - 1])%modulo;


        //     return cache[r][n];
        // }
    
        //Approach 2
    
    
        int nCr(int n, int r) {
            int C[r + 1];
            for(int i = 1; i < r + 1; i++)
                C[i] = 0;

            C[0] = 1;
            for(int i = 1; i <= n; i++)
                for(int j = min(r, i); j > 0; j--)
                    C[j] = (C[j] + C[j - 1])%modulo;

            return C[r];
        }
};
