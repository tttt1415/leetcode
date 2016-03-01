class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        //http://bangbingsyb.blogspot.com/2014/11/leetcode-word-ladder-i-ii.html
        
        wordList.insert(endWord);
        //create queue for breath-first-search
        queue<pair<string, int>> q;
        q.push(make_pair(beginWord, 1));
        while (!q.empty()) {
            string current = q.front().first;
            int length = q.front().second;
            if (current == endWord) {
                return length;
            }
            q.pop();
            vector<string> neighbors = findNeighbors(current, wordList);
            for (int i = 0; i < neighbors.size(); i++) {
                q.push(make_pair(neighbors[i], length + 1));
            }
        }
        
        return 0;
    }
    
    vector<string> findNeighbors(string currentString, unordered_set<string>& wordList) {
        vector<string> result;
        for (int i = 0; i < currentString.size(); i++) {
            char currentChar = currentString[i];
            for (int j = 0; j < 26; j++) {
                if (j + 'a' != currentChar) {
                    currentString[i] = j + 'a';
                    if (wordList.count(currentString)) {
                        result.push_back(currentString);
                        //erase to avoid revert to searched string
                        wordList.erase(currentString);
                    }
                }
            }
            //remember to restore the string
            currentString[i] = currentChar;
        }
        
        return result;
    }
    
};