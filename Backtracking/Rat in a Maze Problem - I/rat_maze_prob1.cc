//Link to the question - https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
    vector<string> paths;
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        explore(m, n, "", 0, 0);
        return paths;
    }
    void explore(vector<vector<int>> &m, int n, string s, int i, int j) {
        if(i == n - 1 && j == n - 1 && m[i][j]) {
            paths.push_back(s);
            return;
        }
        
        if(isSafeIndex(n, i, j)) {
            if(m[i][j]) {
                m[i][j] = 0;
                explore(m, n, s + "D", i + 1, j); explore(m, n, s + "L", i, j - 1);
                explore(m, n, s + "R", i, j + 1); explore(m, n, s + "U", i - 1, j);
                m[i][j] = 1;
                return;
            }
            return;
        }
        return;
    }
    bool isSafeIndex(int n, int i, int j) {
        if(i == -1 || j == -1 || i == n || j == n)
            return false;
        return true;
    }
};
