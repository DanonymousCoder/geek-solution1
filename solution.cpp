
class Solution{
public:
    int nCr(int n, int r){
        // code here
        // User function Template for C++
        // Create a 2D vector to store the calculated values of nCr
        vector<vector<int>> dp(n + 1, vector<int>(r + 1, 0));

        // Calculate nCr using dynamic programming
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= min(i, r); j++) {
                // Base cases
                if (j == 0 || j == i) {
                    dp[i][j] = 1;
                } else {
                    // Apply the recursive formula: nCr = (n-1)C(r-1) + (n-1)Cr
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % (int)(1e9 + 7);
                }
            }
        }

        // Return the value of nCr modulo 10^9+7
        return dp[n][r];
    }
};