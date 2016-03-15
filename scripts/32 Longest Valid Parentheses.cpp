class Solution {
public:
    int longestValidParentheses(string s) {
        //https://leetcodenotes.wordpress.com/2013/10/19/leetcode-longest-valid-parentheses-%E8%BF%99%E7%A7%8D%E6%8B%AC%E5%8F%B7%E7%BB%84%E5%90%88%EF%BC%8C%E6%9C%80%E9%95%BF%E7%9A%84valid%E6%8B%AC%E5%8F%B7%E7%BB%84%E5%90%88%E6%9C%89%E5%A4%9A/
        //dp[i] is the longest valid parentheses at i
		//if s[i] is ')', dp[i] = 0 since it cannot be a valid parentheses
		//if s[i] is '(', we will try to see if we can find '(...)' where ... is a valid parentheses.
		//Therefore, we check if s[j] is ')' where j = i + 1 + dp[i+1], update dp[i]
		//Then we should also consider the case like '(...)(more valid...)' so update dp[i] again
        if (s.size() == 0) return 0;
        vector<int> dp(s.size(), 0);
        int maxLength = 0;
        
        //search it from end to start
        for (int i = s.size() - 2; i >= 0; i--) {
            if (s[i] == ')') {
                dp[i] = 0;
            }
            else {
                int j = i + 1 + dp[i+1];
                if (s[j] == ')') {
                    dp[i] = 2 + dp[i + 1];
                    if ((j + 1) < s.size()) {
                        dp[i] += dp[j + 1];
                    }
                }
            }
            maxLength = max(maxLength, dp[i]);
        }
        
        return maxLength;
    }
};