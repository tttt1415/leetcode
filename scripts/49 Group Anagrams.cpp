class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > result;
        map<string, int> hashMap;
        
        for (int i = 0; i < strs.size(); i++) {
            string current = strs[i];
            sort(current.begin(), current.end());
            
            if (hashMap.find(current) != hashMap.end()) {
                result[hashMap[current]-1].push_back(strs[i]);
            }
            else {
                vector<string> v;
                v.push_back(strs[i]);
                result.push_back(v);
                hashMap[current] = result.size();
            }
        }
        
        for (int i = 0; i < result.size(); i++) {
            sort(result[i].begin(), result[i].end());
        }
        
        return result;
    }
};