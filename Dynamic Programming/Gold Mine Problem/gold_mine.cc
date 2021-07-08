/*
Link to the question - https://practice.geeksforgeeks.org/problems/gold-mine-problem2608/1
*/

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        int cost[n][m] = { };
        int gold = 0;
        
        if(n == 1) {
            for(int i = 0; i < m; i++)
                gold += M[0][i];
            return gold;    
        }
        
        for(int j = m - 1; j >= 0; j--) {
            for(int i = 0; i < n; i++) {
                if(j == m - 1)
                    cost[i][j] = M[i][j];
                else {
                    if(i == 0) 
                        cost[i][j] = M[i][j] + max(cost[i][j + 1], cost[i + 1][j + 1]);
                    else if(i == n - 1)
                        cost[i][j] = M[i][j] + max(cost[i][j + 1], cost[i - 1][j + 1]);
                    else
                        cost[i][j] = M[i][j] + max(cost[i - 1][j + 1], max(cost[i][j + 1], cost[i + 1][j + 1]));
                }
                
                gold = max(gold, cost[i][j]);
            }
        }
        
        return gold;
    }
};
