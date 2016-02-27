class Solution {
public:
    int numDecodings(string s) {
        //http://bangbingsyb.blogspot.com/2014/11/leetcode-decode-ways.html
        //similar to Climbing Stairs
        if (s.empty() || s[0] < '1') return 0;
		int fn = 0, fn_1 = 1, fn_2 = 1;
		
		for (int i = 1; i < s.size(); i++) {
			int v = (s[i-1] - '0') * 10 + (s[i] - '0');
			if (v > 9 && v <= 26) fn += fn_2;
			if (s[i] != '0') fn += fn_1;
			fn_2 = fn_1;
			fn_1 = fn;
			fn = 0;
		}
		
		return fn_1;
    }
};

