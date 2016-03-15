class Solution {
public:
    vector<int> grayCode(int n) {
        //n = 0: 0
        //n = 1: 0, 1
        //n = 2: 0, 1, 3, 2
        //n = 3: 0, 1, 3, 2, 6, 7, 5, 4
        //the adding part is the previous result + 2^(n-1) in reverse order
        vector<int> result;
        result.push_back(0);
        
        for (int i = 0; i < n; i++) {
            int highest = 1<<i;
            int length = result.size();
            for (int j = length; j > 0; j--) {
                result.push_back(result[j-1] + highest);
            }
        }
        
        return result;
    }
};