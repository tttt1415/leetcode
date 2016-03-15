class Solution {
public:
    int minDistance(string word1, string word2) {
        // http://bangbingsyb.blogspot.com/2014/11/leetcode-edit-distance.html
        //DP[i+1][j+1] is the edit distance of word1[0:i] -> word2[0:j]
        //insert: word1[0:i] -> word2[0:j-1] inserts word2[j] - DP[i+1][j] + 1
        //delete: word1[0:i-1] -> word2[0:j] deletes word1[i] - DP[i][j+1] + 1
        //replace: word1[0:i-1] -> word2[0:j-1] check word1[i], word2[j] to see if DP[i][j] needs to +1
        //dp[i][j] is minimum of above values
        
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));  //can use two one dimentional array
        
        //the first row and first column is equal to its index since it is insertion
        for (int j = 1; j <= n; j++) {
            dp[0][j] = j;
        }
        
        for (int i = 1; i <= m; i++) {
            dp[i][0] = i;
            for (int j = 1; j <= n; j++) {
                dp[i][j] = (word1[i-1] == word2[j-1]) ? dp[i-1][j-1] : dp[i-1][j-1] + 1;
                dp[i][j] = min(dp[i][j], min(dp[i-1][j] + 1, dp[i][j-1] + 1));
            }
        }
        
        return dp[m][n];
    }
};