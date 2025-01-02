class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0); // Initialize the dp array with size n+1 and all values as 0
        
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i / 2] + (i % 2); // Calculate the number of 1's for each i
        }
        
        return dp; // Return the result  
    }
};