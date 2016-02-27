class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
		vector<string> result;
		string ip;
		
        partitionIP(s, 0, 0, ip, result);
		return result;
    }
	void partitionIP(string s, int startIndex, int partNum, string ip, vector<string>& result) {
		//max is 3 bit
		if (s.size() - startIndex > (4 - partNum) * 3) return;
		
		//min is 1 bit
		if (s.size() - startIndex < (4 - partNum)) return;
		
		if (s.size() == startIndex && partNum == 4) {
		    ip.resize(ip.size() - 1);
			result.push_back(ip);
			return;
		}
		
		int num = 0;
		for (int i = startIndex; i < startIndex + 3; i++) {
			num = num * 10 + s[i] - '0';
			if (num <= 255) {
				ip += s[i];
				partitionIP(s, i + 1, partNum + 1, ip + '.', result);
			}
			//need to handle starting from zero (0.1.0.010)
			if (num == 0) {
			    break;
			}
		}
		
	}
};