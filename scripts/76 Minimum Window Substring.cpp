class Solution {
public:
    string minWindow(string s, string t) {
        //http://articles.leetcode.com/finding-minimum-window-in-s-which/
        // 2*O(n) = O(n)
		int tSize = t.size();
		int sSize = s.size();
		if (tSize > sSize || tSize == 0 || sSize == 0) return "";
		
		int expectedCount[256] = {0};
		for (int i = 0; i < tSize; i++) {
			expectedCount[t[i]]++;
		}
		
		int appearCount[256] = {0};
		int minSize = INT_MAX;
		int matchCount = 0;
		int start = 0;
		int minStart;

		for (int i = 0; i < sSize; i++) {
		    //not in t
			if (expectedCount[s[i]] == 0) continue;
			
			appearCount[s[i]]++;
			if (appearCount[s[i]] <= expectedCount[s[i]]) {
				matchCount++;
			}
			
			if (matchCount == tSize) {
			    //make start to right as possible
				while (expectedCount[s[start]] == 0 || appearCount[s[start]] > expectedCount[s[start]]) {
					appearCount[s[start]]--;
					start++;
				}
				
				//current string size is (i - start + 1))
				if ((i - start + 1) < minSize) {
					minStart = start;
					minSize = i - start + 1;
				}
			}
		}
        
		return (minSize == INT_MAX) ? "" : s.substr(minStart, minSize);
    }
};