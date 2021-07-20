/*
Link to the question - https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1#
*/

class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      
        unordered_set<int> s;
        unordered_set<int>::iterator it;
        
        int min_ele = arr[0];
        for(int i = 0; i < N; i++) {
            s.insert(arr[i]);
            min_ele = min(min_ele, arr[i]);
        }
        
        int length = 1, max_length = 0;
        
        while(!s.empty()) {
            s.erase(min_ele);
            if(s.find(min_ele + 1) != s.end()) {
                min_ele++;
                length++;
                max_length = max(max_length, length);
            }
            else {
                if(s.empty())
                    break;

                it = s.begin();
                int val = *it;
                while(s.find(val - 1) != s.end())
                    val--;
                    
                length = 1;
                min_ele = val;
            }
        }
        
        return max(max_length, length);
    }
};
