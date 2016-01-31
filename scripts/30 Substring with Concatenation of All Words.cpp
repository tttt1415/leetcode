class Solution {
public:
    //http://www.cnblogs.com/TenosDoIt/p/3807055.html
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.size() == 0) return result;
        int numWords = words.size();
        int wordLength = words[0].size();
        int totalLength = numWords*wordLength;
        if (s.size() < totalLength) return result;
        
        unordered_map<string, int> wordCount;
        for(int i = 0; i < numWords; i++) {
            wordCount[words[i]]++;
        }
        
		for (int i = 0; i < wordLength; i++) {
			unordered_map<string, int> wordFound;
			int winStart = i, count = 0;
			for (int winEnd = winStart; winEnd < s.size() - wordLength + 1; winEnd += wordLength) {
				string currentWord = s.substr(winEnd, wordLength);
				if (wordCount[currentWord]) {
					wordFound[currentWord]++;
					
					if (wordFound[currentWord] > wordCount[currentWord]) {
						//currentWord appears too many times
						//try to move the window after the previous currentWord location
						for (int k = winStart; k < winEnd; k += wordLength) {
							string tmpstr = s.substr(k, wordLength);
							wordFound[tmpstr]--;
							if (tmpstr == currentWord) {
								winStart = k + wordLength;
								break;
							}
							count--;
						}
                        
					}
					else {
						count ++;
					}
					
					if (count == numWords) {
						result.push_back(winStart);
					}
				}
				else {
					winStart = winEnd + wordLength;
					wordFound.clear();
					count = 0;
				}
			}
			
		}
        
        return result;
    }
};
