/*
Link to the question - https://practice.geeksforgeeks.org/problems/coin-change2448/1#
*/

class Solution
{
  public:
    long long int count( int S[], int m, int n )
    {
       
        //code here.
        long long int dp[n + 1] = { };
        dp[0] = 1;
        
        for(int i = 0; i < m; i++) {
            for(int j = 1; j < n + 1; j++) {
                if(S[i] <= j)
                    dp[j] += dp[j - S[i]];
            }
        }
        
        return dp[n];
    }
};
