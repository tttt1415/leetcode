class Solution {
public:
    string longestPalindrome(string s) {
        //O(n^2)/ O(1)
        //http://articles.leetcode.com/longest-palindromic-substring-part-i
        //there is also a O(n) solution
        int length = s.size();
        if (length == 0) return "";
        string longest = s.substr(0, 1);
        
        for (int i = 0; i < length - 1; i++) {
            string s1 = stringGenCenter(s, i, i);
            if (s1.size() > longest.size()) {
                longest = s1;
            }
            
            string s2 = stringGenCenter(s, i, i+1);
            if (s2.size() > longest.size()) {
                longest = s2;
            }
        }
        
        return longest;
    }
    
    string stringGenCenter(string& s, int left, int right) {
        int length = s.size();
        
        while (left >= 0 && right <= length - 1) {
            if (s[left] == s[right]) {
                left--;
                right++;
            }
            else {
                break;
            }
        }
        
        return s.substr(left + 1, right - left - 1);
    }
};