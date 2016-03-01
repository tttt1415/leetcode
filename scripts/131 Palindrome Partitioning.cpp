class Solution {
public:
    vector<vector<string>> partition(string s) {
        //for the questions that need to get all the output, use backtracking
        vector<vector<string>> result;
        vector<string> current;
        findPartition(s, 0, current, result);
        
        return result;
    }
    
    void findPartition(string& s, int start, vector<string>& current, vector<vector<string>>& result) {
        if (start == s.size()) {
            result.push_back(current);
            return;
        }
        
        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(s, start, i)) {
                current.push_back(s.substr(start, i - start + 1));
                findPartition(s, i + 1, current, result);
                current.pop_back();
            }
        }
    }
    
    bool isPalindrome(string& s, int start, int end) {
        while (end > start) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        
        return true;
    }
};