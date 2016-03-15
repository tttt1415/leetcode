class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        if (words.size() == 0) return result;
        int i = 0;
        
        while(i < words.size()) {
            int start = i;
            int sum = 0;
            
            while(i < words.size() && (sum + words[i].size()) <= maxWidth) {
                sum += words[i].size() + 1; //consider the space after each word
                i++;
            }
            
            int end = i - 1;
            int numIntervals = end - start;
            int avSpaces, leftSpaces;
            if (numIntervals > 0) {
                avSpaces = (maxWidth - sum + numIntervals + 1) / numIntervals;
                leftSpaces = (maxWidth - sum + numIntervals + 1) % numIntervals;
            }
            
            string current = "";
            for (int j = start; j < end; j++) {
                current += words[j];
                //consider the last line condition
                if (i == words.size()) {
                    current.append(1, ' ');
                }
                else {
                    current.append(avSpaces, ' ');
                    if (leftSpaces > 0) {
                        current.append(1, ' ');
                        leftSpaces--;
                    }
                }
            }
            
            current += words[end];
            //last line condition
            if (current.size() < maxWidth) {
                current.append(maxWidth - current.size(), ' ');
            }
            result.push_back(current);
        }
        
        return result;
    }
};